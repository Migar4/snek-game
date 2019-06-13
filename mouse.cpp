#include "mouse.h"

double mouse::x = 0;
double mouse::y = 0;

bool mouse::buttonsDown[GLFW_MOUSE_BUTTON_LAST] = {false};
bool mouse::buttonsUp[GLFW_MOUSE_BUTTON_LAST] = {false};
bool mouse::buttons[GLFW_MOUSE_BUTTON_LAST] = {false};


mouse::mouse()
{

}

mouse::~mouse(){

}

int mouse::getMouseX(){
    return x;
}

int mouse::getMouseY(){
    return y;
}

void mouse::mousePosCallback(GLFWwindow *window, double _x, double _y){
    int height;
    int width;

    glfwGetFramebufferSize(window, &width, &height);

    x = _x;
    y = height - _y;
}

void mouse::mouseButtonCallback(GLFWwindow *window, int button, int action, int mods){
    if(action!=GLFW_RELEASE && buttons[button] == false){
        buttonsDown[button] = true;
        buttonsUp[button] = false;
    }

    if(action==GLFW_RELEASE && buttons[button] == true){
        buttonsDown[button] = false;
        buttonsUp[button] = true;
    }

    buttons[button] = (action!=GLFW_RELEASE);
}

bool mouse::buttonDown(int button){
    bool ret = false;
    ret = buttonsDown[button];
    buttonsDown[button] = false;
    return ret;
}

bool mouse::buttonUp(int button){
    bool ret = false;
    ret = buttonsUp[button];
    buttonsUp[button] = false;
    return ret;
}

bool mouse::currentButtons(int button){
    return buttons[button];
}
