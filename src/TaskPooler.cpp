#include "../include/TaskPooler.h"

#include <thread>

using namespace std;

int TaskPooler::findThreadAmount(std::vector<File> tasks) {
    unsigned int hw_threads = thread::hardware_concurrency();

    if (hw_threads == 0) {
        hw_threads = 4;
    }

    unsigned int optimal_threads = hw_threads * 2;

    unsigned int task_count = tasks.size();
    if (task_count < optimal_threads) {
        return task_count;
    }

    const unsigned int MAX_THREADS = 32;
    return min(optimal_threads, MAX_THREADS);
}

vector<vector<File>> TaskPooler::poolTasks(const vector<File>& tasks, int amount) {
    vector<vector<File>> pooledTasks;

    if (tasks.empty() || amount <= 0) {
        return pooledTasks;
    }

    int actual_pools = std::min(amount, static_cast<int>(tasks.size()));
    pooledTasks.resize(actual_pools);

    size_t chunk_size = tasks.size() / actual_pools;
    size_t remainder = tasks.size() % actual_pools;

    size_t start = 0;
    for (int i = 0; i < actual_pools; i++) {
        size_t current_chunk_size = chunk_size + (i < remainder ? 1 : 0);

        pooledTasks[i].assign(
            tasks.begin() + start,
            tasks.begin() + start + current_chunk_size
        );

        start += current_chunk_size;
    }

    return pooledTasks;
}

int TaskPooler::getTotalFindings(Arguments arguments, const string& search) {
    int totalAmount = 0;
    vector<thread> threads;

    auto processFileVector = [&](const vector<File>& files) {
        int localAmount = 0;

        for (const auto& file : files) {
            File& mutableFile = const_cast<File&>(file);
            localAmount += mutableFile.readFileContent(search, arguments);
            localAmount += mutableFile.readFileName(search, arguments);
        }

        lock_guard<mutex> lock(amountMutex);
        totalAmount += localAmount;
    };

    for (const auto& fileVector : pooledTasks) {
        threads.emplace_back(processFileVector, ref(fileVector));
    }

    for (auto& thread : threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }

    return totalAmount;
}