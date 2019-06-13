#ifndef SNEK_H
#define SNEK_H

#include "vector3.h"
#include "rigidbody.h"
#include "sprite.h"
#include "engine.h"
#include "keyboard.h"
#include "mouse.h"
#include <iostream>
#include <GLFW/glfw3.h>
#include <vector>

using namespace std;

class snek
{
public:
    snek();
    snek(string headPath);
    ~snek();

    void reset();
    void handleInput();
    void handleMovement();

    void increaseScore();
    int getScore();
    void increaseLength();
    int getLength();


    sprite getSprite();
    rigidbody& getRigidBody();
    vector3 getPos();

    void update();
    void render();

    bool isRight() const;
    bool isUp() const;
    bool isDown() const;
    bool isLeft() const;



private:
    int length;
    int score;
    int snekSpeed;

    sprite headSpr;


    rigidbody rb;

    vector3 pos;


    vector3 c;
    bool up, down, left, right;

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
};

#endif // SNEK_H
