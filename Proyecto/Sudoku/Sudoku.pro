#-------------------------------------------------
#
# Project created by QtCreator 2013-07-11T10:20:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sudoku
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cell.cpp \
    sudoku.cpp \
    sudokugenerator.cpp \
    inicio.cpp

HEADERS  += mainwindow.h \
    cell.h \
    sudoku.h \
    sudokugenerator.h \
    inicio.h

FORMS    += mainwindow.ui \
    inicio.ui
