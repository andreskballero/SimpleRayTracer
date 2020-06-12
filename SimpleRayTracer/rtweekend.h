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


// Usings

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180;
}

// Common Headers

#include "ray.h"
#include "vec3.h"
#include "color.h"

#endif

