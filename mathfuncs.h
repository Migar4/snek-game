#ifndef MATHFUNCS_H
#define MATHFUNCS_H

#include "vector3.h"
#include <vector>
#include <cmath>

using namespace std;

#define PI 3.142

namespace mathFuncs {
    double toRadians(double degrees);
    double toDegrees(double radians);

    vector3 rotate(vector3 point, const vector3 pivot, float deg);
    int getRandomBetween(int value);
    float min(vector<float> v);
    float max(vector<float> v);
    float abs(float val);
}

#endif // MATHFUNCS_H
