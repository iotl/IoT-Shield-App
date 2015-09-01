TEMPLATE = app

QT += qml quick
CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11


SOURCES += main.cpp \
    TalkBack.cpp \
    Channel.cpp \
    ApiManager.cpp \
    ApiCommon.cpp \
    QmlModel.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    TalkBack.h \
    Channel.h \
    ApiManager.h \
    ApiCommon.h \
    QmlModel.h

