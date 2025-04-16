//user.cpp

#include "User.h"

User::User(string name, int id, string mail) : username(name), userID(id), email(mail) {}

string User::getUsername() const {
    return username;
}

int User::getUserID() const {
    return userID;
}

string User::getName() const {
    return username;
}

string User::getEmail() const {
    return email;
}

int User::getID() const {
    return userID;
}
