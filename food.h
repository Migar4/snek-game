#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include "sprite.h"
#include "rigidbody.h"
#include "vector3.h"
#include "rect.h"

using namespace std;

class food
{
public:
    food();
    food(string path);
    ~food();

    void render();
    void update();
    void reset();

    void setPos(vector3 _pos);
    vector3 getPos();

    sprite getSprite();
    rigidbody& getRigidbody();

    void changePos();

private:
    sprite spr;
    rigidbody rb;
    vector3 pos;
    vector3 c;
    int x,y;
};

#endif // FOOD_H
