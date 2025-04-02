#include "../headers/UserManager.h"

void UserManager::addUser(const std::string &username, const std::string &password) {
    users.emplace_back(username, password);
}

bool UserManager::authenticateUser(const std::string &username, const std::string &password) {
    for (const auto &user : users) {
        if (user.getUsername() == username && user.authenticate(password)) {
            return true;
        }
    }
    return false;
}

void UserManager::saveUsersToFile(const std::string &filename) {
    std::ofstream file(filename, std::ios::out);
    if (!file) {
        std::cerr << "Error opening file for writing!\n";
        return;
    }

    for (const auto &user : users) {
        file << user.getUsername() << "," << user.getPassword() << "\n";  
    }

    file.close();
}

void UserManager::loadUsersFromFile(const std::string &filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file for reading!\n";
        return;
    }

    users.clear();
    std::string line, uname, pass;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        if (std::getline(iss, uname, ',') && std::getline(iss, pass)) {
            users.emplace_back(uname, pass);
        }
    }

    file.close();
}
