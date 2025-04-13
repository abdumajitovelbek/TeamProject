//Admin.h

#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "RoadReport.h"
#include "ReportManager.h"

class Admin : public User {
    ReportManager* manager;
public:
    Admin(string name, int id, string email, ReportManager* mgr);
    virtual ~Admin() {}
    void displayInfo() override;
    void viewAllReports();
    void filterReportsBySeverity(Severity level);
    void viewTopReports();
};

#endif
