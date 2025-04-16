//RegularUser.cpp

#include "RegularUser.h"
#include <iostream>
#include "Utils.h"

RegularUser::RegularUser(string name, int id, string email) : User(name, id, email) {}

void RegularUser::displayInfo() {
    cout << "Regular User: " << username << " (ID: " << userID << ", Email: " << email << ")" << endl;
}

string RegularUser::getName() const {
    return getUsername();
}

string RegularUser::getEmail() const {
    return email;
}

int RegularUser::getID() const {
    return getUserID();
}

RoadReport RegularUser::createReport(string location, string description, Severity severity) {
    return RoadReport(0, userID, location, description, severity, getCurrentDate()); // reportID set in main.cpp
}

void RegularUser::supportReport(int reportID) {
    cout << "User " << userID << " supported report ID " << reportID << endl; // Optional, can be removed
}
