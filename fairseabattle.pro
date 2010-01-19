# Variables

VERSION = '1.0'
PRERELEASE = ''
COMPILE_DEBUG_IO = 'NO'
DEPLOYERS_EXTRA_TARGETS = 'NO'
#
# You can compile application with debugging output.
# Corresponding sources are available in SVN or in
# special source packages.
#
# COMPILE_DEBUG_IO = 'YES'
#
# You can build packages, but to do it
# you MUST have complete source tree with
# developers part. You can get it from SVN.
#
# DEPLOYERS_EXTRA_TARGETS = 'YES'
#

TEMPLATE = app
# -Wextra -Weffc++
QMAKE_CXXFLAGS = -Wall
QMAKE_CXXFLAGS_RELEASE = -Wall
QT += core gui
CONFIG += release warn_on qt debug
OBJECTS_DIR = build
MOC_DIR = build
RCC_DIR = build
TARGET = fairseabattle
DEFINES += FAIRSEABATTLEVERSION=$$VERSION
!isEmpty(PRERELEASE) {
  DEFINES += FAIRSEABATTLEPRERELEASE=pre$$PRERELEASE
}
DEPENDPATH += src/logic src/control src/gui
INCLUDEPATH += src/logic src/control src/gui
DISTFILES += COPYING MANIFEST README
DISTFILES += images/new.png \
             images/auto.png \
             images/go.png

RESOURCES= fairseabattle.qrc

HEADERS += src/gui/arenawidget.h \
           src/gui/alerter.h \
           src/control/controller.h \
           src/gui/flags_colors.h \
           src/logic/geometry.h \
           src/logic/map.h \
           src/logic/arena.h \
           src/logic/flags.h \
           src/logic/legend.h

SOURCES += src/fairseabattle.cpp \
           src/gui/alerter.cpp \
           src/gui/arenawidget.cpp \
           src/control/controller.cpp \
           src/gui/flags_colors.cpp \
           src/logic/arena.cpp \
           src/logic/geometry.cpp \
           src/logic/map.cpp \
           src/logic/flags.cpp \
           src/logic/legend.cpp

contains(COMPILE_DEBUG_IO, YES) {
message("Configuring COMPILE_DEBUG_IO...")
HEADERS += src/logic/map_io.h \
           src/logic/legend_io.h \
           src/logic/flags_io.h \
           src/logic/arena_io.h
SOURCES += src/logic/map_io.cpp \
           src/logic/legend_io.cpp \
           src/logic/flags_io.cpp \
           src/logic/arena_io.cpp
}

unix {
  install_fairseabattle.path = /usr/local/bin
  install_fairseabattle.commands = $(INSTALL_PROGRAM) $(TARGET) $(INSTALL_ROOT)$$install_fairseabattle.path/$(QMAKE_TARGET)
  INSTALLS += install_fairseabattle
} else {
  message("No install target for your platform.")
  message("Install FairSeaBattle manualy.")
}

contains(DEPLOYERS_EXTRA_TARGETS, YES) {
#
# extra target sdist: source distribution
#
SOURCE_DIST = $${TARGET}-$${VERSION}
SOURCE_DIST_EXT = .tar.gz
!isEmpty(PRERELEASE) {
  SOURCE_DIST = $${SOURCE_DIST}pre$${PRERELEASE}
}
SOURCE_FILES = $$DISTFILES $$SOURCES $$HEADERS $$RESOURCES $${TARGET}.pro

source_dist_root.target = sdist
source_dist_root.depends = $${SOURCE_DIST}$${SOURCE_DIST_EXT}

source_dist.target = $$source_dist_root.depends
source_dist.depends = $$SOURCE_FILES
source_dist.commands  = '$(CHK_DIR_EXISTS) $${SOURCE_DIST} && exit 1;'
source_dist.commands += 'for i in $$source_dist.depends;'
source_dist.commands += 'do'
source_dist.commands += "$(MKDIR) `dirname $${SOURCE_DIST}/\$\$i`;"
source_dist.commands += '$(COPY) \$\$i $${SOURCE_DIST}/\$\$i;'
source_dist.commands += 'done;'
source_dist.commands += 'echo $$SOURCE_FILES | tr " " "\\n" | sort >$${SOURCE_DIST}/MANIFEST;'
source_dist.commands += '$(TAR) $${SOURCE_DIST}.tar $${SOURCE_DIST};'
source_dist.commands += '$(COMPRESS) $${SOURCE_DIST}.tar;'

QMAKE_EXTRA_TARGETS += source_dist_root source_dist
#
# extra target deb: deb distribution
#
# NOTE!!!
# To use it you need
#   -- deb-based linux (debian, ubuntu, etc.)
#   -- complete set of sources from SVN
#
deb_dist_root.target = deb
deb_dist_root.commands  = '$(CHK_DIR_EXISTS) debian && exit 1;'
deb_dist_root.commands += '$(COPY_DIR) devel/debian debian;'
deb_dist_root.commands += 'chmod 755 debian/rules;'
deb_dist_root.commands += 'dpkg-buildpackage -b -us -uc -rfakeroot;'

QMAKE_EXTRA_TARGETS += deb_dist_root
#
# end of section
#
}
