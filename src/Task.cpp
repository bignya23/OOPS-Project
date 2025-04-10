#include "../headers/Task.h"

Task::~Task()
{
}

std::string Task::getTitle() const
{
    return task_title;
}

std::string Task::getDescription() const
{
    return task_description;
}

int Task::getId() const
{
    return this->task_no;
}
bool Task::getStatus() const
{
    return this->isCompleted;
}

int Task::getPriority() const
{
    return this->priority;
}

void Task::markComplete()
{
    this->isCompleted = true;
}

void Task::markIncomplete()
{
    this->isCompleted = false;
}

void Task::setTitle(const std::string &new_title)
{
    this->task_title = new_title;
}
void Task::setDescription(const std::string &new_description)
{
    this->task_description = new_description;
}

void Task::setPriority(int new_priority)
{
    this->priority = new_priority;
}

void Task::setDueDate(const std::string &dueDate)
{
    std::tm tm = {};
    std::istringstream ss(dueDate);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    due_date = std::chrono::system_clock::from_time_t(std::mktime(&tm));
}

std::string Task::getDueDate() const
{
    auto tt = std::chrono::system_clock::to_time_t(due_date);
    std::ostringstream oss;
    oss << std::put_time(std::localtime(&tt), "%Y-%m-%d");
    return oss.str();
}

std::string WorkTask::getProjectDescription() const {
    return project_description;
}

std::string WorkTask::getProjectTitle() const {
    return project_name;
}

void WorkTask::setProjectDescription(const std::string &project_description) {
    this->project_description = project_description;
}

void WorkTask::setProjectTitle(const std::string &project_title) {
    project_name = project_title;
}
bool Task::isOverdue() const
{
    return std::chrono::system_clock::now() > due_date;
}

void Task::display() const
{
    std::cout << "Task #" << task_no << " - " << task_title << "\n"
              << "Description: " << task_description << "\n"
              << "Due Date: " << getDueDate() << (isOverdue() ? " (Overdue!)" : "") << "\n"
              << "Status: " << (isCompleted ? "Completed" : "Pending") << "\n"
              << "Priority: " << priority << "\n\n";
}

void WorkTask::display() const
{
    std::cout << "Work Task : \n";
    Task::display();
    std::cout << "Project Title: " << project_name << "\n"
              << "Project Description: " << project_description << "\n\n";
}
