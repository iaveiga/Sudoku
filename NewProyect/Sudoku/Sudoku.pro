#-------------------------------------------------
#
# Project created by QtCreator 2013-07-09T00:55:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sudoku
TEMPLATE = app


SOURCES += main.cpp\
        sudoku.cpp \
    tablero.cpp \
    sudok.cpp \
    cell.cpp \
    inicio.cpp \
    Tablet.cpp

HEADERS  += sudoku.h \
    tablero.h \
    sudok.h \
    cell.h \
    inicio.h \
    tablet.h

FORMS    += sudoku.ui \
    tablero.ui \
    inicio.ui
