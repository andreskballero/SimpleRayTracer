//
//  camera.h
//  SimpleRayTracer
//
//  Created by Andrés Caballero Toledo on 13/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef CAMERA_H
#define CAMERA_H

#include "rtweekend.h"
#include "vec3.h"
#include "ray.h"

class camera {
public:
    camera(point3 lookfrom, point3 lookat, vec3 vup, float vfov, float aspect_ratio, float aperture, float focus_dist);
    
    ray getRay(float s, float t) const;
    
private:
    point3 origin;
    vec3 horizontal;
    vec3 vertical;
    point3 lower_left_corner;
    vec3 u;
    vec3 v;
    vec3 w;
    float lens_radius;
};

#endif
