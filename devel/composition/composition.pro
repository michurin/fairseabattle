# Variables
TEMPLATE = app
QT += core gui
CONFIG += release warn_on qt debug
OBJECTS_DIR = ../../build
MOC_DIR = ../../build
TARGET = composition
DEPENDPATH += ../../src/logic ../../src/gui
INCLUDEPATH += ../../src/logic ../../src/gui

SOURCES += composition.cpp
HEADERS += composition.h
