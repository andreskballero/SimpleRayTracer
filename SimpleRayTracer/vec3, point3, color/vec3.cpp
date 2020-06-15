//
//  vec3.cpp
//  SimpleRayTracer
//
//  Created by Andrés Caballero Toledo on 10/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "vec3.h"

vec3 vec3::operator-() const {
    return vec3(-x, -y, -z);
}

vec3& vec3::operator+= (const vec3& v) {
    x += v.getX();
    y += v.getY();
    z += v.getZ();
    return *this;
}

vec3& vec3::operator*= (const float m) {
    x *= m;
    y *= m;
    z *= m;
    return *this;
}

vec3& vec3::operator/= (const float d) {
    return *this *= 1/d;
}

float vec3::length() const {
    return sqrt(lengthSquared());
}

float vec3::lengthSquared() const {
    return x*x + y*y + z*z;
}

float vec3::getX() const {
    return x;
}

float vec3::getY() const {
    return y;
}

float vec3::getZ() const {
    return z;
}

