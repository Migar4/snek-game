#ifndef SNEKBODY_H
#define SNEKBODY_H

#include "snek.h"
#include "vector3.h"

class snekBody
{
public:
    snekBody(snek& _player);
    ~snekBody();

    void createSpr(string path);

    void update();
    void render();

    void updateHeadPos();
    void updateBody();

    vector<rigidbody*>& getRigidBody();
    //vector<rect>& getRc();
    vector<sprite>& getSpr();
    vector<vector3>& getPos();
    void reset();

private:
    int length;
    vector3 headPos;
    vector3 prevPos;
    vector3 sprPos;
    float rot;

    snek* player;

    rigidbody tempRb;

    vector<vector3> pos;
    vector<sprite> spr;
    vector<rigidbody*> rb;
};

#endif // SNEKBODY_H
