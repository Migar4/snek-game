#include "food.h"
#include "engine.h"
#include "mathfuncs.h"

food::food()
{
    c = vector3(0, 0, 1);
    x = mathFuncs::getRandomBetween(engine::SCREEN_WIDTH);
    y = mathFuncs::getRandomBetween(engine::SCREEN_HEIGHT);
    pos = vector3(x, y, 0);
}

food::food(string path):food(){
    spr = sprite(path);
    vector3 sc(0.1, 0.1, 0);
    spr.setScale(sc);
    rect boundingRect(pos, *spr.getSize() * (*spr.getScale()));
    rb.initialize(0, 0, spr.getPos(), spr.getRot(), spr.getScale(), spr.getSize(), boundingRect);
}

food::~food(){

}

void food::render(){
    spr.render();
    rb.render(c);
}

void food::update(){

    spr.setPos(pos);
    spr.update();
    rb.update();
}

sprite food::getSprite(){
    return spr;
}

rigidbody& food::getRigidbody(){
    return rb;
}

vector3 food::getPos(){
    return pos;
}

void food::setPos(vector3 _pos){
    pos = _pos;
    spr.setPos(pos);
    update();
}

void food::changePos(){
    x = mathFuncs::getRandomBetween(engine::SCREEN_WIDTH);
    y = mathFuncs::getRandomBetween(engine::SCREEN_HEIGHT);
    pos = vector3(x, y, 0);
    update();
}

void food::reset(){
    changePos();
}
