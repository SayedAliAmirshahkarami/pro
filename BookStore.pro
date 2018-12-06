#-------------------------------------------------
#
# Project created by QtCreator 2018-12-01T18:24:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BookStore
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
    book.cpp \
    booklist.cpp \
    customerwindow.cpp \
    acountantwindow.cpp

HEADERS  += mainwindow.h \
    book.h \
    booklist.h \
    customerwindow.h \
    acountantwindow.h

FORMS    += mainwindow.ui \
    customerwindow.ui \
    acountantwindow.ui
