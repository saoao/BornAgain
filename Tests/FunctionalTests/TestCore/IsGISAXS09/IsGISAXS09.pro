TEMPLATE = app
CONFIG  += console
CONFIG  -= qt app_bundle
QT      -= core gui

include($$PWD/../../../../shared.pri)
DEFINES += STANDALONE
LIBS += $$BornAgainCore_LIB
SOURCES += IsGISAXS09.cpp
HEADERS += IsGISAXS09.h
