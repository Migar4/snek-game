#include "rigidbody.h"
#include "engine.h"
#include <GLFW/glfw3.h>
#include "mathfuncs.h"
#include <iostream>
#include <stdio.h>
#include "engine.h"

using namespace std;
using namespace mathFuncs;

rigidbody::rigidbody()
{

}

rigidbody::~rigidbody(){

}

void rigidbody::initialize(float _friction, float _gravity,
                           vector3* _pos, float* _rot, vector3* _scale,
                           vector3* _size, rect _boundingRect){
    friction = _friction;
    gravity = _gravity;
    pos = _pos;
    rot = _rot;
    lastRot = *rot;
    scale = _scale;
    size = _size;
    boundingRect = _boundingRect;
}

void rigidbody::update(){
    vel.x *= friction;
    vel.y += gravity;

    *pos = *pos + (vel * engine::getDt());

    boundingRect.moveTo(*pos);


    //bounding rect
    vector3 z(0, 0, 0);
    if(lastRot!=*rot){
        boundingRect.lowerLeftVertex = rotate(boundingRect.lowerLeftVertex,
                                              z, *rot - lastRot);

        boundingRect.lowerRightVertex = rotate(boundingRect.lowerRightVertex,
                                              z, *rot - lastRot);

        boundingRect.upperRightVertex = rotate(boundingRect.upperRightVertex,
                                              z, *rot - lastRot);

        boundingRect.upperLeftVertex = rotate(boundingRect.upperLeftVertex,
                                              z, *rot - lastRot);

        lastRot = *rot;
    }
}

void rigidbody::render(vector3 c){
    glLoadIdentity();
    glTranslatef(pos->x, pos->y, pos->z);

    glColor4f(c.x, c.y, c.z, 1);
    glLineWidth(2.5);

    glBegin(GL_LINES);

    //bounding rect
    glVertex2f(boundingRect.lowerLeftVertex.x, boundingRect.lowerLeftVertex.y);
    glVertex2f(boundingRect.lowerRightVertex.x, boundingRect.lowerRightVertex.y);

    glVertex2f(boundingRect.lowerRightVertex.x, boundingRect.lowerRightVertex.y);
    glVertex2f(boundingRect.upperRightVertex.x, boundingRect.upperRightVertex.y);

    glVertex2f(boundingRect.upperRightVertex.x, boundingRect.upperRightVertex.y);
    glVertex2f(boundingRect.upperLeftVertex.x, boundingRect.upperLeftVertex.y);

    glVertex2f(boundingRect.upperLeftVertex.x, boundingRect.upperLeftVertex.y);
    glVertex2f(boundingRect.lowerLeftVertex.x, boundingRect.lowerLeftVertex.y);

    glEnd();

}


void rigidbody::addForce(vector3 f){
    vel = vel + f;
}

void rigidbody::setVel(vector3 _vel){
    vel = _vel;
}

vector3 rigidbody::getVel(){
    return vel;
}


vector3 rigidbody::getPos(){
    return *pos;
}


bool rigidbody::isRectColliding(const rigidbody &rbA, const rigidbody &rbB){

    bool ALeftB = true;
    bool ARightB = true;
    bool AAboveB = true;
    bool ABelowB = true;

    float minX = engine::SCREEN_WIDTH;
    float maxX = 0;
    float minY = engine::SCREEN_HEIGHT;
    float maxY = 0;

    float BminX = engine::SCREEN_WIDTH;
    float BmaxX = 0;
    float BminY = engine::SCREEN_HEIGHT;
    float BmaxY = 0;

    if((rbA.boundingRect.lowerLeftVertex.getX() + rbA.pos->x) < minX) minX = rbA.boundingRect.lowerLeftVertex.getX() + rbA.pos->x;
    if((rbA.boundingRect.lowerRightVertex.getX() + rbA.pos->x) < minX) minX = rbA.boundingRect.lowerRightVertex.getX() + rbA.pos->x;
    if((rbA.boundingRect.upperLeftVertex.getX() + rbA.pos->x) < minX) minX = rbA.boundingRect.upperLeftVertex.getX() + rbA.pos->x;
    if((rbA.boundingRect.upperRightVertex.getX() + rbA.pos->x) < minX) minX = rbA.boundingRect.upperRightVertex.getX() + rbA.pos->x;

    if((rbA.boundingRect.lowerLeftVertex.getX() + rbA.pos->x) > maxX) maxX = rbA.boundingRect.lowerLeftVertex.getX() + rbA.pos->x;
    if((rbA.boundingRect.lowerRightVertex.getX() + rbA.pos->x) > maxX) maxX = rbA.boundingRect.lowerRightVertex.getX() + rbA.pos->x;
    if((rbA.boundingRect.upperLeftVertex.getX() + rbA.pos->x) > maxX) maxX = rbA.boundingRect.upperLeftVertex.getX() + rbA.pos->x;
    if((rbA.boundingRect.upperRightVertex.getX() + rbA.pos->x) > maxX) maxX = rbA.boundingRect.upperRightVertex.getX() + rbA.pos->x;

    if((rbA.boundingRect.lowerLeftVertex.getY() + rbA.pos->y) < minY) minY = rbA.boundingRect.lowerLeftVertex.getY() + rbA.pos->y;
    if((rbA.boundingRect.lowerRightVertex.getY() + rbA.pos->y) < minY) minY = rbA.boundingRect.lowerRightVertex.getY() + rbA.pos->y;
    if((rbA.boundingRect.upperLeftVertex.getY() + rbA.pos->y) < minY) minY = rbA.boundingRect.upperLeftVertex.getY() + rbA.pos->y;
    if((rbA.boundingRect.upperRightVertex.getY() + rbA.pos->y) < minY) minY = rbA.boundingRect.upperRightVertex.getY() + rbA.pos->y;

    if((rbA.boundingRect.lowerLeftVertex.getY() + rbA.pos->y) > maxY) maxY = rbA.boundingRect.lowerLeftVertex.getY() + rbA.pos->y;
    if((rbA.boundingRect.lowerRightVertex.getY() + rbA.pos->y) > maxY) maxY = rbA.boundingRect.lowerRightVertex.getY() + rbA.pos->y;
    if((rbA.boundingRect.upperLeftVertex.getY() + rbA.pos->y) > maxY) maxY = rbA.boundingRect.upperLeftVertex.getY() + rbA.pos->y;
    if((rbA.boundingRect.upperRightVertex.getY() + rbA.pos->y) > maxY) maxY = rbA.boundingRect.upperRightVertex.getY() + rbA.pos->y;


    if((rbB.boundingRect.lowerLeftVertex.getX() + rbB.pos->x) < BminX) BminX = rbB.boundingRect.lowerLeftVertex.getX() + rbB.pos->x;
    if((rbB.boundingRect.lowerRightVertex.getX() + rbB.pos->x) < BminX) BminX = rbB.boundingRect.lowerRightVertex.getX() + rbB.pos->x;
    if((rbB.boundingRect.upperLeftVertex.getX() + rbB.pos->x) < BminX) BminX = rbB.boundingRect.upperLeftVertex.getX() + rbB.pos->x;
    if((rbB.boundingRect.upperRightVertex.getX() + rbB.pos->x) < BminX) BminX = rbB.boundingRect.upperRightVertex.getX() + rbB.pos->x;

    if((rbB.boundingRect.lowerLeftVertex.getX() + rbB.pos->x) > BmaxX) BmaxX = rbB.boundingRect.lowerLeftVertex.getX() + rbB.pos->x;
    if((rbB.boundingRect.lowerRightVertex.getX() + rbB.pos->x) > BmaxX) BmaxX = rbB.boundingRect.lowerRightVertex.getX() + rbB.pos->x;
    if((rbB.boundingRect.upperLeftVertex.getX() + rbB.pos->x) > BmaxX) BmaxX = rbB.boundingRect.upperLeftVertex.getX() + rbB.pos->x;
    if((rbB.boundingRect.upperRightVertex.getX() + rbB.pos->x) > BmaxX) BmaxX = rbB.boundingRect.upperRightVertex.getX() + rbB.pos->x;

    if((rbB.boundingRect.lowerLeftVertex.getY() + rbB.pos->y) < BminY) BminY = rbB.boundingRect.lowerLeftVertex.getY() + rbB.pos->y;
    if((rbB.boundingRect.lowerRightVertex.getY() + rbB.pos->y) < BminY) BminY = rbB.boundingRect.lowerRightVertex.getY() + rbB.pos->y;
    if((rbB.boundingRect.upperLeftVertex.getY() + rbB.pos->y) < BminY) BminY = rbB.boundingRect.upperLeftVertex.getY() + rbB.pos->y;
    if((rbB.boundingRect.upperRightVertex.getY() + rbB.pos->y) < BminY) BminY = rbB.boundingRect.upperRightVertex.getY() + rbB.pos->y;

    if((rbB.boundingRect.lowerLeftVertex.getY() + rbB.pos->y) > BmaxY) BmaxY = rbB.boundingRect.lowerLeftVertex.getY() + rbB.pos->y;
    if((rbB.boundingRect.lowerRightVertex.getY() + rbB.pos->y) > BmaxY) BmaxY = rbB.boundingRect.lowerRightVertex.getY() + rbB.pos->y;
    if((rbB.boundingRect.upperLeftVertex.getY() + rbB.pos->y) > BmaxY) BmaxY = rbB.boundingRect.upperLeftVertex.getY() + rbB.pos->y;
    if((rbB.boundingRect.upperRightVertex.getY() + rbB.pos->y) > BmaxY) BmaxY = rbB.boundingRect.upperRightVertex.getY() + rbB.pos->y;

    //cout << "AMINX: " << minX << " AMINY: " << minY << endl;
    //cout << "AMAXX: " << maxX << " AMAXY: " << maxY << endl;
    //cout << "BMINX: " << BminX << " BMINY: " << BminY << endl;
    //cout << "BMAXX: " << BmaxX << " BMAXY: " << BmaxY << endl;

    ALeftB = (maxX < BminX);
    ARightB = (minX > BmaxX);
    AAboveB = (minY > BmaxY);
    ABelowB = (maxY < BminY);

    //cout << "A LEFT OF B: " << ALeftB << endl;
    //cout << "A RIGHT OF B: " << ARightB << endl;
    //cout << "A ABOVE B: " << AAboveB << endl;
    //cout << "A BELOW B: " << ABelowB << endl;
    //cout << " \n\n\n\n" << endl;

    return !(ALeftB || ARightB || AAboveB || ABelowB);
}

bool rigidbody::isRectColliding( rigidbody *&rbA,  rigidbody *&rbB){

    bool ALeftB = true;
    bool ARightB = true;
    bool AAboveB = true;
    bool ABelowB = true;

    float minX = engine::SCREEN_WIDTH;
    float maxX = 0;
    float minY = engine::SCREEN_HEIGHT;
    float maxY = 0;

    float BminX = engine::SCREEN_WIDTH;
    float BmaxX = 0;
    float BminY = engine::SCREEN_HEIGHT;
    float BmaxY = 0;

    if((rbA->boundingRect.lowerLeftVertex.getX() + rbA->pos->x) < minX) minX = rbA->boundingRect.lowerLeftVertex.getX() + rbA->pos->x;
    if((rbA->boundingRect.lowerRightVertex.getX() + rbA->pos->x) < minX) minX = rbA->boundingRect.lowerRightVertex.getX() + rbA->pos->x;
    if((rbA->boundingRect.upperLeftVertex.getX() + rbA->pos->x) < minX) minX = rbA->boundingRect.upperLeftVertex.getX() + rbA->pos->x;
    if((rbA->boundingRect.upperRightVertex.getX() + rbA->pos->x) < minX) minX = rbA->boundingRect.upperRightVertex.getX() + rbA->pos->x;

    if((rbA->boundingRect.lowerLeftVertex.getX() + rbA->pos->x) > maxX) maxX = rbA->boundingRect.lowerLeftVertex.getX() + rbA->pos->x;
    if((rbA->boundingRect.lowerRightVertex.getX() + rbA->pos->x) > maxX) maxX = rbA->boundingRect.lowerRightVertex.getX() + rbA->pos->x;
    if((rbA->boundingRect.upperLeftVertex.getX() + rbA->pos->x) > maxX) maxX = rbA->boundingRect.upperLeftVertex.getX() + rbA->pos->x;
    if((rbA->boundingRect.upperRightVertex.getX() + rbA->pos->x) > maxX) maxX = rbA->boundingRect.upperRightVertex.getX() + rbA->pos->x;

    if((rbA->boundingRect.lowerLeftVertex.getY() + rbA->pos->y) < minY) minY = rbA->boundingRect.lowerLeftVertex.getY() + rbA->pos->y;
    if((rbA->boundingRect.lowerRightVertex.getY() + rbA->pos->y) < minY) minY = rbA->boundingRect.lowerRightVertex.getY() + rbA->pos->y;
    if((rbA->boundingRect.upperLeftVertex.getY() + rbA->pos->y) < minY) minY = rbA->boundingRect.upperLeftVertex.getY() + rbA->pos->y;
    if((rbA->boundingRect.upperRightVertex.getY() + rbA->pos->y) < minY) minY = rbA->boundingRect.upperRightVertex.getY() + rbA->pos->y;

    if((rbA->boundingRect.lowerLeftVertex.getY() + rbA->pos->y) > maxY) maxY = rbA->boundingRect.lowerLeftVertex.getY() + rbA->pos->y;
    if((rbA->boundingRect.lowerRightVertex.getY() + rbA->pos->y) > maxY) maxY = rbA->boundingRect.lowerRightVertex.getY() + rbA->pos->y;
    if((rbA->boundingRect.upperLeftVertex.getY() + rbA->pos->y) > maxY) maxY = rbA->boundingRect.upperLeftVertex.getY() + rbA->pos->y;
    if((rbA->boundingRect.upperRightVertex.getY() + rbA->pos->y) > maxY) maxY = rbA->boundingRect.upperRightVertex.getY() + rbA->pos->y;


    if((rbB->boundingRect.lowerLeftVertex.getX() + rbB->pos->x) < BminX) BminX = rbB->boundingRect.lowerLeftVertex.getX() + rbB->pos->x;
    if((rbB->boundingRect.lowerRightVertex.getX() + rbB->pos->x) < BminX) BminX = rbB->boundingRect.lowerRightVertex.getX() + rbB->pos->x;
    if((rbB->boundingRect.upperLeftVertex.getX() + rbB->pos->x) < BminX) BminX = rbB->boundingRect.upperLeftVertex.getX() + rbB->pos->x;
    if((rbB->boundingRect.upperRightVertex.getX() + rbB->pos->x) < BminX) BminX = rbB->boundingRect.upperRightVertex.getX() + rbB->pos->x;

    if((rbB->boundingRect.lowerLeftVertex.getX() + rbB->pos->x) > BmaxX) BmaxX = rbB->boundingRect.lowerLeftVertex.getX() + rbB->pos->x;
    if((rbB->boundingRect.lowerRightVertex.getX() + rbB->pos->x) > BmaxX) BmaxX = rbB->boundingRect.lowerRightVertex.getX() + rbB->pos->x;
    if((rbB->boundingRect.upperLeftVertex.getX() + rbB->pos->x) > BmaxX) BmaxX = rbB->boundingRect.upperLeftVertex.getX() + rbB->pos->x;
    if((rbB->boundingRect.upperRightVertex.getX() + rbB->pos->x) > BmaxX) BmaxX = rbB->boundingRect.upperRightVertex.getX() + rbB->pos->x;

    if((rbB->boundingRect.lowerLeftVertex.getY() + rbB->pos->y) < BminY) BminY = rbB->boundingRect.lowerLeftVertex.getY() + rbB->pos->y;
    if((rbB->boundingRect.lowerRightVertex.getY() + rbB->pos->y) < BminY) BminY = rbB->boundingRect.lowerRightVertex.getY() + rbB->pos->y;
    if((rbB->boundingRect.upperLeftVertex.getY() + rbB->pos->y) < BminY) BminY = rbB->boundingRect.upperLeftVertex.getY() + rbB->pos->y;
    if((rbB->boundingRect.upperRightVertex.getY() + rbB->pos->y) < BminY) BminY = rbB->boundingRect.upperRightVertex.getY() + rbB->pos->y;

    if((rbB->boundingRect.lowerLeftVertex.getY() + rbB->pos->y) > BmaxY) BmaxY = rbB->boundingRect.lowerLeftVertex.getY() + rbB->pos->y;
    if((rbB->boundingRect.lowerRightVertex.getY() + rbB->pos->y) > BmaxY) BmaxY = rbB->boundingRect.lowerRightVertex.getY() + rbB->pos->y;
    if((rbB->boundingRect.upperLeftVertex.getY() + rbB->pos->y) > BmaxY) BmaxY = rbB->boundingRect.upperLeftVertex.getY() + rbB->pos->y;
    if((rbB->boundingRect.upperRightVertex.getY() + rbB->pos->y) > BmaxY) BmaxY = rbB->boundingRect.upperRightVertex.getY() + rbB->pos->y;

    //cout << "AMINX: " << minX << " AMINY: " << minY << endl;
    //cout << "AMAXX: " << maxX << " AMAXY: " << maxY << endl;
    //cout << "BMINX: " << BminX << " BMINY: " << BminY << endl;
    //cout << "BMAXX: " << BmaxX << " BMAXY: " << BmaxY << endl;

    ALeftB = (maxX < BminX);
    ARightB = (minX > BmaxX);
    AAboveB = (minY > BmaxY);
    ABelowB = (maxY < BminY);

    //cout << "A LEFT OF B: " << ALeftB << endl;
    //cout << "A RIGHT OF B: " << ARightB << endl;
    //cout << "A ABOVE B: " << AAboveB << endl;
    //cout << "A BELOW B: " << ABelowB << endl;
    //cout << " \n\n\n\n" << endl;

    return !(ALeftB || ARightB || AAboveB || ABelowB);
}
