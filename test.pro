QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    myglwidget.cpp

HEADERS += \
    myglwidget.h

win32:LIBS += -lfreeglut
unix:LIBS += -lGL -lGLU -lglut

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# 包含GLUT库
LIBS += -lGL -lGLU -lglut

# 指定包含头文件的路径（如果必要的话）
INCLUDEPATH += /usr/include
