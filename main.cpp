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
#include "gamemanager.h"

using namespace std;



int main()
{

    gameManager gm("snek");
    gm.start();
    return 0;
}

