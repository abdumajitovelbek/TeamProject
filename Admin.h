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
    string getName() const override;  
    string getEmail() const override; 
    int getID() const override;        
    void viewAllReports();
    void filterReportsBySeverity(Severity level);
    void viewTopReports();
};

#endif
