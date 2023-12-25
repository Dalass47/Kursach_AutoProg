TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    interface.cpp \
    client.cpp \
    clientinterface.cpp \
    clientlist.cpp \
    payment.cpp \
    paymentinterface.cpp \
    paymentlist.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    interface.h \
    client.h \
    clientinterface.h \
    clientlist.h \
    payment.h \
    paymentinterface.h \
    paymentlist.h

