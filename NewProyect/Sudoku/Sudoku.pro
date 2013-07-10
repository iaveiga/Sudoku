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
    tablero.cpp \
    sudok.cpp \
    cell.cpp \
    inicio.cpp \
    Tablet.cpp \
    sudoku_ui.cpp

HEADERS  += \
    tablero.h \
    sudok.h \
    cell.h \
    inicio.h \
    tablet.h \
    sudoku_ui.h

FORMS    += \
    tablero.ui \
    inicio.ui \
    sudoku_ui.ui
