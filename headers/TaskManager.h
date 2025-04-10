#pragma once

#include "Task.h"
#include <vector>
#include <string>

class TaskManager {
private:
    std::vector<Task*> tasks;
public:
    TaskManager() = default;
    ~TaskManager() = default;


    void addTasks(Task* new_task);

    bool updateTasks(int id, std::string new_title, std::string new_description, std::string new_duedate, std::string new_isCompleted, int new_priority);

    void deleteTasks();

    void displayTasks() const;

    void sortOnPriority(); 


};