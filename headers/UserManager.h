#pragma once

#include "User.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

class UserManager {
private:
    std::vector<User> users;

public:
    void addUser(const std::string &username, const std::string &password);
    bool authenticateUser(const std::string &username, const std::string &password);
    
    void saveUsersToFile(const std::string &filename);
    void loadUsersFromFile(const std::string &filename);
};

