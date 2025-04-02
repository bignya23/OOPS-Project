#pragma once

#include "Task.h"
#include "TaskManager.h"
#include <fstream>
#include <vector>

class FileHandler {
public:
    static void saveTasksToFile(const std::vector<std::unique_ptr<Task>> &tasks, const std::string &filename);
    static void loadTasksFromFile(std::vector<std::unique_ptr<Task>> &tasks, const std::string &filename);
};
