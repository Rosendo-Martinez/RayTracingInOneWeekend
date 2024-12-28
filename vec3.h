#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class vec3
{
public:
    double elm[3];

    vec3() : elm{0,0,0} {}
    vec3(double elm0, double elm1, double elm2) : elm{elm0,elm1,elm2} {}

    double x() const { return elm[0]; }
    double y() const { return elm[1]; }
    double z() const { return elm[2]; }

    vec3    operator- ()       const { return vec3(-elm[0], -elm[1], -elm[2]); }
    double  operator[](int i)  const { return elm[i]; }
    double& operator[](int i)        { return elm[i]; } 
 
    vec3& operator+=(const vec3& v)
    {
        elm[0] += v.elm[0];
        elm[1] += v.elm[1];
        elm[2] += v.elm[2];
        return *this;
    }

    vec3& operator*=(double t)
    {
        elm[0] *= t;
        elm[1] *= t;
        elm[2] *= t;
        return *this;
    }

    vec3& operator/=(double t)
    {
        return *this *= 1/t;   
    }

    double length() const
    {
        return std::sqrt(length_squared());
    }

    double length_squared() const
    {
        return elm[0]*elm[0] + elm[1]*elm[1] + elm[2]*elm[2];
    }
};

#endif