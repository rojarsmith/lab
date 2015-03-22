#-------------------------------------------------
#
# Project created by QtCreator 2015-03-11T19:22:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtMultiThreadWidgetUi
TEMPLATE = app

SOURCES += main.cpp\
        dialog.cpp \
    mythread.cpp \
    myboostthread.cpp

HEADERS  += dialog.h \
    mythread.h \
    myboostthread.h

FORMS    += dialog.ui


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../Library/Cpp/boost_1_57_0/my_build_dir/lib/ -lboost_thread-mgw49-mt-1_57 -lboost_system-mgw49-mt-1_57
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../Library/Cpp/boost_1_57_0/my_build_dir/lib/ -lboost_thread-mgw49-mt-d-1_57 -lboost_system-mgw49-mt-d-1_57
else:unix: LIBS += -L$$PWD/../../../../Library/Cpp/boost_1_57_0_build_mingw_32bit/lib/ -lboost_thread-mgw49-mt-1_57

INCLUDEPATH += $$PWD/../../../../Library/Cpp/boost_1_57_0/my_build_dir/include/boost-1_57/
DEPENDPATH += $$PWD/../../../../Library/Cpp/boost_1_57_0/my_build_dir/include/boost-1_57/
