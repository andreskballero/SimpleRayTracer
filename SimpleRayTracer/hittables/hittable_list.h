//
//  hittable_list.h
//  SimpleRayTracer
//
//  Created by Andrés Caballero Toledo on 12/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

class hittable_list: public hittable {
public:
    hittable_list() {}
    hittable_list(shared_ptr<hittable> object) { add(object); }

    void clear();
    void add(shared_ptr<hittable> object);

    virtual bool hit(const ray& rayo, float t_min, float t_max, hit_record& rec) const;

private:
    std::vector<shared_ptr<hittable>> objects;
};

#endif
