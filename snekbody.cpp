#include "snekbody.h"
#include <assert.h>

snekBody::snekBody(snek& _player)
{
    headPos = _player.getPos();

    length = _player.getLength();

    player = &_player;
    assert(player != NULL);
    prevPos = headPos;
    sprPos = prevPos;
    rot = 0;
}

snekBody::~snekBody(){

}

void snekBody::createSpr(string path){

    sprite tempSpr(path, prevPos);
    vector3 sc(0.1, 0.1, 0);
    tempSpr.setScale(sc);
    spr.push_back(tempSpr);

    rect* tempRc = new rect(*spr[length].getPos(), *spr[length].getSize() * *spr[length].getScale());
    //rc.push_back(tempRc);

    rigidbody* tempRb = new rigidbody();
    tempRb->initialize(0, 0, spr[length].getPos(), spr[length].getRot(), spr[length].getScale(), spr[length].getSize(), *tempRc);

    rb.push_back(tempRb);

    player->increaseLength();
    length = player->getLength();

}

void snekBody::update(){

    //updateHeadPos();
    headPos = player->getPos();
    length = player->getLength();

    spr[0].left = player->isLeft();
    spr[0].right = player->isRight();
    spr[0].up = player->isUp();
    spr[0].down = player->isDown();

    updateHeadPos();

    //spr[0].setPos(prevPos);

    spr[0].setPos(player->getPos());
    spr[0].rotateTo(*player->getSprite().getRot());
    updateBody();

    spr[0].rotateTo(*player->getSprite().getRot());
    for(unsigned int i = 0; i < spr.size(); i++){
        spr[i].update();
        rb[i]->update();
    }
}

void snekBody::render(){
    for(unsigned int i = 1; i < spr.size(); i++){
        spr[i].render();
        rb[i]->render(vector3(1, 0, 0));
    }
    spr[0].render();
    rb[0]->render(vector3(1, 0, 0));
}


void snekBody::updateHeadPos(){
    headPos = player->getPos();

    if(player->isRight()){
        prevPos.x = headPos.x - ((player->getSprite().getSize()->x * player->getSprite().getScale()->x));
        prevPos.y = headPos.y;
    }
    if(player->isLeft()){
        prevPos.x = headPos.x + ((player->getSprite().getSize()->x * player->getSprite().getScale()->x));
        prevPos.y = headPos.y;
    }
    if(player->isUp()){
        prevPos.x = headPos.x;
        prevPos.y = headPos.y - ((player->getSprite().getSize()->y * player->getSprite().getScale()->y));
    }
    if(player->isDown()){
        prevPos.x = headPos.x;
        prevPos.y = headPos.y + ((player->getSprite().getSize()->y * player->getSprite().getScale()->y));
    }
}

void snekBody::updateBody(){


    for(unsigned int i = spr.size() ; i > 0; i--){
        spr[i].setPos(*spr[i-1].getPos());
    }


    /*for(unsigned int i = 0; i < spr.size() - 1; i++){
        if(spr[i].right){
            spr[i+1].right = true;
            spr[i+1].left = false;
            spr[i+1].up = false;
            spr[i+1].down = false;

            sprPos.x = (spr[i].getPos()->x - ((spr[i].getSize()->x * spr[i].getScale()->x)));
            sprPos.y = (spr[i].getPos()->y);
        }
        if(spr[i].left){
            spr[i+1].right = false;
            spr[i+1].left = true;
            spr[i+1].up = false;
            spr[i+1].down = false;

            sprPos.x = (spr[i].getPos()->x + ((spr[i].getSize()->x * spr[i].getScale()->x)));
            sprPos.y = (spr[i].getPos()->y);
        }
        if(spr[i].up){
            spr[i+1].right = false;
            spr[i+1].left = false;
            spr[i+1].up = true;
            spr[i+1].down = false;

            sprPos.x = spr[i].getPos()->x;
            sprPos.y = spr[i].getPos()->y - ((spr[i].getSize()->y * spr[i].getScale()->y));
        }
        if(spr[i].down){
            spr[i+1].right = false;
            spr[i+1].left = false;
            spr[i+1].up = false;
            spr[i+1].down = true;

            sprPos.x = spr[i].getPos()->x;
            sprPos.y = spr[i].getPos()->y + (spr[i].getSize()->y * spr[i].getScale()->y);
        }

        spr[i+1].setPos(sprPos);
        spr[i+1].rotateTo(*(spr[i].getRot()));

    }*/

}

vector<rigidbody*>& snekBody::getRigidBody(){
    return rb;
}

vector<sprite>& snekBody::getSpr(){
    return spr;
}

vector<vector3>& snekBody::getPos(){
    return pos;
}

void snekBody::reset(){
    spr.empty();
    rb.empty();
    pos.empty();
}
