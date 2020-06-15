//
//  color.cpp
//  SimpleRayTracer
//
//  Created by Andrés Caballero Toledo on 10/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "vec3.h"
#include "color.h"

void printColor(std::ostream& out, color pixel_color, int samples_per_pixel) {
    float r = pixel_color.getX();
    float g = pixel_color.getY();
    float b = pixel_color.getZ();
    
    // dividir el color total por el número de muestras para hacer la media
    // del color que se debe mostrar
    float scale = 1.0 / samples_per_pixel;
    // corrección gamma 2 para mejorar los colores
    r = sqrt(scale * r);
    g = sqrt(scale * g);
    b = sqrt(scale * b);
    
    // escribir el [0, 255] valor traducido de cada componente color
    out << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(b, 0.0, 0.999)) << '\n';
}
