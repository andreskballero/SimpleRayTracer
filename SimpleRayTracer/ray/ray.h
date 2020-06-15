//
//  ray.h
//  SimpleRayTracer
//
//  Created by Andrés Caballero Toledo on 10/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
public:
    ray() {}
    ray(const point3& ori, const vec3& dir) : origin(ori), direction(dir) {}

    point3 getOrigin() const;
    vec3 getDirection() const;

    // P(t) = A + tb; donde P es una posición 3D a lo largo de una línea 3D
    point3 currentPoint(float t) const;

private:
    point3 origin;
    vec3 direction;
};

#endif
