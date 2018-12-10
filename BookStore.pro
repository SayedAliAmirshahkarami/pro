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
    bookClasses/book.cpp \
    bookClasses/booklist.cpp \
    uiClasses/customerwindow.cpp \
    uiClasses/acountantwindow.cpp \
    uiClasses/customerenterwindow.cpp \
    uiClasses/acountantenterwindow.cpp \
    customer.cpp \
    queue.cpp \
    bookstack.cpp

HEADERS  += mainwindow.h \
    bookClasses/book.h \
    bookClasses/booklist.h \
    uiClasses/customerwindow.h \
    uiClasses/acountantwindow.h \
    uiClasses/customerenterwindow.h \
    uiClasses/acountantenterwindow.h \
    customer.h \
    queue.h \
    bookstack.h

FORMS    += mainwindow.ui \
    uiClasses/customerwindow.ui \
    uiClasses/acountantwindow.ui \
    uiClasses/customerenterwindow.ui \
    uiClasses/acountantenterwindow.ui
