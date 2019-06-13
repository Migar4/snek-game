#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include <GLFW/glfw3.h>
#include <unistd.h>
#include "engine.h"
#include "mouse.h"
#include "keyboard.h"
#include "mathfuncs.h"
#include "texture.h"
#include "sprite.h"
#include "rect.h"
#include "rigidbody.h"
#include "snek.h"
#include "food.h"
#include "snekbody.h"

using namespace std;

class gameManager
{
public:

    enum class state{
        START,
        GAMEPLAY,
        GAMEOVER,
        COUNT
    };

    gameManager(string name);
    ~gameManager();

    void start();

private:
    engine * mEngine;
    snek* mPlayer;
    snekBody* mBody;
    food* mFood;

    state mState;
    sprite* mStartSprite;
    sprite* mGameOverSprite;

    void setState(state S);

};

#endif // GAMEMANAGER_H
