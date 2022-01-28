QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    change_figure.cpp \
    draw_figure.cpp \
    error_list.cpp \
    figure_work.cpp \
    lib_funcs.cpp \
    main.cpp \
    mainwindow.cpp \
    read_file.cpp \
    selector.cpp

HEADERS += \
    change_figure.h \
    draw_figure.h \
    error_list.h \
    figure_work.h \
    lib_funcs.h \
    mainwindow.h \
    read_file.h \
    selector.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    lab_01_en_GB.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
