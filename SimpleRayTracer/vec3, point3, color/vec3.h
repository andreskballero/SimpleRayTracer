//
//  vec3.h
//  SimpleRayTracer
//
//  Created by Andrés Caballero Toledo on 10/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef VEC3_H
#define VEC3_H

#include "rtweekend.h"

#include <cmath>
#include <iostream>

class vec3 {
public:
    vec3() : x(0), y(0), z(0) {}
    vec3(float xn, float yn, float zn) : x(xn), y(yn), z(zn) {}

    vec3 operator- () const;
    vec3& operator+= (const vec3& v);
    vec3& operator*= (const float m);
    vec3& operator/= (const float d);

    float length() const;
    float lengthSquared() const;
    
    float getX() const;
    float getY() const;
    float getZ() const;
        
    inline static vec3 randomVector() {
        return vec3(randomFloat(), randomFloat(), randomFloat());
    }
    
    inline static vec3 randomVector(float min, float max) {
        return vec3(randomFloat(min, max), randomFloat(min, max), randomFloat(min, max));
    }

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

// dot product
inline float dot(const vec3& u, const vec3& v) {
    return u.getX() * v.getX()
         + u.getY() * v.getY()
         + u.getZ() * v.getZ();
}

// cross product
inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3(u.getY() * v.getZ() - u.getZ() * v.getY(),
                u.getZ() * v.getX() - u.getX() * v.getZ(),
                u.getX() * v.getY() - u.getY() * v.getX());
}

// transformar en unit vector
inline vec3 unitVector(vec3 v) {
    return v / v.length();
}

inline vec3 randomInUnitSphere() {
    while (true) {
        vec3 rand = vec3::randomVector(-1, 1);
        if (rand.lengthSquared() >= 1.0) continue;
        return rand;
    }
}

inline vec3 randomUnitVector() {
    float a = randomFloat(0, 2 * pi);
    float z = randomFloat(-1, 1);
    float r = sqrt(1 - z * z);
    return vec3(r*cos(a), r*sin(a), z);
}

inline vec3 randomInHemisphere(const vec3& normal) {
    vec3 in_unit_sphere = randomInUnitSphere();
    if (dot(in_unit_sphere, normal) > 0.0)
        return in_unit_sphere;
    else
        return -in_unit_sphere;
}

inline vec3 reflect(const vec3& v, const vec3& n) {
    return v - 2 * dot(v, n) * n;
}

inline vec3 refract(const vec3& uv, const vec3& n, float etai_over_etat) {
    float cos_theta = dot(-uv, n);
    vec3 r_out_parallel = etai_over_etat * (uv + (cos_theta * n));
    vec3 r_out_perp = -sqrt(1.0 - r_out_parallel.lengthSquared()) * n;
    return r_out_parallel + r_out_perp;
}

inline vec3 randomInUnitDisk() {
    while (true) {
        vec3 p = vec3(randomFloat(-1, 1), randomFloat(-1, 1), 0.0);
        if (p.lengthSquared() >= 1) continue;
        return p;
    }
}

#endif

