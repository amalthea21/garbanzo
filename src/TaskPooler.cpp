#include "../include/TaskPooler.h"

void TaskPooler::addTaskPool(std::vector<File> files) {
    pooledTasks.push_back(files);
}

int TaskPooler::getTotalFindings(Arguments arguments, const std::string& search) {
    int totalAmount = 0;
    std::vector<std::thread> threads;

    auto processFileVector = [&](const std::vector<File>& files) {
        int localAmount = 0;

        for (const auto& file : files) {
            File& mutableFile = const_cast<File&>(file);
            localAmount += mutableFile.readFileContent(search, arguments);
            localAmount += mutableFile.readFileName(search, arguments);
        }

        std::lock_guard<std::mutex> lock(amountMutex);
        totalAmount += localAmount;
    };

    for (const auto& fileVector : pooledTasks) {
        threads.emplace_back(processFileVector, std::ref(fileVector));
    }

    for (auto& thread : threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }

    return totalAmount;
}

void TaskPooler::clear() {
    pooledTasks.clear();
}

size_t TaskPooler::getPoolCount() const {
    return pooledTasks.size();
}