#pragma once

#include "Task.h"
#include "TaskManager.h"
#include <fstream>
#include <vector>

class FileHandler {
public:
    static void saveTasksToFile(const std::vector<Task*> &tasks, const std::string &filename);
    static void loadTasksFromFile(std::vector<Task*> &tasks, const std::string &filename);
    static void saveTasksToFileOverwrite(const std::vector<Task*> &tasks, const std::string &filename);
};
