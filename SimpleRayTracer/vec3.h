//
//  vec3.h
//  SimpleRayTracer
//
//  Created by Andrés Caballero Toledo on 10/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class vec3 {
public:
    vec3() : x(0), y(0), z(0) {}
    vec3(float xn, float yn, float zn) : x(xn), y(yn), z(zn) {}

    vec3 operator- () const;
    vec3& operator+= (const vec3 &v);
    vec3& operator*= (const float m);
    vec3& operator/= (const float d);

    float length() const;
    float lengthSquared() const;
    
    float getX() const;
    float getY() const;
    float getZ() const;

private:
    float x;
    float y;
    float z;
};

// Type aliases para vec3
using point3 = vec3;   // punto 3D
using color = vec3;    // color RGB

// vec3 funciones de utilidad
inline std::ostream& operator <<(std::ostream& out, const vec3& v) {
    return out << v.getX() << ' ' << v.getY() << ' ' << v.getZ();
}

inline vec3 operator+ (const vec3& u, const vec3& v) {
    return vec3(u.getX() + v.getX(), u.getY() + v.getY(), u.getZ() + v.getZ());
}

inline vec3 operator- (const vec3& u, const vec3& v) {
    return vec3(u.getX() - v.getX(), u.getY() - v.getY(), u.getZ() - v.getZ());
}

inline vec3 operator* (const vec3& u, const vec3& v) {
    return vec3(u.getX() * v.getX(), u.getY() * v.getY(), u.getZ() * v.getZ());
}

inline vec3 operator* (float t, const vec3& v) {
    return vec3(t*v.getX(), t*v.getY(), t*v.getZ());
}

inline vec3 operator* (const vec3& v, float t) {
    return t * v;
}

inline vec3 operator/ (vec3 v, float t) {
    return (1/t) * v;
}

inline float dot(const vec3& u, const vec3& v) {
    return u.getX() * v.getX()
         + u.getY() * v.getY()
         + u.getZ() * v.getZ();
}

inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3(u.getY() * v.getZ() - u.getZ() * v.getY(),
                u.getZ() * v.getX() - u.getX() * v.getZ(),
                u.getX() * v.getY() - u.getY() * v.getX());
}

inline vec3 unitVector(vec3 v) {
    return v / v.length();
}

#endif

