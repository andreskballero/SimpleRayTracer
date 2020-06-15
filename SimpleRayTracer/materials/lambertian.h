//
//  lambertian.h
//  SimpleRayTracer
//
//  Created by Andrés Caballero Toledo on 14/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "material.h"

class lambertian: public material {
public:
    lambertian(const color& a) : albedo(a) {}
    
    virtual bool scatter(const ray& rayo, const hit_record& rec, color& attenuation, ray& scattered) const;
    
private:
    color albedo;
};

#endif
