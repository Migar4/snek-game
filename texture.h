#ifndef TEXTURE_H
#define TEXTURE_H

#include <GLFW/glfw3.h>
#include <SOIL/SOIL.h>
#include <iostream>

using namespace std;

class texture
{
public:
    texture();
    texture(int _id);
    texture(string path);
    ~texture();

    int getHeight();
    int getWidth();
    int getId();


private:

    bool getTextureParams();

    int id, height, width;
};

#endif // TEXTURE_H
