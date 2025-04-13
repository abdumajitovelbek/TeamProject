cmake_minimum_required(VERSION 3.29)
project(RoadDamageReportingSystem)

set(CMAKE_CXX_STANDARD 20)

add_executable(RoadDamageReportingSystem main.cpp
        User.h
        Admin.h
        RegularUser.h
        RoadReport.h
        ReportManager.h
        SupportList.h
        Severity.h
        User.cpp
        Admin.cpp
        RegularUser.cpp
        RoadReport.cpp
        ReportManager.cpp
        SupportList.cpp
        UserManager.cpp
        UserManager.h
        Utils.cpp
        Utils.h)
