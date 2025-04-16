//User.h

#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
protected:
    string username;
    int userID;
    string email;

public:
    User(string name, int id, string email);
    string getUsername() const;  
    int getUserID() const;   
    virtual void displayInfo() = 0;
    virtual string getName() const = 0;
    virtual string getEmail() const = 0;
    virtual int getID() const = 0;
    string getEmail() { return email; } 
    virtual ~User() {}
};

#endif
