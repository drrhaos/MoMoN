TEMPLATE = app
TARGET = qlocmes
QT += core \
    gui \
    sql \
    network \
    phonon
HEADERS += mudpclient.h \
    mudpserver.h \
    mtcpsocket.h \
    mpopupmessage.h \
    MSqlTableModel.h \
    MSqlRelationalDelegate.h \
    mclient.h \
    mcreateuser.h \
    mmessage.h \
    mserver.h \
    msettings.h \
    mtabwidgets.h \
    mtextedit.h \
    qlocmes.h
SOURCES += mudpclient.cpp \
    mudpserver.cpp \
    mtcpsocket.cpp \
    mpopupmessage.cpp \
    MSqlTableModel.cpp \
    MSqlRelationalDelegate.cpp \
    mclient.cpp \
    mcreateuser.cpp \
    mmessage.cpp \
    mserver.cpp \
    msettings.cpp \
    mtabwidgets.cpp \
    mtextedit.cpp \
    main.cpp \
    qlocmes.cpp
FORMS += mpopupmessage.ui \
    mtabwidgets.ui \
    mmessage.ui \
    msettings.ui \
    qlocmes.ui \
    mcreateuser.ui
RESOURCES += systray.qrc
RC_FILE += qlocmes.rc
