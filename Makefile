#############################################################################
# Makefile for building: Scanner
# Generated by qmake (2.01a) (Qt 4.8.3) on: ?? 11? 8 20:06:33 2012
# Project:  Scanner.pro
# Template: app
# Command: /usr/bin/qmake -o Makefile Scanner.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -march=i686 -mtune=generic -O2 -pipe -fstack-protector --param=ssp-buffer-size=4 -D_FORTIFY_SOURCE=2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -march=i686 -mtune=generic -O2 -pipe -fstack-protector --param=ssp-buffer-size=4 -D_FORTIFY_SOURCE=2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt/mkspecs/linux-g++ -I. -I/usr/include/QtCore -I/usr/include/QtGui -I/usr/include -Imoc -I.
LINK          = g++
LFLAGS        = -Wl,-O1,--sort-common,--as-needed,-z,relro -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = object/

####### Files

SOURCES       = main.cpp \
		window.cpp \
		center.cpp moc/moc_window.cpp \
		moc/moc_center.cpp
OBJECTS       = object/main.o \
		object/window.o \
		object/center.o \
		object/moc_window.o \
		object/moc_center.o
DIST          = /usr/share/qt/mkspecs/common/unix.conf \
		/usr/share/qt/mkspecs/common/linux.conf \
		/usr/share/qt/mkspecs/common/gcc-base.conf \
		/usr/share/qt/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt/mkspecs/common/g++-base.conf \
		/usr/share/qt/mkspecs/common/g++-unix.conf \
		/usr/share/qt/mkspecs/qconfig.pri \
		/usr/share/qt/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt/mkspecs/features/qt_functions.prf \
		/usr/share/qt/mkspecs/features/qt_config.prf \
		/usr/share/qt/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt/mkspecs/features/default_pre.prf \
		/usr/share/qt/mkspecs/features/release.prf \
		/usr/share/qt/mkspecs/features/default_post.prf \
		/usr/share/qt/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt/mkspecs/features/warn_on.prf \
		/usr/share/qt/mkspecs/features/qt.prf \
		/usr/share/qt/mkspecs/features/unix/thread.prf \
		/usr/share/qt/mkspecs/features/moc.prf \
		/usr/share/qt/mkspecs/features/resources.prf \
		/usr/share/qt/mkspecs/features/uic.prf \
		/usr/share/qt/mkspecs/features/yacc.prf \
		/usr/share/qt/mkspecs/features/lex.prf \
		/usr/share/qt/mkspecs/features/include_source_dir.prf \
		Scanner.pro
QMAKE_TARGET  = Scanner
DESTDIR       = 
TARGET        = Scanner

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_window.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: Scanner.pro  /usr/share/qt/mkspecs/linux-g++/qmake.conf /usr/share/qt/mkspecs/common/unix.conf \
		/usr/share/qt/mkspecs/common/linux.conf \
		/usr/share/qt/mkspecs/common/gcc-base.conf \
		/usr/share/qt/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt/mkspecs/common/g++-base.conf \
		/usr/share/qt/mkspecs/common/g++-unix.conf \
		/usr/share/qt/mkspecs/qconfig.pri \
		/usr/share/qt/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt/mkspecs/features/qt_functions.prf \
		/usr/share/qt/mkspecs/features/qt_config.prf \
		/usr/share/qt/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt/mkspecs/features/default_pre.prf \
		/usr/share/qt/mkspecs/features/release.prf \
		/usr/share/qt/mkspecs/features/default_post.prf \
		/usr/share/qt/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt/mkspecs/features/warn_on.prf \
		/usr/share/qt/mkspecs/features/qt.prf \
		/usr/share/qt/mkspecs/features/unix/thread.prf \
		/usr/share/qt/mkspecs/features/moc.prf \
		/usr/share/qt/mkspecs/features/resources.prf \
		/usr/share/qt/mkspecs/features/uic.prf \
		/usr/share/qt/mkspecs/features/yacc.prf \
		/usr/share/qt/mkspecs/features/lex.prf \
		/usr/share/qt/mkspecs/features/include_source_dir.prf \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -o Makefile Scanner.pro
/usr/share/qt/mkspecs/common/unix.conf:
/usr/share/qt/mkspecs/common/linux.conf:
/usr/share/qt/mkspecs/common/gcc-base.conf:
/usr/share/qt/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt/mkspecs/common/g++-base.conf:
/usr/share/qt/mkspecs/common/g++-unix.conf:
/usr/share/qt/mkspecs/qconfig.pri:
/usr/share/qt/mkspecs/modules/qt_phonon.pri:
/usr/share/qt/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt/mkspecs/features/qt_functions.prf:
/usr/share/qt/mkspecs/features/qt_config.prf:
/usr/share/qt/mkspecs/features/exclusive_builds.prf:
/usr/share/qt/mkspecs/features/default_pre.prf:
/usr/share/qt/mkspecs/features/release.prf:
/usr/share/qt/mkspecs/features/default_post.prf:
/usr/share/qt/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt/mkspecs/features/warn_on.prf:
/usr/share/qt/mkspecs/features/qt.prf:
/usr/share/qt/mkspecs/features/unix/thread.prf:
/usr/share/qt/mkspecs/features/moc.prf:
/usr/share/qt/mkspecs/features/resources.prf:
/usr/share/qt/mkspecs/features/uic.prf:
/usr/share/qt/mkspecs/features/yacc.prf:
/usr/share/qt/mkspecs/features/lex.prf:
/usr/share/qt/mkspecs/features/include_source_dir.prf:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile Scanner.pro

dist: 
	@$(CHK_DIR_EXISTS) object/Scanner1.0.0 || $(MKDIR) object/Scanner1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) object/Scanner1.0.0/ && $(COPY_FILE) --parents unp.h config.h types.h listener.h window.h exception.h center.h object/Scanner1.0.0/ && $(COPY_FILE) --parents main.cpp window.cpp center.cpp object/Scanner1.0.0/ && $(COPY_FILE) --parents window.ui object/Scanner1.0.0/ && (cd `dirname object/Scanner1.0.0` && $(TAR) Scanner1.0.0.tar Scanner1.0.0 && $(COMPRESS) Scanner1.0.0.tar) && $(MOVE) `dirname object/Scanner1.0.0`/Scanner1.0.0.tar.gz . && $(DEL_FILE) -r object/Scanner1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc/moc_window.cpp moc/moc_center.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc/moc_window.cpp moc/moc_center.cpp
moc/moc_window.cpp: center.h \
		types.h \
		exception.h \
		window.h
	/usr/bin/moc $(DEFINES) $(INCPATH) window.h -o moc/moc_window.cpp

moc/moc_center.cpp: types.h \
		exception.h \
		center.h
	/usr/bin/moc $(DEFINES) $(INCPATH) center.h -o moc/moc_center.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_window.h
compiler_uic_clean:
	-$(DEL_FILE) ui_window.h
ui_window.h: window.ui
	/usr/bin/uic window.ui -o ui_window.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

object/main.o: main.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o object/main.o main.cpp

object/window.o: window.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o object/window.o window.cpp

object/center.o: center.cpp center.h \
		types.h \
		exception.h \
		listener.h \
		unp.h \
		config.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o object/center.o center.cpp

object/moc_window.o: moc/moc_window.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o object/moc_window.o moc/moc_window.cpp

object/moc_center.o: moc/moc_center.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o object/moc_center.o moc/moc_center.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

