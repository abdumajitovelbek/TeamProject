//Admin.cpp
#include "Admin.h"
#include <iostream>

Admin::Admin(string name, int id, string email, ReportManager* mgr) : User(name, id, email), manager(mgr) {}

void Admin::displayInfo() {
    cout << "Admin: " << username << " (ID: " << userID << ", Email: " << email << ")" << endl;
}

void Admin::viewAllReports() {
    manager->getAllReports();
}

void Admin::filterReportsBySeverity(Severity level) {
    manager->filterBySeverity(level);
}

void Admin::viewTopReports() {
    manager->getTopSupportedReports();
}