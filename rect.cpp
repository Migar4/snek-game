#include "rect.h"
#include "engine.h"

rect::rect()
{
    pos = vector3(0, 0);
    size = vector3(0, 0);
    updateVertices();
}

rect::rect(vector3 _size){
    pos = vector3(0, 0);
    size = _size;
    updateVertices();

}

rect::rect(vector3 _pos, vector3 _size):rect(_size){
    pos = _pos;

    updateVertices();
}

void rect::moveBy(vector3 by){
    pos = pos + by;
    updateVertices();
}

void rect::moveTo(vector3 to){
    pos = to;
    updateVertices();
}

void rect::setSize(vector3 _size){
    size = _size;
    updateVertices();
}

void rect::updateVertices(){
    lowerLeftVertex = vector3(-(size.x/2), -(size.y/2), 0);
    lowerRightVertex = vector3((size.x/2), -(size.y/2), 0);
    upperRightVertex = vector3((size.x/2),(size.y/2), 0);
    upperLeftVertex = vector3(-(size.x/2), (size.y/2), 0);
}

vector3 rect::getPos(){
    return pos;
}

string rect::toString(){
    stringstream ss;
    ss << "(" << pos.x << ", " << pos.y << ", " << pos.z << ") \n";
    ss << "Lower left vertex: (" << lowerLeftVertex.x << ", " << lowerLeftVertex.y << ") \n";
    ss << "Upper right vertex: (" << upperRightVertex.x << ", " << upperRightVertex.y << ") \n";
    ss << endl;

    return ss.str();
}

rect& rect::operator =(rect& rc){
    pos = rc.pos;
    size = rc.size;
    updateVertices();

    return *this;
}

rect rect::operator +(rect& rc){
    pos = pos + rc.pos;
    updateVertices();

    return *this;
}
