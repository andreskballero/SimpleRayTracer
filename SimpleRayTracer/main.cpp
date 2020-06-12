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

color rayColor(const ray& ray, const hittable& elements) {
    hit_record rec;
    if (elements.hit(ray, 0, infinity, rec)) {
        return 0.5 * (rec.normal + color(1,1,1));
    }
    vec3 unit_direction = unitVector(ray.getDirection());
    float t = 0.5*(unit_direction.getY() + 1.0);
    return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}

int main(int argc, const char *argv[]) {
    // configuración de la pantalla
    const float aspect_ratio = 16.0 / 9.0;
    const int screen_width = 1000;
    const int screen_height = static_cast<int>(screen_width / aspect_ratio);

    // línea de formato del archivo .ppm - se debe seguir una convención
    // concreta para que se pueda interpretar el .ppm
    std::cout << "P3\n" << screen_width << " " << screen_height << "\n255\n";

    // elementos de cámara
    float viewport_height = 2.0;
    float viewport_width = aspect_ratio * viewport_height;
    float focal_length = 1.0; // distancia entre projection plane y projection point = 1

    point3 origin = point3(0, 0, 0);
    vec3 horizontal = vec3(viewport_width, 0, 0);
    vec3 vertical = vec3(0, viewport_height, 0);
    point3 lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);
    
    // lista de elementos de la escena
    hittable_list elements;
    elements.add(make_shared<sphere>(point3(0,0,-1), 0.5));
    elements.add(make_shared<sphere>(point3(0,-100.5,-1), 100));
    
    // voy bajando, y
    for (int y = screen_height-1; y >= 0; --y) {
        // de izquierda a derecha, x
        for (int x = 0; x < screen_width; ++x) {
            float u = float(x) / (screen_width-1);
            float v = float(y) / (screen_height-1);
            
            ray ray(origin, lower_left_corner + u*horizontal + v*vertical - origin);
            
            color pixel_color = rayColor(ray, elements);
            
            printColor(std::cout, pixel_color);
        }
    }
    
    return EXIT_SUCCESS;
}
