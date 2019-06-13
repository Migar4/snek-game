#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "vector3.h"
#include "rect.h"

class rigidbody
{
public:
    rigidbody();
    ~rigidbody();

    static bool isRectColliding(const rigidbody& rbA, const rigidbody& rbB);
    static bool isRectColliding(rigidbody*& rbA, rigidbody*& rbB);


    void initialize(float _friction, float _gravity, vector3* _pos, float* _rot,
                    vector3* _scale, vector3* _size, rect _boundingRect);

    void update();
    void render(vector3 c);
    void addForce(vector3 f);

    void setVel(vector3 _vel);
    vector3 getVel();
    vector3 getPos();


private:
    vector3* pos;
    vector3* scale;
    float* rot;
    float lastRot;
    vector3* size;
    float gravity;
    float friction;
    vector3 vel;
    rect boundingRect;
};

#endif // RIGIDBODY_H
