//
//  lambertian.cpp
//  SimpleRayTracer
//
//  Created by Andrés Caballero Toledo on 14/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "lambertian.h"

bool lambertian::scatter(const ray& rayo, const hit_record& rec, color& attenuation, ray& scattered) const {
    vec3 scatter_direction = rec.normal + randomUnitVector();
    scattered = ray(rec.point, scatter_direction);
    attenuation = albedo;
    return true;
}
