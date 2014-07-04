#-------------------------------------------------
#
# Project created by QtCreator 2014-06-26T18:41:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Proj1
TEMPLATE = app


SOURCES += main.cpp\
        mainui.cpp \
    setting/setting.cpp \
    setting/advanced.cpp \
    setting/excludedfiletype.cpp \
    setting/realtimproui.cpp \
    scan/scan.cpp \
    state/state.cpp \
    scan/scanini.cpp

HEADERS  += mainui.h \
    setting/setting.h \
    setting/advanced.h \
    setting/excludedfiletype.h \
    setting/realtimproui.h \
    scan/scan.h \
    state/state.h \
    scan/scanini.h

FORMS    += mainui.ui \
    setting/setting.ui \
    setting/excludedfiletype.ui \
    setting/realtimproui.ui \
    scan/scan.ui \
    state/state.ui \
    scan/scanini.ui \
    setting/advanced.ui

RESOURCES += \
    img.qrc
