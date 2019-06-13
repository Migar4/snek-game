#ifndef ENGINE_H
#define ENGINE_H

#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

//engine should be responsible of creating a window and giving delta time
class engine
{
public:

    static int SCREEN_WIDTH;
    static int SCREEN_HEIGHT;


    engine(const char* windowName);
    ~engine();

    void update();
    void beginRender();
    void endRender();

    static float getDt();

private:
    static float dt;
    float lastTime;
    GLFWwindow* window;
};

#endif // ENGINE_H
