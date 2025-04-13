//ReportManager.h

#ifndef REPORTMANAGER_H
#define REPORTMANAGER_H

#include "RoadReport.h"
#include <vector>
using namespace std;

class ReportManager {
private:
    std::vector<RoadReport> reports;

public:
    ReportManager();
    void addReport(RoadReport report);
    void getAllReports();
    void getTopSupportedReports();
    void filterBySeverity(Severity severity);

};

#endif
