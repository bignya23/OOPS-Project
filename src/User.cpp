#include "../headers/User.h"

User::User(const std::string &uname, const std::string &pass)
    : username(uname), password(pass) {}

std::string User::getUsername() const {
    return username;
}

bool User::authenticate(const std::string &inputPassword) const {
    return password == inputPassword;
}

std::string User::getPassword() const {
    return password;
}
