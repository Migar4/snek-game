#include "keyboard.h"

bool keyboard::keys[GLFW_KEY_LAST] = {0};
bool keyboard::keysDown[GLFW_KEY_LAST] = {0};
bool keyboard::keysUp[GLFW_KEY_LAST] = {0};


keyboard::keyboard()
{

}

keyboard::~keyboard(){

}

void keyboard::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods){
    if(action!=GLFW_RELEASE && keys[key] == false){
        keysDown[key] = true;
        keysUp[key] = false;
    }

    if(action==GLFW_RELEASE && keys[key] == true){
        keysDown[key] = false;
        keysUp[key] = true;
    }

    keys[key] = action!=GLFW_RELEASE;
}

bool keyboard::keyDown(int key){
    bool ret = false;
    ret = keysDown[key];
    keysDown[key] = false;
    return ret;
}

bool keyboard::keyUp(int key){
    bool ret = false;
    ret = keysUp[key];
    keysUp[key] = false;
    return ret;
}

bool keyboard::currentKey(int key){
    return keys[key];
}
