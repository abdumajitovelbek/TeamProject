//RegularUser.cpp

#include "RegularUser.h"
#include <iostream>
#include "Utils.h"


RegularUser::RegularUser(string name, int id, string email) : User(name, id, email) {}

void RegularUser::displayInfo() {
    cout << "Regular User: " << username << " (ID: " << userID << ", Email: " << email << ")" << endl;
}

RoadReport RegularUser::createReport(string location, string description, Severity severity) {
    return RoadReport(userID, location, description, severity, getCurrentDate());
}

void RegularUser::supportReport(int reportID) {
    cout << "User " << userID << " supported report ID " << reportID << endl;
}
