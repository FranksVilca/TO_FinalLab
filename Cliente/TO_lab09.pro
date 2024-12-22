QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    BaseDeDatos.cpp \
    Cliente.cpp \
    Cliente_factory.cpp \
    VentanaPrincipal.cpp \
    main.cpp \
    singleton.cpp

HEADERS += \
    BaseDeDatos.h \
    Cliente.h \
    Cliente_factory.h \
    VentanaPrincipal.h \
    singleton.h \
    ui_VentanaPrincipal.h


FORMS += VentanaPrincipal.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
