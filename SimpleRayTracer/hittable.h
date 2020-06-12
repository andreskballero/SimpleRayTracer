//
//  hittable.h
//  SimpleRayTracer
//
//  Created by Andrés Caballero Toledo on 12/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

struct hit_record {
    point3 point;
    vec3 normal;
    float t;
    bool front_face;

    inline void setFaceNormal(const ray& ray, const vec3& outward_normal) {
        front_face = dot(ray.getDirection(), outward_normal) < 0;
        normal = front_face ? outward_normal :-outward_normal;
    }

};

class hittable {
public:
    virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const = 0;
};

#endif

