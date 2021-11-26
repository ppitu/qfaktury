cmake_minimum_required(VERSION 3.5)

project(qfaktury VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(Qt6 COMPONENTS Xml REQUIRED)
find_package(Qt6 COMPONENTS Core5Compat REQUIRED)
find_package(Qt6 COMPONENTS PrintSupport REQUIRED)
find_package(Qt6 COMPONENTS Network REQUIRED)

set(PROJECT_SOURCES
    src/main.cpp src/mainwindow.cpp src/mainwindow.h src/mainwindow.ui
    src/backup.cpp src/backup.h src/backup.ui src/bill.cpp src/bill.h
    src/buyerdata.cpp src/buyerdata.cpp src/buyers.cpp src/buyers.h
    src/buyers.ui src/buyerslist.cpp src/buyerslist.h src/buyerslist.ui
    src/changeamount.cpp src/changeamount.h src/changeamount.ui
    src/config.h src/const.h src/convertamount.cpp src/convertamount.h
    src/correctgross.cpp src/correctgross.h src/correction.cpp src/correction.cpp
    src/csvexport.cpp src/csvexport.h src/csvexport.ui src/custompaymdata.cpp src/custompaymdata.h
    src/custompayment.cpp src/custompayment.h src/custompaymentdialog.ui src/datewidgetitem.h
    src/deliverynote.cpp src/deliverynote.h src/detector.h src/documentdata.h src/duplicate.cpp src/duplicate.h
    src/goodsgrosslist.cpp src/goodsgrosslist.h src/goodsissuednotes.cpp
    src/goodsissuednotes.h src/goodslist.cpp src/goodslist.h src/goodslist.ui src/idatalayer.h src/invoice.cpp
    src/invoice.h src/invoice.ui src/invoicegross.cpp src/invoicegross.h src/invoicerr.cpp src/invoicerr.h src/messagehandler.h
    src/organizer.cpp src/organizer.h src/organizer.ui src/owncalendar.cpp src/owncalendar.h src/productdata.h
    src/runguard.cpp src/runguard.h src/saftfile.cpp src/saftfile.h src/saftfile.ui
    src/saftfileoutput.cpp src/saftfileoutput.h src/send.cpp src/send.h src/setting.cpp src/setting.h
    src/setting.ui src/user.cpp src/user.h src/user.ui src/validations.cpp src/validations.h src/warehouse.cpp
    src/warehouse.h src/warehousedata.h src/xmldatalayer.cpp src/xmldatalayer.h
    src/SimpleSmtp_SSL_QT5/smtp_attachements/emailwindow.cpp src/SimpleSmtp_SSL_QT5/smtp_attachements/emailwindow.h
    src/SimpleSmtp_SSL_QT5/smtp_attachements/emailwindow.ui src/SimpleSmtp_SSL_QT5/smtp_attachements/smtp.cpp
    src/SimpleSmtp_SSL_QT5/smtp_attachements/smtp.h
    src/Dialog/ProductDialog.cpp src/Dialog/ProductDialog.h src/Dialog/ProductDialog.ui
    src/TableView/ProductTableView.h src/TableView/ProductTableView.cpp src/TableView/ProductTableView.ui
  )

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(qfaktury
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        qfaktury.qrc
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET contractapp APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(qfaktury SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(qfaktury
            ${PROJECT_SOURCES}
        )
    endif()
endif()

include_directories("../qfaktury-core")

target_link_libraries(qfaktury PRIVATE qfaktury-core)
target_link_libraries(qfaktury PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(qfaktury PRIVATE Qt6::Xml)
target_link_libraries(qfaktury PRIVATE Qt6::Core5Compat)
target_link_libraries(qfaktury PRIVATE Qt6::PrintSupport)
target_link_libraries(qfaktury PRIVATE Qt6::Network)

set_target_properties(qfaktury PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(qfaktury)
endif()
