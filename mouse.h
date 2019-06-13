#ifndef MOUSE_H
#define MOUSE_H

#include <GLFW/glfw3.h>
class mouse
{
public:
    mouse();
    ~mouse();

    static void mousePosCallback(GLFWwindow* window, double _x, double _y);
    static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

    static int getMouseX();
    static int getMouseY();

    static bool buttonDown(int button);
    static bool buttonUp(int button);
    static bool currentButtons(int button);



private:
    static double x, y;

    static bool buttons[];
    static bool buttonsDown[];
    static bool buttonsUp[];

};

#endif // MOUSE_H
