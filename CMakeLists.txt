cmake_minimum_required(VERSION 3.16)

project(ClinicsAppointment VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt with Widgets and SQL modules
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    registration.cpp
    registration.h
    registration.ui
    databasemanager.cpp
    databasemanager.h
    dashboard.cpp
    dashboard.h
    dashboard.ui
    bookappointment.cpp
    bookappointment.h
    bookappointment.ui
    viewdoctors.cpp
    viewdoctors.h
    viewdoctors.ui
    myappointments.cpp
    myappointments.h
    myappointments.ui
    aboutus.cpp
    aboutus.h
    aboutus.ui
    billing.cpp
    billing.h
    billing.ui
    myprofile.cpp
    myprofile.h
    myprofile.ui
    slotavailabilityviewer.cpp
    slotavailabilityviewer.h
    slotavailabilityviewer.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ClinicsAppointment
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        dashboard.h dashboard.cpp dashboard.ui
        bookappointment.h bookappointment.cpp bookappointment.ui
        viewdoctors.h viewdoctors.cpp viewdoctors.ui
        myappointments.h myappointments.cpp myappointments.ui
        myprofile.h myprofile.cpp myprofile.ui
        billing.h billing.cpp billing.ui
        aboutus.h aboutus.cpp aboutus.ui
        slotavailabilityviewer.h slotavailabilityviewer.cpp slotavailabilityviewer.ui

    )
else()
    if(ANDROID)
        add_library(ClinicsAppointment SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(ClinicsAppointment
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Link against Qt Widgets and SQL
target_link_libraries(ClinicsAppointment PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Sql
)

if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.ClinicsAppointment)
endif()
set_target_properties(ClinicsAppointment PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS ClinicsAppointment
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ClinicsAppointment)
endif()
