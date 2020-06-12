//
//  rtweekend.h
//  SimpleRayTracer
//
//  Created by Andrés Caballero Toledo on 12/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>


// usings
using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// constantes
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// funciones de utilidad
inline float degrees_to_radians(float degrees) {
    return degrees * pi / 180;
}

    // devuelve un número random entre 0 y 1
inline float randomFloat() {
    return rand() / (RAND_MAX + 1.0);
}

    // devuelve un número random entre min y max
inline float randomFloat(float min, float max) {
    return min + (max-min)*randomFloat();
}

    // abraza la x entre min y max
inline float clamp(float x, float min, float max) {
    if (x < min) return min;
    if (x > max) return max;
    return x;
}

// headers comunes
#include "ray.h"
#include "vec3.h"
#include "color.h"
#include "camera.h"

#endif

