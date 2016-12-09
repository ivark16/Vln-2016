QT += core
QT -= gui
QT += core gui sql
QT += sql

CONFIG += c++11

TARGET = Vln-2016
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    consoleui.cpp \
    listservices.cpp \
    scientistList.cpp \
    DataLayer.cpp \
    scientist.cpp \
    computer.cpp \
    searching.cpp \
    ui.cpp \
    connection.cpp \
    playgame.cpp

HEADERS += \
    consoleui.h \
    listservices.h \
    scientistList.h \
    DataLayer.h \
    scientist.h \
    computer.h \
    searching.h \
    ui.h \
    connection.h \
    playgame.h
