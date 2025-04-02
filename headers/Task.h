#pragma once
#include <iostream>
#include <string.h>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>

class Task
{
protected:
    int task_no;
    std::string task_title;
    std::string task_description;
    std::chrono::system_clock::time_point due_date;
    bool isCompleted;
    int priority;

public:
    Task::Task(int id, const std::string &title, const std::string &description,
               const std::string &dueDate, bool isCompleted, int priority)
        : task_no(id), task_title(title), task_description(description),
          isCompleted(isCompleted), priority(priority) {
                this->setDueDate(dueDate);
          }

    virtual ~Task();

    int getId() const;
    std::string getTitle() const;
    std::string getDescription() const;
    std::string getDueDate() const;
    bool getStatus() const;
    int getPriority() const;

    void markComplete();
    void markIncomplete();
    void setTitle(const std::string &new_title);
    void setDescription(const std::string &new_description);
    void setDueDate(const std::string &dueDate);
    void setPriority(int new_priority);

    bool isOverdue() const;
    void display() const;
};

class WorkTask : public Task
{
private:
    std::string project_name;
    std::string project_decription;

public:
    WorkTask(int id, const std::string &title, const std::string &description,
             const std::string &dueDate, const std::string &projectName)
        : Task(id, title, description, dueDate, isCompleted, priority), project_name(projectName), project_decription(project_decription) {}

    void getProjectName() const;
    void getProjectDes() const;
    void setProjectName() const;
    void setProjectDes() const;
};