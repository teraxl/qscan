#-------------------------------------------------
#
# Project created by QtCreator 2018-12-04T14:34:02
#
#-------------------------------------------------

QT       += core gui svg widgets

TARGET = interface
TEMPLATE = lib

DEFINES += INTERFACE_LIBRARY

CONFIG += staticlib
CONFIG += c++14

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

#DESTDIR = $$PWD/../../build/biblos
#OBJECTS_DIR = $$DESTDIR/build/.objd
#MOC_DIR = $$DESTDIR/build/.mocd
#RCC_DIR = $$DESTDIR/build/.qrcd
#UI_DIR = $$DESTDIR/build/.uid

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES +=   \
  baseeditor.cpp \
  basescanimage.cpp \
  documentdata.cpp \
  imageconverter.cpp \
  imagedelegate.cpp \
  imagelistmodel.cpp \
  imageview.cpp \
  papersize.cpp \
  qmenuutils.cpp \
  qscanlogging.cpp \
  stackableframe.cpp

HEADERS += \
    baseeditor.h \
    basescanimage.h \
    documentdata.h \
    imageconverter.h \
    imagedelegate.h \
    imagelistmodel.h \
    imageview.h \
    interface_global.h \
    iplugininterface.h  \
    papersize.h \
    qmenuutils.h \
    qscanlogging.h \
    stackableframe.h

DISTFILES += \
    plugininterface.json

INCLUDEPATH += /usr/local/include

unix|win32: LIBS += -lqyaml-cpp
unix|win32: LIBS += -lyaml-cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../document/release/ -ldocument
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../document/debug/ -ldocument
else:unix: LIBS += -L$$OUT_PWD/../document/ -ldocument

INCLUDEPATH += $$PWD/../document
DEPENDPATH += $$PWD/../document
