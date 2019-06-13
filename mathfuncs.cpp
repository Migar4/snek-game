#include "mathfuncs.h"
#include <ctime>
#include <cstdlib>

namespace mathFuncs {

double toRadians(double degrees){
    return (degrees/180) * PI;
}

double toDegrees(double radians){
    return (radians/PI) * 180;
}

vector3 rotate(vector3 point, const vector3 pivot, float deg){

    double rads = toRadians(deg);
    double s = sin(rads);
    double c = cos(rads);

    point = point - pivot;

    double newX = point.x * c - point.y * s;
    double newY = point.x * s + point.y * c;

    point.x = newX + pivot.x;
    point.y = newY + pivot.y;

    return point;
}


float min(vector<float> v){
    float ret = v[0];

    for(auto &n :v){
        if(ret < n){
            ret = n;
        }
    }
    return ret;
}


float max(vector<float> v){
    float ret = v[0];

    for(auto &n :v){
        if(ret < n){
            ret = n;
        }
    }
    return ret;
}

float abs(float val){
    if(val < 0){
        return -val;
    }
    else{
        return val;
    }
}

int getRandomBetween(int value){
    return ((rand() % value) + 1);
}

}
