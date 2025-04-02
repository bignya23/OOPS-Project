#pragma once

#include <string>
#include "../headers/Task.h"
#include "../headers/TaskManager.h"

class UI {
private:


public:
    static void getDisplayMenu();
    static int checkvalidchoice();
    static std::unique_ptr<Task> createTaskUI();
    static void updateTaskUI(TaskManager& taskManager);
};




