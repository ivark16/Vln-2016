#-------------------------------------------------
#
# Project created by QtCreator 2016-12-12T10:29:54
#
#-------------------------------------------------

QT       += core gui
QT       += core gui sql
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gui-Vln-2016
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    computer.cpp \
    connection.cpp \
    DataLayer.cpp \
    listservices.cpp \
    scientist.cpp \
    searching.cpp \
    addscientist.cpp
        listservices.cpp
        DataLayer.cpp
        scientist.cpp
        computer.cpp
        searching.cpp
        connection.cpp
HEADERS  += mainwindow.h \
    computer.h \
    connection.h \
    DataLayer.h \
    listservices.h \
    scientist.h \
    searching.h \
    sql.h \
    sqlite3.h \
    addscientist.h
        listservices.h
        DataLayer.h
        scientist.h
        computer.h
        searching.h
        connection.h
FORMS    += mainwindow.ui \
    addscientist.ui
INCLUDEPATH += models \
    repositories \
    services \
    ui
