//RoadReport.cpp

#include "RoadReport.h"
#include <iostream>

RoadReport::RoadReport(int reportID, int reporterID, string loc, string desc, Severity sev, string date)
    : reportID(reportID), location(loc), description(desc), severity(sev), dateReported(date),
      status("Pending"), supportCount(0), reporterID(reporterID) {}

void RoadReport::addSupport(int userID) {
    if (!supporterIDs.contains(userID)) {
        supporterIDs.add(userID);
        supportCount++;
        cout << "User " << userID << " supported report ID " << reportID << ". Total supports: " << supportCount << endl;
    } else {
        cout << "User " << userID << " has already supported this report.\n";
    }
}

string severityToString(Severity sev) {
    switch (sev) {
        case BAD: return "Bad";
        case VERY_BAD: return "Very Bad";
        case EXTREMELY_BAD: return "Extremely Bad";
        default: return "Unknown";
    }
}

void RoadReport::displayReport() const {
    cout << "Report ID: " << reportID << "\nLocation: " << location << "\nDescription: " << description
         << "\nSeverity: " << severityToString(severity) << "\nDate: " << dateReported
         << "\nStatus: " << status << "\nSupports: " << supportCount << endl;
}
