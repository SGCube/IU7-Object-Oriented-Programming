#-------------------------------------------------
#
# Project created by QtCreator 2019-03-04T14:12:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab_04
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
	facade/facade.cpp \
	gui/widget.cpp \
    main.cpp \
	managers/drawmanager.cpp \
	object/camera.cpp \
	object/composite.cpp \
	object/edge.cpp \
	object/model.cpp \
	object/vertex.cpp \
	scene/scene.cpp \
	workers/builder.cpp \
	workers/transformator.cpp \
	workers/uploader.cpp

HEADERS += \
	actions/action.h \
	exception/builderexception.h \
	exception/drawexception.h \
	exception/exceptionbase.h \
	exception/objectexception.h \
	exception/transformerexception.h \
	exception/uploaderexception.h \
	facade/facade.h \
	facade/mediator.h \
	gui/drawer.h \
	gui/widget.h \
	managers/drawmanager.h \
	managers/objectmanager.h \
	managers/uploadmanager.h \
	object/camera.h \
	object/composite.h \
	object/edge.h \
	object/model.h \
	object/object.h \
	object/vertex.h \
	scene/scene.h \
	transformations/transformations.h \
	workers/builder.h \
	workers/transformator.h \
	workers/uploader.h

FORMS += \
    widget.ui
