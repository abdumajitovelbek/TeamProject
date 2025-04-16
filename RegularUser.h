//RegularUser.h

#ifndef REGULARUSER_H
#define REGULARUSER_H

#include "User.h"
#include "RoadReport.h"

class RegularUser : public User {
public:
    virtual ~RegularUser() {}
    RegularUser(string name, int id, string email);
    void displayInfo() override;
    string getName() const override;   
    string getEmail() const override;  
    int getID() const override;        
    RoadReport createReport(string location, string description, Severity severity);
    void supportReport(int reportID);
};

#endif
