TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++0x -pthread
LIBS += -pthread

SOURCES += main.cpp \
    tcp/tcpserver.cpp \
    server/server.cpp \
    server/chatmessage.cpp

HEADERS += \
    tcp/tcpserver.h \
    utils/safequeue.h \
    tcp/tcppacket.h \
    client.h \
    server/server.h \
    server/chatmessage.h \
    server/channel.h
