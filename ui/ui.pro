######################################################################
# Automatically generated by qmake (3.0) Do. Sep. 25 18:40:14 2014
######################################################################

QT = core gui widgets

TEMPLATE = lib
INCLUDEPATH += ../lib/

CONFIG += staticlib link_pkgconfig
PKGCONFIG +=

# Input
HEADERS += ahpMainWindow.h CriterionListModel.h CriterionRateItem.h
FORMS += ahpMainWindow.ui
SOURCES += ahpMainWindow.cpp CriterionListModel.cpp CriterionRateItem.cpp

QMAKE_CXXFLAGS += -g3 -gdwarf-2
CONFIG += debug console