//ReportManager.h

#ifndef REPORTMANAGER_H
#define REPORTMANAGER_H

#include "RoadReport.h"
#include <vector>
using namespace std;

class ReportManager {
private:
    std::vector<RoadReport> reports;
    int nextReportID; 

public:
    ReportManager();
    int generateNewReportID();
    void addReport(RoadReport report);
    RoadReport* getReportByID(int reportID); 
    void getAllReports();
    void getTopSupportedReports();
    void filterBySeverity(Severity severity);
};

#endif
