#include "engine.h"
#include "mouse.h"
#include "keyboard.h"
#include <ctime>

int engine::SCREEN_WIDTH = 1024;
int engine::SCREEN_HEIGHT = 720;
float engine::dt = 0;

engine::engine(const char* windowName)
{

if(!glfwInit()){
        cout << "couldnt initialize glfw" << endl;
    }

    engine::window = glfwCreateWindow(engine::SCREEN_WIDTH, engine::SCREEN_HEIGHT, windowName, NULL, NULL);

    if(engine::window == NULL){
        cout << "couldnt create a window" << endl;
    }

    srand(time(0));
    int height, width;
    glfwMakeContextCurrent(window);
    glfwGetFramebufferSize(window, &width, &height);

    glfwSwapInterval(1);

    //callbacks
    glfwSetCursorPosCallback(window, mouse::mousePosCallback);
    glfwSetMouseButtonCallback(window, mouse::mouseButtonCallback);
    glfwSetKeyCallback(window, keyboard::keyCallback);

    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

    glfwSetWindowPos(window, (mode->width - SCREEN_WIDTH)/2, (mode->height - SCREEN_HEIGHT) /2);

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, -10, 10 );
    glDepthRange(-10, 10);

    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_ALPHA_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    engine::lastTime  = (float)glfwGetTime();
}

engine::~engine(){

}

void engine::update(){

    float now = (float)glfwGetTime();

    dt = now - lastTime;
    lastTime = now;

    glfwPollEvents();
}

void engine::beginRender(){
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void engine::endRender(){
    glfwSwapBuffers(window);
}

float engine::getDt(){
    return dt;
}
