QT += core
QT -= gui

CONFIG += c++11

TARGET = Vln-2016
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    consoleui.cpp \
    listservices.cpp \
    list.cpp

HEADERS += \
    consoleui.h \
    listservices.h \
    list.h
