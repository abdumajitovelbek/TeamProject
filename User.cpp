//user.cpp

#include "User.h"

User::User(string name, int id, string mail) : username(name), userID(id), email(mail) {}

string User::getUsername() {
    return username;
}

int User::getUserID() {
    return userID;
}
string User::getName() const {
    return name;
}

string User::getEmail() const {
    return email;
}

int User::getID() const {
    return id;
}
