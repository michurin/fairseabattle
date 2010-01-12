# Variables
TEMPLATE = app
QT -= core
QT -= gui
#CONFIG += release warn_on qt debug
OBJECTS_DIR = ../../build
MOC_DIR = ../../build
TARGET = logic
DEPENDPATH += ../../src/logic
INCLUDEPATH += ../../src/logic

SOURCES += logic.cpp

# Input
SOURCES += ../../src/logic/arena.cpp
SOURCES += ../../src/logic/arena_io.cpp
SOURCES += ../../src/logic/flags.cpp
SOURCES += ../../src/logic/flags_io.cpp
SOURCES += ../../src/logic/geometry.cpp
SOURCES += ../../src/logic/legend.cpp
SOURCES += ../../src/logic/legend_io.cpp
SOURCES += ../../src/logic/map.cpp
SOURCES += ../../src/logic/map_io.cpp

HEADERS += ../../src/logic/arena.h
HEADERS += ../../src/logic/arena_io.h
HEADERS += ../../src/logic/flags.h
HEADERS += ../../src/logic/flags_io.h
HEADERS += ../../src/logic/geometry.h
HEADERS += ../../src/logic/legend.h
HEADERS += ../../src/logic/legend_io.h
HEADERS += ../../src/logic/map.h
HEADERS += ../../src/logic/map_io.h
