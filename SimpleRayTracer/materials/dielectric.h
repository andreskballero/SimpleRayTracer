//
//  dielectric.h
//  SimpleRayTracer
//
//  Created by Andrés Caballero Toledo on 14/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef DIELECTRIC_H
#define DIELECTRIC_H

#include "vec3.h"
#include "ray.h"
#include "hittable.h"
#include "material.h"

class dielectric: public material {
public:
    dielectric(float ri) : ref_idx(ri) {}
    
    virtual bool scatter(const ray& rayo, const hit_record& rec, color& attenuation, ray& scattered) const;
private:
    float ref_idx;
};

#endif
