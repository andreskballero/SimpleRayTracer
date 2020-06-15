//
//  dielectric.cpp
//  SimpleRayTracer
//
//  Created by Andrés Caballero Toledo on 14/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "dielectric.h"

bool dielectric::scatter(const ray& rayo, const hit_record& rec, color& attenuation, ray& scattered) const {
    attenuation = color(1.0, 1.0, 1.0);
    float etai_over_etat = (rec.front_face) ? (1.0 / ref_idx) : (ref_idx);
    
    vec3 unit_direction = unitVector(rayo.getDirection());
    float cos_theta = fmin(dot(-unit_direction, rec.normal), 1.0);
    float sin_theta = sqrt(1.0 - (cos_theta * cos_theta));
    
    if ((etai_over_etat * sin_theta) > 1.0) {
        vec3 reflected = reflect(unit_direction, rec.normal);
        scattered = ray(rec.point, reflected);
        return true;
    }
    
    float reflect_prob = schlick(cos_theta, etai_over_etat);
    if (randomFloat() < reflect_prob) {
        vec3 reflected = reflect(unit_direction, rec.normal);
        scattered = ray(rec.point, reflected);
        return true;
    }
    
    vec3 refracted = refract(unit_direction, rec.normal, etai_over_etat);
    scattered = ray(rec.point, refracted);
    return true;
}
