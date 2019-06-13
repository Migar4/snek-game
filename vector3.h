#ifndef VECTOR3_H
#define VECTOR3_H
#include <iostream>

using namespace std;

class vector3
{
public:
    vector3();
    vector3(float _x);
    vector3(float _x, float _y);
    vector3(float _x, float _y, float _z);
    vector3(const vector3& u);
    ~vector3();

    static double magnitude(const vector3& u);
    static int dot(const vector3& u, const vector3& v);
    static float project(const vector3& u, const vector3& v);

    vector3& operator=(const vector3& v);
    vector3 operator+(const vector3& v);
    vector3 operator- (const vector3& v);
    vector3 operator*(const vector3& v);
    vector3 operator *(const float v);
    vector3 operator/(const vector3& v);

    bool operator==(const vector3& v);
    bool operator!=(const vector3& v);
    friend ostream& operator << (ostream& out, vector3 v );


    float getX()const;
    float getY()const;
    float getZ()const;

    void setX(float _x);
    void setY(float _y);
    void setZ(float _z);

    float x;
    float y;
    float z;

};

#endif // VECTOR3_H
