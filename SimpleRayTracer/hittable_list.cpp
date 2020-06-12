//
//  hittable_list.cpp
//  SimpleRayTracer
//
//  Created by Andrés Caballero Toledo on 12/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "hittable_list.h"

void hittable_list::clear() {
    objects.clear();
}

void hittable_list::add(shared_ptr<hittable> object) {
    objects.push_back(object);
}

bool hittable_list::hit(const ray& ray, float t_min, float t_max, hit_record& rec) const {
    hit_record temp_rec;
    bool hit_anything = false;
    float closest_so_far = t_max;

    for (const shared_ptr<hittable>& object : objects) {
        if (object->hit(ray, t_min, closest_so_far, temp_rec)) {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }

    return hit_anything;
}

