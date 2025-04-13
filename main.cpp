// main.cpp – Road Damage Reporting System with Login

#include <iostream>
#include <memory>
#include "RegularUser.h"
#include "Admin.h"
#include "ReportManager.h"
#include "UserManager.h"
#include "Utils.h"

using namespace std;

void menu() {
    cout << "\n--- Road Damage Reporting System ---" << endl;
    cout << "1. Create Report" << endl;
    cout << "2. Support a Report" << endl;
    cout << "3. View All Reports (Admin Only)" << endl;
    cout << "4. View Top Supported Reports (Admin Only)" << endl;
    cout << "5. Filter Reports by Severity (Admin Only)" << endl;
    cout << "0. Exit" << endl;
    cout << "Choose an option: ";
}

int main() {
    ReportManager manager;
    UserManager userManager;

    // Pre-register one admin
    auto adminUser = make_shared<Admin>("Admin", 999, "admin@example.com", &manager);
    userManager.addUser(adminUser);

    // Login
    string name, email;
    cout << "Login\nEnter name: ";
    getline(cin, name);
    cout << "Enter email: ";
    getline(cin, email);

    shared_ptr<User> currentUser = userManager.loginUser(name, email);

    if (!currentUser) {
        int newID = userManager.generateNewUserID();
        cout << "New user created with ID: " << newID << endl;
        currentUser = make_shared<RegularUser>(name, newID, email);
        userManager.addUser(currentUser);
    }

    bool isAdmin = dynamic_pointer_cast<Admin>(currentUser) != nullptr;
    bool running = true;

    while (running) {
        menu();
        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                string location, description;
                int severityInt;
                cout << "\nEnter location: ";
                getline(cin, location);
                cout << "Enter description: ";
                getline(cin, description);
                cout << "Enter severity (0 = BAD, 1 = VERY_BAD, 2 = EXTREMELY_BAD): ";
                cin >> severityInt;
                cin.ignore();

                if (severityInt < 0 || severityInt > 2) {
                    cout << "Invalid severity level.\n";
                    break;
                }

                Severity severity = static_cast<Severity>(severityInt);
                auto regUser = dynamic_pointer_cast<RegularUser>(currentUser);
                if (regUser) {
                    RoadReport report = regUser->createReport(location, description, severity);
                    manager.addReport(report);
                } else {
                    cout << "Only regular users can create reports.\n";
                }
                break;
            }
            case 2: {
                int reportID;
                cout << "\nEnter Report ID to support: ";
                cin >> reportID;
                cin.ignore();

                auto regUser = dynamic_pointer_cast<RegularUser>(currentUser);
                if (regUser) {
                    regUser->supportReport(reportID); // You may want to link this to manager in future
                } else {
                    cout << "Only regular users can support reports.\n";
                }
                break;
            }
            case 3:
                if (isAdmin) dynamic_pointer_cast<Admin>(currentUser)->viewAllReports();
                else cout << "Access denied. Admin only.\n";
                break;
            case 4:
                if (isAdmin) dynamic_pointer_cast<Admin>(currentUser)->viewTopReports();
                else cout << "Access denied. Admin only.\n";
                break;
            case 5: {
                if (isAdmin) {
                    int severityInt;
                    cout << "\nEnter severity to filter by (0 = BAD, 1 = VERY_BAD, 2 = EXTREMELY_BAD): ";
                    cin >> severityInt;
                    cin.ignore();

                    if (severityInt < 0 || severityInt > 2) {
                        cout << "Invalid severity level.\n";
                        break;
                    }
                    dynamic_pointer_cast<Admin>(currentUser)->filterReportsBySeverity(static_cast<Severity>(severityInt));
                } else {
                    cout << "Access denied. Admin only.\n";
                }
                break;
            }
            case 0:
                running = false;
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option.\n";
        }
    }

    return 0;
}