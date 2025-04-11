#include "../headers/TaskManager.h"
#include "../headers/Task.h"
#include <algorithm>
void TaskManager::addTasks(Task* new_task)
{
    tasks.push_back(new_task);
}

bool TaskManager::updateTasks(int id, std::string new_title, std::string new_description, std::string new_duedate, std::string new_isCompleted, int new_priority)
{
    for (auto &task : tasks)
    {
        if (task->getId() == id)
        {
            std::cout << "Task ID is : " << id << std::endl;
            if (new_title != "")
            {
                task->setTitle(new_title);
            }
            if (new_description != "")
            {
                task->setDescription(new_description);
            }
            if (new_duedate != "")
            {
                task->setDueDate(new_duedate);
            }
            if (new_isCompleted != "")
            {
                if (new_isCompleted == "1")
                {
                    task->markComplete();
                }
                else
                {
                    task->markIncomplete();
                }
            }
            if(new_priority <= 3 && new_priority >= 1) {
                task->setPriority(new_priority);
            }
            return true;
        }
    }
    return false;
}

void TaskManager::displayTasks(std::vector<Task*> &tasks)
{   
    
    if (tasks.empty())
    {
        std::cout << "No tasks available.\n";
        return;
    }

    std::cout << "------- Task List -------\n";
    for (const auto &task : tasks)
    {
        task->display();
        std::cout << "-------------------------\n";
    }
}

void TaskManager::deleteTasks(std::vector<Task*> &tasks)
{
    if (tasks.empty())
    {
        std::cout << "No task to delete\n";
        return;
    }

    displayTasks(tasks);
    int id;
    std::cout << "Enter the id of the task to delete : ";
    std::cin >> id;
    std::cin.ignore();

    std::vector<Task*> new_tasks;

    for(auto& task : tasks) {
        if(task->getId() != id) {
            new_tasks.push_back(task);
        }
    }
    tasks = new_tasks;

    std::cout << "Task Deleted Successfully !!!\n";
}


void TaskManager::sortOnPriority(std::vector<Task*> &tasks) {
    sort(tasks.begin(), tasks.end(), [&](Task* first, Task* second) {
        return first->getPriority() < second->getPriority();
    });
}


std::vector<Task*>& TaskManager::getTasks() {
    return tasks;
}
