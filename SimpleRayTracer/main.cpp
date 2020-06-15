//
//  main.cpp
//  SimpleRayTracer
//
//  Created by Andrés Caballero Toledo on 10/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "rtweekend.h"
#include "color.h"
#include "hittable_list.h"
#include "sphere.h"
#include "camera.h"
#include "lambertian.h"
#include "metal.h"
#include "dielectric.h"

#include <cstdlib> // aquí están EXIT_SUCCESS y EXIT_ERROR
#include <iostream>

// función recursiva que debe parar cuando falle al dar en algo
// limitar el máximo recursion depth
color rayColor(const ray& rayo, const hittable& elements, int recursion_depth) {
    hit_record rec;
    
    if (recursion_depth <= 0)
        return color(0, 0, 0);
    
    if (elements.hit(rayo, 0.001, infinity, rec)) {
        ray scattered;
        color attenuation;
        if (rec.mat->scatter(rayo, rec, attenuation, scattered))
            return attenuation * rayColor(scattered, elements, recursion_depth-1);
        return color(0, 0, 0);
    }
    
    vec3 unit_direction = unitVector(rayo.getDirection());
    float t = 0.5*(unit_direction.getY() + 1.0);
    return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}

int main(int argc, const char *argv[]) {
    // configuración de la pantalla
    const float aspect_ratio = 16.0 / 9.0;
    const int screen_width = 400;
    const int screen_height = static_cast<int>(screen_width / aspect_ratio);
    const int samples_per_pixel = 100;
    const int max_recursion_depth = 50;

    // línea de formato del archivo .ppm - se debe seguir una convención
    // concreta para que se pueda interpretar el .ppm
    std::cout << "P3\n" << screen_width << " " << screen_height << "\n255\n";

    // R
    float R = cos(pi / 4);
    
    // lista de elementos de la escena
    hittable_list elements;
    elements.add(make_shared<sphere>(point3(0, 0, -1), 0.5, make_shared<lambertian>(color(0.1, 0.2, 0.5))));
    elements.add(make_shared<sphere>(point3(0, -100.5, -1), 100, make_shared<lambertian>(color(0.8, 0.8, 0.0))));
    
    elements.add(make_shared<sphere>(point3(1, 0, -1), 0.5, make_shared<metal>(color(0.8, 0.6, 0.2), 0.3)));
    
    elements.add(make_shared<sphere>(point3(-1, 0, -1), 0.5, make_shared<dielectric>(1.5)));
    elements.add(make_shared<sphere>(point3(-1, 0, -1), -0.45, make_shared<dielectric>(1.5)));

    
    // cámara
    point3 lookfrom(3, 3, 2);
    point3 lookat(0, 0, -1);
    vec3 vup(0, 1, 0);
    float dist_to_focus = (lookfrom - lookat).length();
    float aperture = 0.0; // cuanto mayor sea la apertura, más luz entra en la cámara y mayor el defocus blur
    
    camera camara(lookfrom, lookat, vup, 30.0, aspect_ratio, aperture, dist_to_focus);
    
    // voy bajando, y
    for (int y = screen_height-1; y >= 0; --y) {
        std::cerr << "\rScanlines remaining: " << y << ' ' << std::flush;
        // de izquierda a derecha, x
        for (int x = 0; x < screen_width; ++x) {
            color pixel_color(0, 0, 0);
            for (int s = 0; s < samples_per_pixel; ++s) {
                float u = (x + randomFloat()) / (screen_width-1);
                float v = (y + randomFloat()) / (screen_height-1);
                ray rayo = camara.getRay(u, v);
                pixel_color += rayColor(rayo, elements, max_recursion_depth);
            }
            printColor(std::cout, pixel_color, samples_per_pixel);
        }
    }
    std::cerr << "\nDone\n";
    
    return EXIT_SUCCESS;
}
