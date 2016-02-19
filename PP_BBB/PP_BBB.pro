QT += core sql serialport
QT -= gui

TARGET = PP_BBB
    target.files = PP_BBB
    target.path = /home/szymon/PP/PP_BBB
INSTALLS += target
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

SOURCES += main.cpp \
    program.cpp


QTPLUGIN += qsqlmysql

HEADERS += \
    program.h

QMAKE_CXXFLAGS += -pthread
QMAKE_CFLAGS += -pthread
LIBS += -pthread
