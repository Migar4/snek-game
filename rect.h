#ifndef RECT_H
#define RECT_H

#include "vector3.h"
#include <sstream>

using namespace std;

class rect
{
public:
    rect();
    rect(vector3 _size);
    rect(vector3 _pos, vector3 _size);

    void moveBy(vector3 by);
    void moveTo(vector3 to);

    void setSize(vector3 _size);

    vector3 upperLeftVertex;
    vector3 upperRightVertex;
    vector3 lowerRightVertex;
    vector3 lowerLeftVertex;

    string toString();

    rect& operator=(rect& rc);
    rect operator +(rect& rc);
    vector3 getPos();

private:
    void updateVertices();
    vector3 pos;
    vector3 size;
};

#endif // RECT_H
