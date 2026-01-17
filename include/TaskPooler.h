#pragma once

#include <vector>
#include <thread>
#include <mutex>
#include <string>
#include "Arguments.h"
#include "File.h"

class TaskPooler {
private:
    std::vector<std::vector<File>> pooledTasks;
    std::mutex amountMutex;

public:
    // Add files to the task pool
    void addTaskPool(std::vector<File> files);

    // Get total findings across all pooled tasks using threads
    int getTotalFindings(Arguments arguments, const std::string& search);

    // Clear all pooled tasks
    void clear();

    // Get the number of task pools
    size_t getPoolCount() const;
};