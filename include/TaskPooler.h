#pragma once

#include <mutex>
#include <vector>
#include "File.h"
#include "Arguments.h"

class TaskPooler {
public:
    std::vector<File> tasks;
    std::vector<std::vector<File>> pooledTasks;
    std::mutex amountMutex;

    int findThreadAmount(std::vector<File> tasks);
    std::vector<std::vector<File>> poolTasks(const std::vector<File>& tasks, int amount);
    int getTotalFindings(Arguments arguments, const std::string& search);
};