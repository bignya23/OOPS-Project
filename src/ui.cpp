#include <iostream>
#include "../headers/ui.h"

void UI::getDisplayMenu()
{
    std::cout << "\n----- Task Manager Menu -----\n";
    std::cout << "0. Show main menu\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. Update Task\n";
    std::cout << "3. Delete Task\n";
    std::cout << "4. Display Tasks\n";
    std::cout << "5. Exit\n";
    std::cout << "-----------------------------\n";
}
void UI::displayUserMenu()
{
    std::cout << "\n------- User Management System -------\n";
    std::cout << "1. Register User\n";
    std::cout << "2. Login User\n";
    std::cout << "3. Exit\n";
    std::cout << "-----------------------------\n";
}
int UI::checkvalidchoice()
{
    int choice;

    while (true)
    {
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a valid number.\n";
            continue;
        }
        if (choice < 0 || choice > 5)
        {
            std::cout << "Invalid Choice. Please select a correct choice from the menu !!!\n";
            continue;
        }
        else
        {
            break;
        }
    }

    return choice;
}

int UI::checkValidUserChoice() {

    int choice;

    while (true)
    {
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a valid number.\n";
            continue;
        }
        if (choice < 0 || choice > 3)
        {
            std::cout << "Invalid Choice. Please select a correct choice from the menu !!!\n";
            continue;
        }
        else
        {
            break;
        }
    }

    return choice;
}

 
void UI::updateTaskUI(std::vector<Task*>& tasks)
{
    int id;
    std::string input;

    std::cout << "Enter Task ID to update: ";
    std::cin >> id;
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input! Please enter a valid number.\n";
        updateTaskUI(tasks);
        return;
    }
    std::cin.ignore(); 

    Task* taskToUpdate = nullptr;
    for (auto &task : tasks)
    {
        if (task->getId() == id)
        {
            taskToUpdate = task;
            break;
        }
    }

    if (!taskToUpdate)
    {
        std::cout << "Task with ID " << id << " not found.\n";
        return;
    }

    std::string new_title, new_description, new_dueDate, new_isCompleted, new_priority;

    std::cout << "Enter new Title (leave empty to keep unchanged): ";
    std::getline(std::cin, new_title);

    std::cout << "Enter new Description (leave empty to keep unchanged): ";
    std::getline(std::cin, new_description);

    std::cout << "Enter new Due Date (leave empty to keep unchanged) (FORMAT - YEAR-MONTH-DAY): ";
    std::getline(std::cin, new_dueDate);

    std::cout << "Is the task completed? (1 for Yes, 0 for No) (leave empty to keep unchanged): ";
    std::getline(std::cin, new_isCompleted);

    std::cout << "Enter new Priority (1 = HIGH, 2 = MEDIUM, 3 = LOW) (leave empty to keep unchanged): ";
    std::getline(std::cin, new_priority);

    if (!new_title.empty())
    {
        taskToUpdate->setTitle(new_title);
    }
    if (!new_description.empty())
    {
        taskToUpdate->setDescription(new_description);
    }
    if (!new_dueDate.empty())
    {
        taskToUpdate->setDueDate(new_dueDate);
    }
    if (!new_isCompleted.empty())
    {
        int completed = std::stoi(new_isCompleted);
        if (completed == 1)
            taskToUpdate->markComplete();
        else if (completed == 0)
            taskToUpdate->markIncomplete();
    }
    if (!new_priority.empty())
    {
        int prio = std::stoi(new_priority);
        taskToUpdate->setPriority(prio);
    }

    if (WorkTask* workTask = dynamic_cast<WorkTask*>(taskToUpdate))
    {
        std::string new_project_title, new_project_description;
        std::cout << "Enter new Project Title (leave empty to keep unchanged): ";
        std::getline(std::cin, new_project_title);

        std::cout << "Enter new Project Description (leave empty to keep unchanged): ";
        std::getline(std::cin, new_project_description);

        if (!new_project_title.empty())
        {
            workTask->setProjectTitle(new_project_title);
        }
        if (!new_project_description.empty())
        {
            workTask->setProjectDescription(new_project_description);
        }
    }

    std::cout << "Task updated successfully!\n";
}



Task* UI::createTaskUI()
{
    int id, priority = 3;
    std::string title, description, dueDate, projectName;

    std::cout << "Enter Task ID: ";
    std::cin >> id;
    std::cin.ignore();

    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input! Please enter a valid number.\n";
        UI::createTaskUI();
    }

    std::cout << "Enter Title: ";
    std::getline(std::cin, title);

    std::cout << "Enter Description: ";
    std::getline(std::cin, description);

    std::cout << "Enter Due Date (FORMAT - YEAR-MONTH-DAY) : ";
    std::getline(std::cin, dueDate);

    while (true)
    {
        std::cout << "Enter priority (1 = HIGH, 2 = MEDIUM, 3 = LOW): ";
        std::cin >> priority;
        std::cin.ignore();

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a valid number between 1 and 3.\n";
            continue;
        }
        if (priority < 1 || priority > 3)
        {
            std::cout << "Invalid input! Please enter a valid number between 1 and 3.\n";
            continue;
        }
        break;
    }
    return new Task(id, title, description, dueDate, false, priority);
}

WorkTask* UI::createWorkTaskUI() {
    int id, priority = 3;
    std::string title, description, dueDate, projectName, projectDescription;

    std::cout << "Enter Task ID: ";
    std::cin >> id;
    std::cin.ignore();

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input! Please enter a valid number.\n";
        return UI::createWorkTaskUI();
    }

    std::cout << "Enter Title: ";
    std::getline(std::cin, title);

    std::cout << "Enter Description: ";
    std::getline(std::cin, description);

    std::cout << "Enter Due Date (FORMAT - YEAR-MONTH-DAY): ";
    std::getline(std::cin, dueDate);

    while (true) {
        std::cout << "Enter priority (1 = HIGH, 2 = MEDIUM, 3 = LOW): ";
        std::cin >> priority;
        std::cin.ignore();

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a valid number between 1 and 3.\n";
            continue;
        }
        if (priority < 1 || priority > 3) {
            std::cout << "Invalid input! Please enter a valid number between 1 and 3.\n";
            continue;
        }
        break;
    }

    std::cout << "Enter Project Name: ";
    std::getline(std::cin, projectName);

    std::cout << "Enter Project Description: ";
    std::getline(std::cin, projectDescription);

    return new WorkTask(id, title, description, dueDate, false, priority, projectName, projectDescription);
}