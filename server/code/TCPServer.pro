QT -= gui
QT += network
CONFIG += c++17 console
CONFIG -= app_bundle
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += headers\
               thirdPartyLibraries/zipper

SOURCES += \
        src/main.cpp \
        src/tcpconnection.cpp \
        src/tcprunnable.cpp \
        src/tcpserver.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    headers/tcpconnection.h \
    headers/tcprunnable.h \
    headers/tcpserver.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/thirdPartyLibraries/zipper/build/release/ -lZipper
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/thirdPartyLibraries/zipper/build/debug/ -lZipper
else:unix: LIBS += -L$$PWD/thirdPartyLibraries/zipper/build/ -lZipper

INCLUDEPATH += $$PWD/thirdPartyLibraries/zipper/build
DEPENDPATH += $$PWD/thirdPartyLibraries/zipper/build

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/thirdPartyLibraries/zipper/build/release/libZipper.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/thirdPartyLibraries/zipper/build/debug/libZipper.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/thirdPartyLibraries/zipper/build/release/Zipper.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/thirdPartyLibraries/zipper/build/debug/Zipper.lib
else:unix: PRE_TARGETDEPS += $$PWD/thirdPartyLibraries/zipper/build/libZipper.a
