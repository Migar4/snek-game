#ifndef SPRITE_H
#define SPRITE_H

#include <GLFW/glfw3.h>
#include <iostream>
#include "vector3.h"
#include "texture.h"

using namespace std;

class sprite
{
public:
    sprite();
    sprite(string path);
    sprite(string path, vector3 _pos);
    ~sprite();

    void update();
    void render();

    void moveTo(vector3 v);
    void moveBy(vector3 v);

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

    void speedTo(float _speed);
    void speedBy(float _speed);

    void rotateTo(float deg);
    void rotateBy(float deg);

    void setScale(float _scale);
    void setScale(vector3 v);

    void flipHorizontally();
    void flipVertically();

    bool left, right, up, down;
    vector3* getPos();
    float* getRot();
    vector3* getScale();
    vector3* getSize();
    void setPos(vector3 _pos);

private:
    texture tex;
    float speed;
    vector3 pos;
    float rot;
    vector3 scale;
    vector3 size;
};

#endif // SPRITE_H
