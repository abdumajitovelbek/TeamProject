#include "UserManager.h"

void UserManager::addUser(shared_ptr<User> user) {
    users.push_back(user);
}

shared_ptr<User> UserManager::getUserByID(int id) {
    for (const auto& user : users) {
        if (user->getID() == id)
            return user;
    }
    return nullptr;
}
shared_ptr<User> UserManager::loginUser(const string& name, const string& email) {
    for (const auto& user : users) {
        if (user->getName() == name && user->getEmail() == email) {
            return user;
        }
    }
    return nullptr;
}

int UserManager::generateNewUserID() {
    int maxID = 0;
    for (const auto& user : users) {
        if (user->getID() > maxID) {
            maxID = user->getID();
        }
    }
    return maxID + 1;
}