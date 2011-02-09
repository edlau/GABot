TEMPLATE = app
CONFIG = qt release
INCLUDEPATH = include
HEADERS = \
	include/bot.h \
	include/coordinate.h \
	include/direction.h \
	include/rotation.h \
	include/thing.h \
	include/garule.h \
	include/simplega.h \
	include/mainwindow.h \
	include/botview.h \
	include/team.h \
	include/gabot.h \
	include/arena.h \
	include/ball.h \
	include/teamparser.h \
	include/teamdata.h \
	include/game.h \
	include/random.h
SOURCES = \
	src/main.cpp \
	src/bot.cpp \
	src/garule.cpp \
	src/simplega.cpp \
	src/mainwindow.cpp \
	src/botview.cpp \
	src/team.cpp \
	src/gabot.cpp \
	src/arena.cpp \
	src/ball.cpp \
	src/teamparser.cpp \
	src/teamdata.cpp \
	src/game.cpp \
	src/random.cpp
TARGET = gabot
