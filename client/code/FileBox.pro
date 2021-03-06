QT += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += headers \
               thirdPartyLibraries/zipper
SOURCES += \
    src/login.cpp \
    src/main.cpp \
    src/register.cpp \
    src/filebox.cpp \
    src/filesystemtreeview.cpp \
    src/tcpclient.cpp \
    src/serverfilesbrowser.cpp
HEADERS += \
    headers/login.h \
    headers/register.h \
    headers/filebox.h \
    headers/filesystemtreeview.h \
    headers/tcpclient.h \
    headers/serverfilesbrowser.h

FORMS += \
    forms/login.ui \
    forms/register.ui \
    forms/filebox.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ../resources/images/images.qrc
unix:!macx: LIBS += -lZipper