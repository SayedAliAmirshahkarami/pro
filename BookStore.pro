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
        uiClasses/mainwindow.cpp\
    bookClasses/book.cpp \
    bookClasses/booklist.cpp \
    uiClasses/customerwindow.cpp \
    uiClasses/acountantwindow.cpp

HEADERS  += uiClasses/mainwindow.h \
    bookClasses/book.h \
    bookClasses/booklist.h \
    uiClasses/customerwindow.h \
    uiClasses/acountantwindow.h

FORMS    += uiClasses/mainwindow.ui \
    uiClasses/customerwindow.ui \
    uiClasses/acountantwindow.ui
