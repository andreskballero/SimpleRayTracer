//
//  main.cpp
//  SimpleRayTracer
//
//  Created by Andrés Caballero Toledo on 10/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "rtweekend.h"

#include "hittable_list.h"
#include "sphere.h"

#include <cstdlib> // aquí están EXIT_SUCCESS y EXIT_ERROR
#include <iostream>

color rayColor(const ray& ray, const hittable& world) {
    hit_record rec;
    if (world.hit(ray, 0, infinity, rec)) {
        return 0.5 * (rec.normal + color(1,1,1));
    }
    vec3 unit_direction = unitVector(ray.getDirection());
    float t = 0.5*(unit_direction.getY() + 1.0);
    return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}

int main(int argc, const char * argv[]) {
    const float aspect_ratio = 16.0 / 9.0;
    const int image_width = 1000;
    const int image_height = static_cast<int>(image_width / aspect_ratio);

    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    float viewport_height = 2.0;
    float viewport_width = aspect_ratio * viewport_height;
    float focal_length = 1.0;

    point3 origin = point3(0, 0, 0);
    vec3 horizontal = vec3(viewport_width, 0, 0);
    vec3 vertical = vec3(0, viewport_height, 0);
    point3 lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);

    hittable_list world;
    world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
    world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));
    
    for (int y = image_height-1; y >= 0; --y) {
        for (int x = 0; x < image_width; ++x) {
            float u = float(x) / (image_width-1);
            float v = float(y) / (image_height-1);
            ray ray(origin, lower_left_corner + u*horizontal + v*vertical - origin);
            color pixel_color = rayColor(ray, world);
            printColor(std::cout, pixel_color);
        }
    }
    
    return EXIT_SUCCESS;
}
