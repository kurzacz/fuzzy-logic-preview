#-------------------------------------------------
#
# Project created by QtCreator 2018-05-31T01:07:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = FuzzyPreview
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    ArchitekturaMamdani.cpp \
    FunkcjaPrzynaleznosci.cpp \
    ObslugaPrzynaleznosci.cpp \
    Regula.cpp \
    Rozmywanie.cpp \
    SingletonowaFunkcjaPrzynaleznosci.cpp \
    TrapezowaFunkcjaPrzynaleznosci.cpp \
    TrojkatnaFunkcjaPrzynaleznosci.cpp \
    WejscieRozmyte.cpp \
    WyjscieRozmyte.cpp \
    Wyostrzanie.cpp \
    WyostrzanieCOS.cpp \
    ZbiorRozmyty.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    ArchitekturaMamdani.h \
    FunkcjaPrzynaleznosci.h \
    LiczbaRozmyta.h \
    ObslugaPrzynaleznosci.h \
    Przynaleznosc.h \
    Regula.h \
    Rozmywanie.h \
    SingletonowaFunkcjaPrzynaleznosci.h \
    TrapezowaFunkcjaPrzynaleznosci.h \
    TrojkatnaFunkcjaPrzynaleznosci.h \
    WejscieRozmyte.h \
    WyjscieRozmyte.h \
    Wyostrzanie.h \
    WyostrzanieCOS.h \
    Wyrazenie.h \
    ZbiorRozmyty.h

FORMS    += mainwindow.ui
