//
//  metal.cpp
//  SimpleRayTracer
//
//  Created by Andrés Caballero Toledo on 14/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "metal.h"

bool metal::scatter(const ray& rayo, const hit_record& rec, color& attenuation, ray& scattered) const {
    vec3 reflected = reflect(unitVector(rayo.getDirection()), rec.normal);
    scattered = ray(rec.point, reflected + (fuzz * randomInUnitSphere()));
    attenuation = albedo;
    return (dot(scattered.getDirection(), rec.normal) > 0);
}
