#-------------------------------------------------
#
# Project created by QtCreator 2017-08-10T19:54:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtWidgetBasic
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    toolbox/toolbox.cpp \
    qt_mouse_hover/qhoverbutton.cpp \
    qt_image_toggle_button/qimagetogglebutton.cpp \
    qt_group_image_toggle_button/qgroupimagetogglebutton.cpp

HEADERS += \
        mainwindow.h \
    toolbox/toolbox.h \
    qt_mouse_hover/qhoverbutton.h \
    qt_image_toggle_button/qimagetogglebutton.h \
    qt_group_image_toggle_button/qgroupimagetogglebutton.h

FORMS += \
    toolbox/toolbox.ui

RESOURCES += \
    qtwidgetbasic.qrc
