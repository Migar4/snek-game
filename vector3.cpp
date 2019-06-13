#include "vector3.h"
#include <cmath>

using namespace std;

vector3::vector3(): x(0), y(0), z(0)
{

}

vector3::vector3(float _x, float _y): x(_x), y(_y), z(0){

}

vector3::vector3(float _x, float _y, float _z): x(_x), y(_y), z(_z){

}


vector3::vector3(const vector3 &u): x(u.x), y(u.y), z(u.z){

}

vector3::vector3(float _x): x(_x), y(_x), z(_x){

}
vector3::~vector3(){

}

double vector3::magnitude(const vector3 &u){
    return sqrt(pow(u.x, 2.0) + pow(u.y, 2.0) + pow(u.z, 2.0));
}

int vector3::dot(const vector3 &u, const vector3 &v){
    return (u.x * v.x) + (u.y * v.y) + (u.z * v.z);
}

float vector3::project(const vector3 &u, const vector3 &v){
    return (float)(dot(u, v) / magnitude(v));
}


vector3 vector3::operator +(const vector3& v){
    vector3 ret;
    ret.x = this->x + v.x;
    ret.y = this->y + v.y;
    ret.z = this->z + v.z;
    return ret;
}

vector3 vector3::operator-(const vector3& v){
    vector3 ret;
    ret.x = this->x - v.x;
    ret.y = this->y - v.y;
    ret.z = this->z - v.z;
    return ret;
}


vector3 vector3::operator *(const vector3& v){
    vector3 ret;
    ret.x = this->x * v.x;
    ret.y = this->y * v.y;
    ret.z = this->z * v.z;
    return ret;
}

vector3 vector3::operator *(const float v){
    vector3 ret;
    ret.x = this->x * v;
    ret.y = this->y * v;
    ret.z = this->z * v;
    return ret;
}

vector3 vector3::operator /(const vector3& v){
    vector3 ret;
    ret.x = this->x / v.x;
    ret.y = this->y / v.y;
    ret.z = this->z / v.z;
    return ret;
}

vector3& vector3::operator =(const vector3& v){
    x = v.x;
    y = v.y;
    z = v.z;

    return *this;
}


bool vector3::operator ==(const vector3& v){
    return(x == v.x && y == v.y && z == v.z);
}

bool vector3::operator !=(const vector3& v){
    return !(operator ==(v));
}

ostream& operator << (ostream& out, vector3 v){
    out << "X: " << v.x << " Y: " << v.y << " Z: " << v.z;
    return out;
}

float vector3::getX()const {
    return x;
}

float vector3::getY() const{
    return y;
}

float vector3::getZ() const{
    return z;
}

void vector3::setX(float _x){
    x = _x;
}

void vector3::setY(float _y){
    y = _y;
}

void vector3::setZ(float _z){
    z = _z;
}
