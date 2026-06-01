# -------------------------------------------------
# Project created by QtCreator 2009-05-11T20:39:49
# -------------------------------------------------
TARGET = OTUPYACHIVATEL
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    Tags.cpp \
    Replacer.cpp \
    RandomGenerator.cpp \
    RandomAdder.cpp \
    Config.cpp \
    toolbarmodeform.cpp \
    aboutdialog.cpp
HEADERS += mainwindow.h \
    Tags.h \
    Replacer.h \
    RandomGenerator.h \
    RandomAdder.h \
    Config.h \
    toolbarmodeform.h \
    aboutdialog.h
FORMS += mainwindow.ui \
    toolbarmodeform.ui \
    aboutdialog.ui
OTHER_FILES += UP4K-men \
    Sitting.ico \
    UP4K-men \
    Left.ico
TRANSLATIONS = otupyachivatel_ru.ts
RESOURCES += resource.qrc
win32 {
RC_FILE = myappico.rc
}
ICON = UP4K-men.ico
