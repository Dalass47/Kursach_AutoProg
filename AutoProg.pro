TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    interface.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    interface.h

