TEMPLATE = app
CONFIG -= console c++11
CONFIG -= app_bundle
CONFIG -= qt

include(TestCase/TestCase.pri)
include(SmartPointer/SmartPointer.pri)
include(Exception/Exception.pri)
include(Object/Object.pri)
include(List/List.pri)

SOURCES += main.cpp
