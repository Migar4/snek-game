#include "snek.h"
#include "rect.h"

snek::snek()
{
    length = 0;
    score = 0;
    snekSpeed = 200;
    up = false;
    down = false;
    left = false;
    right = true;
    c = vector3(1, 0, 0);
    pos = vector3(engine::SCREEN_WIDTH/2, engine::SCREEN_HEIGHT/2, 0);
}

snek::snek(string headPath):snek(){
    headSpr = sprite(headPath, pos);
    vector3 sc(0.1, 0.1, 0);
    headSpr.setScale(sc);
    rect boundingHeadRect(pos, *headSpr.getSize() * (*headSpr.getScale()));
    rb.initialize(0, 0, headSpr.getPos(), headSpr.getRot(), headSpr.getScale(), headSpr.getSize(), boundingHeadRect);

}

snek::~snek(){

}

void snek::update(){
    handleInput();
    handleMovement();

    if(pos.x >= engine::SCREEN_WIDTH){
        pos.x = pos.x - engine::SCREEN_WIDTH;
    }
    if(pos.x <= 0){
        pos.x = engine::SCREEN_WIDTH;
    }
    if(pos.y >= engine::SCREEN_HEIGHT){
        pos.y = pos.y - engine::SCREEN_HEIGHT;
    }
    if(pos.y <= 0){
        pos.y = engine::SCREEN_HEIGHT;
    }


    headSpr.update();
    rb.update();


}

void snek::render(){
    headSpr.render();
    rb.render(c);
}

void snek::reset(){
    length = 0;
    score = 0;
    snekSpeed = 200;
    up = false;
    down = false;
    left = false;
    right = true;
    pos = vector3(engine::SCREEN_WIDTH/2, engine::SCREEN_HEIGHT/2, 0);
    if(down || up){
        headSpr.rotateTo(0);
        up = false;
        down = false;
        left = false;
        right = true;
    }
}


void snek::handleInput(){
    if(keyboard::keyDown(GLFW_KEY_W)){

        if(!down){
            headSpr.rotateTo(90);
            up = true;
            down = false;
            left = false;
            right = false;

            headSpr.up = true;
            headSpr.down = false;
            headSpr.left = false;
            headSpr.right = false;
        }
    }
    if(keyboard::keyDown(GLFW_KEY_S)){

        if(!up){
            headSpr.rotateTo(-90);
            up = false;
            down = true;
            left = false;
            right = false;

            headSpr.up = false;
            headSpr.down = true;
            headSpr.left = false;
            headSpr.right = false;
        }
    }
    if(keyboard::keyDown(GLFW_KEY_A)){

        if(!right){
            headSpr.rotateTo(-180);
            up = false;
            down = false;
            left = true;
            right = false;

            headSpr.up = false;
            headSpr.down = false;
            headSpr.left = true;
            headSpr.right = false;
        }
    }
    if(keyboard::keyDown(GLFW_KEY_D)){

        if(!left){
            headSpr.rotateTo(0);
            up = false;
            down = false;
            left = false;
            right = true;

            headSpr.up = false;
            headSpr.down = false;
            headSpr.left = false;
            headSpr.right = true;
        }
    }
}

void snek::handleMovement(){
    if(right){
        pos.x = pos.x + snekSpeed * engine::getDt();

        headSpr.setPos(pos);
    }
    if(left){
        pos.x = pos.x - snekSpeed * engine::getDt();
        headSpr.setPos(pos);
    }
    if(up){
        pos.y = pos.y + snekSpeed * engine::getDt();
        headSpr.setPos(pos);
    }
    if(down){
        pos.y = pos.y - snekSpeed * engine::getDt();
        headSpr.setPos(pos);
    }
}

void snek::increaseScore(){
    score++;
}

void snek::increaseLength(){
    length++;
}

int snek::getScore(){
    return score;
}

sprite snek::getSprite(){
    return headSpr;
}

rigidbody& snek::getRigidBody(){
    return rb;
}


vector3 snek::getPos() {
    return *headSpr.getPos();
}

bool snek::isDown() const{
    return down;
}

bool snek::isUp() const{
    return up;
}

bool snek::isLeft() const{
    return left;
}

bool snek::isRight() const{
    return right;
}

int snek::getLength(){
    return length;
}
