// NotificationManager.h
#pragma once
#include <vector>
#include <chrono>
#include <thread>
#include <iostream>
#include "Task.h"

class NotificationManager {
public:
  
    static void startNotifications(const std::vector<Task*>& tasks) {
        std::thread([&tasks]() {
            while (true) {
                auto now = std::chrono::system_clock::now();
                for (auto* task : tasks) {
                    if (!task->getStatus()) {
                        std::cout << "\n[Notification] Task \"" << task->getTitle()
                                      << "\" pending with due date " << task->getDueDate() << "\n";
                    }
                }
                std::this_thread::sleep_for(std::chrono::seconds(30));
            }
        }).detach();
    }
};
