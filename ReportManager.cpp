//ReportManager.cpp

#include "ReportManager.h"
#include "RoadReport.h"
#include <iostream>
#include <algorithm>

using namespace std;

ReportManager::ReportManager() {}

void ReportManager::addReport(RoadReport report) {
    reports.push_back(report);
    cout << "Report added by user ID " << report.getReporterID() << "." << endl;
}

void ReportManager::getAllReports() {
    cout << "Listing all reports...\n" << endl;
    for (const auto& report : reports) {
        report.displayReport();
        cout << "------------------*---" << endl;
    }
}

void ReportManager::getTopSupportedReports() {
    cout << "Top Supported Reports:\n" << endl;

    // Sort reports by support count (descending)
    vector<RoadReport> sortedReports = reports;
    sort(sortedReports.begin(), sortedReports.end(), [](const RoadReport& a, const RoadReport& b) {
        return a.getSupportCount() > b.getSupportCount();
    });

    int count = 0;
    for (const auto& report : sortedReports) {
        report.displayReport();
        cout << "---------------------" << endl;
        if (++count >= 3) break; // Show top 3
    }
}

void ReportManager::filterBySeverity(Severity severity) {
    cout << "Reports with severity level: " << severity << "\n" << endl;
    for (const auto& report : reports) {
        if (report.getSeverity() == severity) {
            report.displayReport();
            cout << "---------------------" << endl;
        }
    }
}
