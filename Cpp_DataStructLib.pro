TEMPLATE = app
CONFIG -= console c++11
CONFIG -= app_bundle
CONFIG -= qt

include(TestCase/TestCase.pri)
include(Pointer/Pointer.pri)
include(Exception/Exception.pri)
include(Object/Object.pri)
include(List/List.pri)
include(Array/Array.pri)

SOURCES += main.cpp
