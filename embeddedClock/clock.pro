QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
QT += network

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    alarmclockdialog.cpp \
    alarmthread.cpp \
    dhtthread.cpp \
    main.cpp \
    mainwindow.cpp \
    refreshcalendarwidget.cpp \
    ringdialog.cpp \
    timesetdialog.cpp \
    timeshowthread.cpp \
    timethread.cpp

HEADERS += \
    alarmclockdialog.h \
    alarmthread.h \
    dhtthread.h \
    mainwindow.h \
    refreshcalendarwidget.h \
    ringdialog.h \
    timesetdialog.h \
    timeshowthread.h \
    timethread.h

FORMS += \
    alarmclockdialog.ui \
    mainwindow.ui \
    ringdialog.ui \
    timesetdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
