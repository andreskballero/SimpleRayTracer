//
//  sphere.h
//  SimpleRayTracer
//
//  Created by Andrés Caballero Toledo on 11/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec3.h"

class sphere: public hittable {
public:
    sphere() {}
    sphere(point3 cen, double r) : center(cen), radius(r) {};

    point3 getCenter() const;
    float getRadius() const;
    
    virtual bool hit(const ray& rayo, float t_min, float t_max, hit_record& rec) const;

private:
    point3 center;
    float radius;
};

#endif
