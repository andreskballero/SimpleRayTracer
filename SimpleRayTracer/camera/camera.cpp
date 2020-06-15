//
//  camera.cpp
//  SimpleRayTracer
//
//  Created by Andrés Caballero Toledo on 13/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "camera.h"

camera::camera(point3 lookfrom, point3 lookat, vec3 vup, float vfov, float aspect_ratio, float aperture, float focus_dist) {
    float theta = degreesToRadians(vfov);
    float h = tan(theta / 2);
    float viewport_height = 2.0 * h;
    float viewport_width = viewport_height * aspect_ratio;
    //float focal_length = 1.0; // distancia entre projection plane y projection point = 1
    
    w = unitVector(lookfrom - lookat);
    u = unitVector(cross(vup, w));
    v = cross(w, u);
    
    origin = lookfrom;
    horizontal = focus_dist * viewport_width * u;
    vertical = focus_dist * viewport_height * v;
    lower_left_corner = origin - horizontal/2 - vertical/2 - focus_dist * w;
    
    lens_radius = aperture / 2;
}

ray camera::getRay(float s, float t) const {
    vec3 rd = lens_radius * randomInUnitDisk();
    vec3 offset = u * rd.getX() + v * rd.getY();
    return ray(origin + offset, lower_left_corner + s * horizontal + t * vertical - origin - offset);
}
