#-------------------------------------------------
#
# Project created by QtCreator 2015-03-28T17:40:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtMingwWidgetUnicode
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    good.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../Library/Cpp/boost_1_57_0/build_mingw_32/lib/ -lboost_filesystem-mgw49-mt-1_57 -lboost_system-mgw49-mt-1_57 -lboost_iostreams-mgw49-mt-1_57 -lboost_date_time-mgw49-mt-1_57
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../Library/Cpp/boost_1_57_0/build_mingw_32/lib/ -lboost_filesystem-mgw49-mt-d-1_57 -lboost_system-mgw49-mt-1_57 -lboost_iostreams-mgw49-mt-d-1_57 -lboost_date_time-mgw49-mt-d-1_57
else:unix: LIBS += -L$$PWD/../../../../Library/Cpp/boost_1_57_0/build_mingw_32/lib/ -lboost_filesystem-mgw49-mt-1_57

INCLUDEPATH += $$PWD/../../../../Library/Cpp/boost_1_57_0/build_mingw_32/include/boost-1_57
DEPENDPATH += $$PWD/../../../../Library/Cpp/boost_1_57_0/build_mingw_32/include/boost-1_57


