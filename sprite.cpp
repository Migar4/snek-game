#include "sprite.h"
#include "engine.h"
#include "mathfuncs.h"
#include <stdio.h>

sprite::sprite()
{
    pos = vector3(0, 0, 0);
    rot = 0;
    speed = 1000;
    scale  = vector3(1, 0, 0);
    size = vector3(0, 0, 0);
    tex = texture();
    up = false;
    down = false;
    left = false;
    right = false;
}

sprite::sprite(string path){
    tex = texture(path);
    rot = 0;
    speed = 1000;
    pos = vector3(0, 0, 0);
    scale = vector3(1, 1, 0);
    size = vector3(tex.getWidth(), tex.getHeight(), 0);

    up = false;
    down = false;
    left = false;
    right = false;
}

sprite::sprite(string path, vector3 _pos){
    tex = texture(path);
    pos = _pos;
    rot = 0;
    speed = 1000;
    scale = vector3(1, 1, 1);
    size = vector3(tex.getWidth(), tex.getHeight(), 0);

    up = false;
    down = false;
    left = false;
    right = false;
}

sprite::~sprite(){

}

void sprite::update(){

}

void sprite::render(){
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex.getId());

    glLoadIdentity();
    glTranslatef(pos.getX(), pos.getY(), pos.getZ());

    glRotatef(rot, 0, 0, 1);
    glScalef(scale.getX(), scale.getY(), scale.getZ());

    glColor4f(1, 1, 1, 1);
    glBegin(GL_QUADS);

    glTexCoord2d(0, 0);
    glVertex2i(-tex.getWidth()/2, -tex.getHeight()/2);

    glTexCoord2d(1, 0);
    glVertex2i(tex.getWidth()/2, -tex.getHeight()/2);

    glTexCoord2d(1, 1);
    glVertex2i(tex.getWidth()/2, tex.getHeight()/2);

    glTexCoord2d(0, 1);
    glVertex2i(-tex.getWidth()/2, tex.getHeight()/2);

    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void sprite::speedTo(float _speed){
    speed = _speed;
}

void sprite::speedBy(float _speed){
    speed += _speed;
}

void sprite::setScale(float _scale){
    scale = vector3(_scale, _scale, _scale);
}

void sprite::setScale(vector3 v){
    scale = v;
}

void sprite::rotateTo(float deg){
    rot = deg;
}

void sprite::rotateBy(float deg){
    rot += mathFuncs::toRadians(deg) * engine::getDt();
}

void sprite::moveTo(vector3 v){
    pos = v;
}

void sprite::moveBy(vector3 v){
    pos = pos + (v * engine::getDt());
}

void sprite::moveLeft(){
    pos = pos - vector3((speed*engine::getDt()), 0, 0);
}

void sprite::moveRight(){
    pos = pos + vector3((speed*engine::getDt()), 0, 0);
}

void sprite::moveUp(){
    pos = pos + vector3(0, (speed*engine::getDt()), 0);
}

void sprite::moveDown(){
    pos = pos - vector3(0, (speed*engine::getDt()), 0);
}

vector3* sprite::getPos(){
    return &pos;
}

float* sprite::getRot(){
    return &rot;
}

vector3* sprite::getScale(){
    return &scale;
}

vector3* sprite::getSize(){
    return &size;
}

void sprite::flipHorizontally(){
    scale.setX(-scale.x);
    update();
}

void sprite::flipVertically(){
    scale.setY(-scale.y);
    update();
}

void sprite::setPos(vector3 _pos){
    pos = _pos;
}
