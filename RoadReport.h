//RoadReport.h

#ifndef ROADREPORT_H
#define ROADREPORT_H

#include <string>
#include "Severity.h"
#include "SupportList.h"

using namespace std;

class RoadReport {
private:
    int reportID;
    string location;
    string description;
    Severity severity;
    string dateReported;
    string status;
    int supportCount;
    int reporterID;
    SupportList<int> supporterIDs;

public:
    RoadReport(int reportID, int reporterID, string location, string description, Severity severity, string date);
    void addSupport(int userID);
    void displayReport() const;
    int getSupportCount() const { return supportCount; }
    int getReporterID() const { return reporterID; }
    int getReportID() const { return reportID; } 
    Severity getSeverity() const { return severity; }
    ~RoadReport() {}
};

#endif
