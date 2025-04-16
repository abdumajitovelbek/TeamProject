//UserManager.h

#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"
#include <vector>
#include <memory>
using namespace std;

class UserManager {
private:
    vector<shared_ptr<User>> users;

public:
    void addUser(shared_ptr<User> user);
    shared_ptr<User> getUserByID(int id);
    shared_ptr<User> loginUser(const string& name, const string& email);
    int generateNewUserID();

};

#endif
