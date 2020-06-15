//
//  material.h
//  SimpleRayTracer
//
//  Created by Andrés Caballero Toledo on 14/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef MATERIAL_H
#define MATERIAL_H

#include "vec3.h"
#include "ray.h"
#include "hittable.h"

class material {
public:
    virtual bool scatter(const ray& rayo, const hit_record& rec, color& attenuation, ray& scattered) const = 0;
};

inline float schlick(float cosine, float ref_idx) {
    float r0 = (1 - ref_idx) / (1 + ref_idx);
    r0 = r0 * r0;
    return r0 + (1 - r0) * pow((1 - cosine), 5);
}

#endif
