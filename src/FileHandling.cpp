#include "../headers/FileHandling.h"  
#include "Task.h"      
#include <fstream>
#include <sstream>
#include <stdexcept>

void FileHandler::saveTasksToFile(const std::vector<Task*> &tasks, const std::string &filename) {
    std::ofstream outFile(filename, std::ios::app);
    if (!outFile) {
        throw std::runtime_error("Could not open file for writing: " + filename);
    }
    
    for (const auto &task : tasks) {
        if (auto workTask = dynamic_cast<WorkTask*>(task)) {
            outFile << "WorkTask" << "\n";
            outFile << workTask->getId() << "\n";
            outFile << workTask->getTitle() << "\n";
            outFile << workTask->getDescription() << "\n";
            outFile << workTask->getDueDate() << "\n";
            outFile << workTask->getStatus() << "\n"; 
            outFile << workTask->getPriority() << "\n";
            outFile << workTask->getProjectTitle() << "\n";
            outFile << workTask->getProjectDescription() << "\n";
        } else {
            outFile << "Task" << "\n";
            outFile << task->getId() << "\n";
            outFile << task->getTitle() << "\n";
            outFile << task->getDescription() << "\n";
            outFile << task->getDueDate() << "\n";
            outFile << task->getStatus() << "\n";  
            outFile << task->getPriority() << "\n";
        }
    }
    outFile.close();
}


void FileHandler::loadTasksFromFile(std::vector<Task*> &tasks, const std::string &filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        throw std::runtime_error("Could not open file for reading: " + filename);
    }
    
    std::string line;
    while (std::getline(inFile, line)) {
        if (line == "Task") {
            std::string idStr, title, description, dueDate, isCompletedStr, priorityStr;
            if (!std::getline(inFile, idStr) ||
                !std::getline(inFile, title) ||
                !std::getline(inFile, description) ||
                !std::getline(inFile, dueDate) ||
                !std::getline(inFile, isCompletedStr) ||
                !std::getline(inFile, priorityStr)) {
                break; 
            }
            int id = std::stoi(idStr);
            bool isCompleted = (std::stoi(isCompletedStr) != 0);
            int priority = std::stoi(priorityStr);
            
            Task* newTask = new Task(id, title, description, dueDate, isCompleted, priority);
            tasks.push_back(newTask);
            
        }
        else if (line == "WorkTask") {
            std::string idStr, title, description, dueDate, isCompletedStr, priorityStr;
            std::string projectTitle, projectDescription;
            if (!std::getline(inFile, idStr) ||
                !std::getline(inFile, title) ||
                !std::getline(inFile, description) ||
                !std::getline(inFile, dueDate) ||
                !std::getline(inFile, isCompletedStr) ||
                !std::getline(inFile, priorityStr) ||
                !std::getline(inFile, projectTitle) ||
                !std::getline(inFile, projectDescription)) {
                break;
            }
            int id = std::stoi(idStr);
            bool isCompleted = (std::stoi(isCompletedStr) != 0);
            int priority = std::stoi(priorityStr);
            
            Task* newTask = new WorkTask(id, title, description, dueDate, isCompleted, priority, projectTitle, projectDescription);
            tasks.push_back(newTask);
        }
        
    }
    
    inFile.close();
}
