TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    engine.cpp \
    vector3.cpp \
    mathfuncs.cpp \
    mouse.cpp \
    keyboard.cpp \
    texture.cpp \
    sprite.cpp \
    rigidbody.cpp \
    rect.cpp \
    snek.cpp \
    food.cpp \
    gamemanager.cpp \
    snekbody.cpp

LIBS+= -lSOIL -lGLEW -lglfw -lGL -lX11 -lXi -lXrandr -lXxf86vm -lXinerama -lXcursor -lXcursor -lrt -lm -pthread #`pkg-config --cflags glfw3` `pkg-config --static --libs glfw3`

INCLUDEPATH += $$PWD/../../../../../usr/include/GL
DEPENDPATH += $$PWD/../../../../../usr/include/GL

INCLUDEPATH += $$PWD/../../../../../usr/include/GLFW
DEPENDPATH += $$PWD/../../../../../usr/include/GLFW

HEADERS += \
    engine.h \
    vector3.h \
    mathfuncs.h \
    mouse.h \
    keyboard.h \
    texture.h \
    sprite.h \
    rigidbody.h \
    rect.h \
    snek.h \
    food.h \
    gamemanager.h \
    snekbody.h
