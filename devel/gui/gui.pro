# Variables
TEMPLATE = app
QT += core gui
CONFIG += release warn_on qt debug
OBJECTS_DIR = ../../build
MOC_DIR = ../../build
TARGET = gui
DEPENDPATH += ../../src/logic ../../src/gui
INCLUDEPATH += ../../src/logic ../../src/gui

SOURCES += gui.cpp
HEADERS += gui.h

# Input
HEADERS += ../../src/gui/arenawidget.h
HEADERS += ../../src/gui/flags_colors.h
HEADERS += ../../src/logic/geometry.h
HEADERS += ../../src/logic/map.h
HEADERS += ../../src/logic/flags.h

SOURCES += ../../src/gui/arenawidget.cpp
SOURCES += ../../src/gui/flags_colors.cpp
SOURCES += ../../src/logic/geometry.cpp
SOURCES += ../../src/logic/map.cpp
SOURCES += ../../src/logic/flags.cpp
