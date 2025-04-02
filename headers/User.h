#pragma once
#include <string>

class User {
private:
    std::string username;
    std::string password; 

public:
    User(const std::string &uname, const std::string &pass);
    
    std::string getUsername() const;
    bool authenticate(const std::string &inputPassword) const;
    
    std::string getPassword() const;
};


