#-------------------------------------------------
#
# Project created by QtCreator 2013-06-03T21:04:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sudoku
TEMPLATE = app


SOURCES += main.cpp\
        sudokugui.cpp \
    ../Cell.cpp

HEADERS  += sudokugui.h \
    ../Cell.h

FORMS    += sudokugui.ui
