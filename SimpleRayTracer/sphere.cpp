//
//  sphere.cpp
//  SimpleRayTracer
//
//  Created by Andrés Caballero Toledo on 11/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "sphere.h"

point3 sphere::getCenter() const {
    return center;
}

float sphere::getRadius() const {
    return radius;
}

bool sphere::hit(const ray& ray, float t_min, float t_max, hit_record& rec) const {
    // ecuación de segundo grado simplificada
    vec3 oc = ray.getOrigin() - center;
    float a = ray.getDirection().lengthSquared();
    float half_b = dot(oc, ray.getDirection());
    float c = oc.lengthSquared() - radius*radius;
    float discriminant = half_b*half_b - a*c;

    // si el discriminante es mayor que 0 es que hay dos soluciones; nos quedamos
    // con la solución más pequeña primero porque es el punto más cercano
    if (discriminant > 0) {
        float root = sqrt(discriminant);
        float temp = (-half_b - root)/a;
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.point= ray.currentPoint(rec.t);
            vec3 outward_normal = (rec.point - center) / radius;
            rec.setFaceNormal(ray, outward_normal);
            return true;
        }
        temp = (-half_b + root) / a;
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.point = ray.currentPoint(rec.t);
            vec3 outward_normal = (rec.point - center) / radius;
            rec.setFaceNormal(ray, outward_normal);
            return true;
        }
    }
    return false;
}

