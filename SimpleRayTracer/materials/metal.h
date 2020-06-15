//
//  metal.h
//  SimpleRayTracer
//
//  Created by Andrés Caballero Toledo on 14/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef METAL_H
#define METAL_H

#include "vec3.h"
#include "material.h"

class metal: public material {
public:
    metal(const color& a, float f) : albedo(a), fuzz((f < 1) ? f : 1) {}
    
    virtual bool scatter(const ray& rayo, const hit_record& rec, color& attenuation, ray& scattered) const;
    
private:
    color albedo;
    float fuzz;
};

#endif
