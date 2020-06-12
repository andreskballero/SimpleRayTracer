//
//  ray.cpp
//  SimpleRayTracer
//
//  Created by Andrés Caballero Toledo on 10/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "ray.h"

point3 ray::getOrigin() const {
    return origin;
}

vec3 ray::getDirection() const {
    return direction;
}

point3 ray::currentPoint(float t) const {
    return origin + t * direction;
}

