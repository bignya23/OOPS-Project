#pragma once

#include <string>
#include "../headers/Task.h"
#include "../headers/TaskManager.h"

class UI {

public:
    static void getDisplayMenu();
    static int checkvalidchoice();
    static Task* createTaskUI();
    static WorkTask* createWorkTaskUI();
    static void updateTaskUI(std::vector<Task*> &tasks);
    static void displayUserMenu();
    static int checkValidUserChoice();
};




