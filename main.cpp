#include <iostream>
#include "headers/ui.h"
#include "headers/Task.h"
#include "headers/TaskManager.h"
#include "headers/UserManager.h"

int main()
{
    UserManager userManager;
    userManager.loadUsersFromFile("../files/users.txt");

    std::string username, password;
    bool login = false;
    while (true)
    {
        UI::displayUserMenu();
        int choice = UI::checkValidUserChoice();

        switch (choice)
        {
        case 1:
            std::cout << "Enter username: ";
            std::cin >> username;
            std::cout << "Enter password: ";
            std::cin >> password;

            userManager.addUser(username, password);
            userManager.saveUsersToFile("../files/users.txt");
            std::cout << "User registered successfully!\n";

            break;
        case 2:
            std::cout << "Enter username: ";
            std::cin >> username;
            std::cout << "Enter password: ";
            std::cin >> password;

            if (userManager.authenticateUser(username, password))
            {
                std::cout << "Login successful!\n\n";
                std::cout << "___________Welcome " << username;
                login = true;
            }
            else
            {
                std::cout << "Invalid username or password!\n";
            }

            break;

        case 3:
            std::cout << "Exiting program...\n";
            return 0;

        default:
            std::cout << "Invalid choice! Try again.\n";
        }

        if (login == true)
        {
            break;
        }
    }

    TaskManager *taskManager = new TaskManager();
    bool start = true;
    std::cout << " To Advanced Task Manager___________\n\n";
    UI::getDisplayMenu();
    int taskType;

    while (true)
    {
        if (start)
        {
            int choice = UI::checkvalidchoice();
            std::cout << "You have Selected Choice : " << choice << std::endl;
            std::unique_ptr<Task> new_task;
            switch (choice)
            {
            case 0:
                UI::getDisplayMenu();
                break;
            case 1:
                std::cout << "Select Task Type:\n";
                std::cout << "1. Standard Task\n";
                std::cout << "2. Work Task\n";
                std::cout << "Enter your choice: ";
                std::cin >> taskType;
                std::cin.ignore(); 

                Task* newTask;
                
                if (taskType == 1) {
                    newTask = UI::createTaskUI();
                } 
                else if (taskType == 2) {
                    newTask = UI::createWorkTaskUI();
                }
                else
                {
                    std::cout << "Invalid task type selected.\n";
                    break;
                }
                taskManager->addTasks(newTask);
                std::cout << "------------------------" << std::endl;
                std::cout << "Task Added Successfully!" << std::endl;
                break;
            case 2:
                UI::updateTaskUI(*taskManager);
                break;
            case 3:
                taskManager->deleteTasks();
                break;
            case 4:
                taskManager->displayTasks();
                break;
            case 5:
                start = false;
                std::cout << "Exiting Advanced Task Manager\n";
                break;
            default:
                break;
            }
        }
        else
        {
            break;
        }
    }

    return 0;
}