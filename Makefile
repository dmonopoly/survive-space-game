#############################################################################
# Makefile for building: GameV2.app/Contents/MacOS/GameV2
# Generated by qmake (2.01a) (Qt 4.8.1) on: Thu Apr 19 15:33:34 2012
# Project:  GameV2.pro
# Template: app
# Command: /usr/bin/qmake -spec /usr/local/Qt4.8/mkspecs/macx-g++ -o Makefile GameV2.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -gdwarf-2 -arch x86_64 -Xarch_x86_64 -mmacosx-version-min=10.5 -Wall -W $(DEFINES)
CXXFLAGS      = -pipe -g -gdwarf-2 -arch x86_64 -Xarch_x86_64 -mmacosx-version-min=10.5 -Wall -W $(DEFINES)
INCPATH       = -I/usr/local/Qt4.8/mkspecs/macx-g++ -I. -I/Library/Frameworks/QtCore.framework/Versions/4/Headers -I/usr/include/QtCore -I/Library/Frameworks/QtGui.framework/Versions/4/Headers -I/usr/include/QtGui -I/usr/include -I. -I. -F/Library/Frameworks
LINK          = g++
LFLAGS        = -headerpad_max_install_names -arch x86_64 -Xarch_x86_64 -mmacosx-version-min=10.5
LIBS          = $(SUBLIBS) -F/Library/Frameworks -L/Library/Frameworks -framework QtGui -framework QtCore 
AR            = ar cq
RANLIB        = ranlib -s
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
STRIP         = 
INSTALL_FILE  = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = $(COPY_FILE)
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
export MACOSX_DEPLOYMENT_TARGET = 10.4

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = Asteroid.cpp \
		Attacker.cpp \
		EnergyBall1.cpp \
		EnergyBall2.cpp \
		EnergyBall3.cpp \
		EnergyBallLife.cpp \
		FallingObject.cpp \
		Game.cpp \
		Item.cpp \
		Leviathan.cpp \
		Main.cpp \
		Mothership.cpp \
		Object.cpp \
		Player.cpp \
		Projectile.cpp \
		ScreenHelper.cpp \
		Terrier.cpp moc_Game.cpp
OBJECTS       = Asteroid.o \
		Attacker.o \
		EnergyBall1.o \
		EnergyBall2.o \
		EnergyBall3.o \
		EnergyBallLife.o \
		FallingObject.o \
		Game.o \
		Item.o \
		Leviathan.o \
		Main.o \
		Mothership.o \
		Object.o \
		Player.o \
		Projectile.o \
		ScreenHelper.o \
		Terrier.o \
		moc_Game.o
DIST          = /usr/local/Qt4.8/mkspecs/common/unix.conf \
		/usr/local/Qt4.8/mkspecs/common/mac.conf \
		/usr/local/Qt4.8/mkspecs/common/gcc-base.conf \
		/usr/local/Qt4.8/mkspecs/common/gcc-base-macx.conf \
		/usr/local/Qt4.8/mkspecs/common/g++-base.conf \
		/usr/local/Qt4.8/mkspecs/common/g++-macx.conf \
		/usr/local/Qt4.8/mkspecs/qconfig.pri \
		/usr/local/Qt4.8/mkspecs/modules/qt_webkit_version.pri \
		/usr/local/Qt4.8/mkspecs/features/qt_functions.prf \
		/usr/local/Qt4.8/mkspecs/features/qt_config.prf \
		/usr/local/Qt4.8/mkspecs/features/exclusive_builds.prf \
		/usr/local/Qt4.8/mkspecs/features/default_pre.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/default_pre.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/dwarf2.prf \
		/usr/local/Qt4.8/mkspecs/features/debug.prf \
		/usr/local/Qt4.8/mkspecs/features/default_post.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/default_post.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/x86_64.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/objective_c.prf \
		/usr/local/Qt4.8/mkspecs/features/warn_on.prf \
		/usr/local/Qt4.8/mkspecs/features/qt.prf \
		/usr/local/Qt4.8/mkspecs/features/unix/thread.prf \
		/usr/local/Qt4.8/mkspecs/features/moc.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/rez.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/sdk.prf \
		/usr/local/Qt4.8/mkspecs/features/resources.prf \
		/usr/local/Qt4.8/mkspecs/features/uic.prf \
		/usr/local/Qt4.8/mkspecs/features/yacc.prf \
		/usr/local/Qt4.8/mkspecs/features/lex.prf \
		/usr/local/Qt4.8/mkspecs/features/include_source_dir.prf \
		GameV2.pro
QMAKE_TARGET  = GameV2
DESTDIR       = 
TARGET        = GameV2.app/Contents/MacOS/GameV2

####### Custom Compiler Variables
QMAKE_COMP_QMAKE_OBJECTIVE_CFLAGS = -pipe \
		-g \
		-arch \
		x86_64 \
		-Xarch_x86_64 \
		-mmacosx-version-min=10.5 \
		-Wall \
		-W


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

all: Makefile GameV2.app/Contents/PkgInfo GameV2.app/Contents/Resources/empty.lproj GameV2.app/Contents/Info.plist $(TARGET)

$(TARGET):  $(OBJECTS)  
	@$(CHK_DIR_EXISTS) GameV2.app/Contents/MacOS/ || $(MKDIR) GameV2.app/Contents/MacOS/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: GameV2.pro  /usr/local/Qt4.8/mkspecs/macx-g++/qmake.conf /usr/local/Qt4.8/mkspecs/common/unix.conf \
		/usr/local/Qt4.8/mkspecs/common/mac.conf \
		/usr/local/Qt4.8/mkspecs/common/gcc-base.conf \
		/usr/local/Qt4.8/mkspecs/common/gcc-base-macx.conf \
		/usr/local/Qt4.8/mkspecs/common/g++-base.conf \
		/usr/local/Qt4.8/mkspecs/common/g++-macx.conf \
		/usr/local/Qt4.8/mkspecs/qconfig.pri \
		/usr/local/Qt4.8/mkspecs/modules/qt_webkit_version.pri \
		/usr/local/Qt4.8/mkspecs/features/qt_functions.prf \
		/usr/local/Qt4.8/mkspecs/features/qt_config.prf \
		/usr/local/Qt4.8/mkspecs/features/exclusive_builds.prf \
		/usr/local/Qt4.8/mkspecs/features/default_pre.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/default_pre.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/dwarf2.prf \
		/usr/local/Qt4.8/mkspecs/features/debug.prf \
		/usr/local/Qt4.8/mkspecs/features/default_post.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/default_post.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/x86_64.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/objective_c.prf \
		/usr/local/Qt4.8/mkspecs/features/warn_on.prf \
		/usr/local/Qt4.8/mkspecs/features/qt.prf \
		/usr/local/Qt4.8/mkspecs/features/unix/thread.prf \
		/usr/local/Qt4.8/mkspecs/features/moc.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/rez.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/sdk.prf \
		/usr/local/Qt4.8/mkspecs/features/resources.prf \
		/usr/local/Qt4.8/mkspecs/features/uic.prf \
		/usr/local/Qt4.8/mkspecs/features/yacc.prf \
		/usr/local/Qt4.8/mkspecs/features/lex.prf \
		/usr/local/Qt4.8/mkspecs/features/include_source_dir.prf \
		/Library/Frameworks/QtGui.framework/QtGui.prl \
		/Library/Frameworks/QtCore.framework/QtCore.prl
	$(QMAKE) -spec /usr/local/Qt4.8/mkspecs/macx-g++ -o Makefile GameV2.pro
/usr/local/Qt4.8/mkspecs/common/unix.conf:
/usr/local/Qt4.8/mkspecs/common/mac.conf:
/usr/local/Qt4.8/mkspecs/common/gcc-base.conf:
/usr/local/Qt4.8/mkspecs/common/gcc-base-macx.conf:
/usr/local/Qt4.8/mkspecs/common/g++-base.conf:
/usr/local/Qt4.8/mkspecs/common/g++-macx.conf:
/usr/local/Qt4.8/mkspecs/qconfig.pri:
/usr/local/Qt4.8/mkspecs/modules/qt_webkit_version.pri:
/usr/local/Qt4.8/mkspecs/features/qt_functions.prf:
/usr/local/Qt4.8/mkspecs/features/qt_config.prf:
/usr/local/Qt4.8/mkspecs/features/exclusive_builds.prf:
/usr/local/Qt4.8/mkspecs/features/default_pre.prf:
/usr/local/Qt4.8/mkspecs/features/mac/default_pre.prf:
/usr/local/Qt4.8/mkspecs/features/mac/dwarf2.prf:
/usr/local/Qt4.8/mkspecs/features/debug.prf:
/usr/local/Qt4.8/mkspecs/features/default_post.prf:
/usr/local/Qt4.8/mkspecs/features/mac/default_post.prf:
/usr/local/Qt4.8/mkspecs/features/mac/x86_64.prf:
/usr/local/Qt4.8/mkspecs/features/mac/objective_c.prf:
/usr/local/Qt4.8/mkspecs/features/warn_on.prf:
/usr/local/Qt4.8/mkspecs/features/qt.prf:
/usr/local/Qt4.8/mkspecs/features/unix/thread.prf:
/usr/local/Qt4.8/mkspecs/features/moc.prf:
/usr/local/Qt4.8/mkspecs/features/mac/rez.prf:
/usr/local/Qt4.8/mkspecs/features/mac/sdk.prf:
/usr/local/Qt4.8/mkspecs/features/resources.prf:
/usr/local/Qt4.8/mkspecs/features/uic.prf:
/usr/local/Qt4.8/mkspecs/features/yacc.prf:
/usr/local/Qt4.8/mkspecs/features/lex.prf:
/usr/local/Qt4.8/mkspecs/features/include_source_dir.prf:
/Library/Frameworks/QtGui.framework/QtGui.prl:
/Library/Frameworks/QtCore.framework/QtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/local/Qt4.8/mkspecs/macx-g++ -o Makefile GameV2.pro

GameV2.app/Contents/PkgInfo: 
	@$(CHK_DIR_EXISTS) GameV2.app/Contents || $(MKDIR) GameV2.app/Contents 
	@$(DEL_FILE) GameV2.app/Contents/PkgInfo
	@echo "APPL????" >GameV2.app/Contents/PkgInfo
GameV2.app/Contents/Resources/empty.lproj: 
	@$(CHK_DIR_EXISTS) GameV2.app/Contents/Resources || $(MKDIR) GameV2.app/Contents/Resources 
	@touch GameV2.app/Contents/Resources/empty.lproj
	
GameV2.app/Contents/Info.plist: 
	@$(CHK_DIR_EXISTS) GameV2.app/Contents || $(MKDIR) GameV2.app/Contents 
	@$(DEL_FILE) GameV2.app/Contents/Info.plist
	@sed -e "s,@SHORT_VERSION@,1.0,g" -e "s,@TYPEINFO@,????,g" -e "s,@ICON@,,g" -e "s,@EXECUTABLE@,GameV2,g" -e "s,@TYPEINFO@,????,g" /usr/local/Qt4.8/mkspecs/macx-g++/Info.plist.app >GameV2.app/Contents/Info.plist
dist: 
	@$(CHK_DIR_EXISTS) .tmp/GameV21.0.0 || $(MKDIR) .tmp/GameV21.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/GameV21.0.0/ && $(COPY_FILE) --parents Asteroid.h Attacker.h EnergyBall1.h EnergyBall2.h EnergyBall3.h EnergyBallLife.h FallingObject.h Game.h Item.h Leviathan.h Mothership.h Object.h Player.h Projectile.h ScreenHelper.h Terrier.h .tmp/GameV21.0.0/ && $(COPY_FILE) --parents Asteroid.cpp Attacker.cpp EnergyBall1.cpp EnergyBall2.cpp EnergyBall3.cpp EnergyBallLife.cpp FallingObject.cpp Game.cpp Item.cpp Leviathan.cpp Main.cpp Mothership.cpp Object.cpp Player.cpp Projectile.cpp ScreenHelper.cpp Terrier.cpp .tmp/GameV21.0.0/ && (cd `dirname .tmp/GameV21.0.0` && $(TAR) GameV21.0.0.tar GameV21.0.0 && $(COMPRESS) GameV21.0.0.tar) && $(MOVE) `dirname .tmp/GameV21.0.0`/GameV21.0.0.tar.gz . && $(DEL_FILE) -r .tmp/GameV21.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) -r GameV2.app
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_objective_c_make_all:
compiler_objective_c_clean:
compiler_moc_header_make_all: moc_Game.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_Game.cpp
moc_Game.cpp: ScreenHelper.h \
		Object.h \
		FallingObject.h \
		Player.h \
		Asteroid.h \
		Item.h \
		Attacker.h \
		Projectile.h \
		Leviathan.h \
		Terrier.h \
		Mothership.h \
		EnergyBall1.h \
		EnergyBall2.h \
		EnergyBall3.h \
		EnergyBallLife.h \
		Game.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ Game.h -o moc_Game.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_rez_source_make_all:
compiler_rez_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

Asteroid.o: Asteroid.cpp Asteroid.h \
		FallingObject.h \
		Object.h \
		ScreenHelper.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Asteroid.o Asteroid.cpp

Attacker.o: Attacker.cpp Attacker.h \
		FallingObject.h \
		Object.h \
		ScreenHelper.h \
		Projectile.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Attacker.o Attacker.cpp

EnergyBall1.o: EnergyBall1.cpp EnergyBall1.h \
		Item.h \
		FallingObject.h \
		Object.h \
		ScreenHelper.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o EnergyBall1.o EnergyBall1.cpp

EnergyBall2.o: EnergyBall2.cpp EnergyBall2.h \
		Item.h \
		FallingObject.h \
		Object.h \
		ScreenHelper.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o EnergyBall2.o EnergyBall2.cpp

EnergyBall3.o: EnergyBall3.cpp EnergyBall3.h \
		Item.h \
		FallingObject.h \
		Object.h \
		ScreenHelper.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o EnergyBall3.o EnergyBall3.cpp

EnergyBallLife.o: EnergyBallLife.cpp EnergyBallLife.h \
		Item.h \
		FallingObject.h \
		Object.h \
		ScreenHelper.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o EnergyBallLife.o EnergyBallLife.cpp

FallingObject.o: FallingObject.cpp FallingObject.h \
		Object.h \
		ScreenHelper.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o FallingObject.o FallingObject.cpp

Game.o: Game.cpp Game.h \
		ScreenHelper.h \
		Object.h \
		FallingObject.h \
		Player.h \
		Asteroid.h \
		Item.h \
		Attacker.h \
		Projectile.h \
		Leviathan.h \
		Terrier.h \
		Mothership.h \
		EnergyBall1.h \
		EnergyBall2.h \
		EnergyBall3.h \
		EnergyBallLife.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Game.o Game.cpp

Item.o: Item.cpp Item.h \
		FallingObject.h \
		Object.h \
		ScreenHelper.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Item.o Item.cpp

Leviathan.o: Leviathan.cpp Leviathan.h \
		Attacker.h \
		FallingObject.h \
		Object.h \
		ScreenHelper.h \
		Projectile.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Leviathan.o Leviathan.cpp

Main.o: Main.cpp Game.h \
		ScreenHelper.h \
		Object.h \
		FallingObject.h \
		Player.h \
		Asteroid.h \
		Item.h \
		Attacker.h \
		Projectile.h \
		Leviathan.h \
		Terrier.h \
		Mothership.h \
		EnergyBall1.h \
		EnergyBall2.h \
		EnergyBall3.h \
		EnergyBallLife.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Main.o Main.cpp

Mothership.o: Mothership.cpp Mothership.h \
		Attacker.h \
		FallingObject.h \
		Object.h \
		ScreenHelper.h \
		Projectile.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Mothership.o Mothership.cpp

Object.o: Object.cpp Object.h \
		ScreenHelper.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Object.o Object.cpp

Player.o: Player.cpp Player.h \
		Object.h \
		ScreenHelper.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Player.o Player.cpp

Projectile.o: Projectile.cpp Projectile.h \
		ScreenHelper.h \
		Object.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Projectile.o Projectile.cpp

ScreenHelper.o: ScreenHelper.cpp ScreenHelper.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ScreenHelper.o ScreenHelper.cpp

Terrier.o: Terrier.cpp Terrier.h \
		Attacker.h \
		FallingObject.h \
		Object.h \
		ScreenHelper.h \
		Projectile.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Terrier.o Terrier.cpp

moc_Game.o: moc_Game.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_Game.o moc_Game.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:
