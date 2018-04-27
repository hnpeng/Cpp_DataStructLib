TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

include(TestCase/TestCase.pri)
include(SmartPointer/SmartPointer.pri)

SOURCES += main.cpp
