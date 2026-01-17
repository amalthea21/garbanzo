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
    void addTaskPool(std::vector<File> files);
    int getTotalFindings(Arguments arguments, const std::string& search);
    void clear();
    size_t getPoolCount() const;
};