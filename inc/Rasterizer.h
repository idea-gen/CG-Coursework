//
// Created by daniil on 16.02.2022.
//

#pragma once

#include "Primitive.h"
#include "Fragment.h"
#include <utility>

class Rasterizer {
private:
    Primitive _primitive;
public:
    explicit Rasterizer(Primitive primitive) : _primitive(std::move(primitive)) {

    };
    [[nodiscard]] std::vector<Fragment> rasterize() const {
        auto vertices = _primitive.vertices();
        auto& a = vertices[0];
        auto& b = vertices[1];
        auto& c = vertices[2];
        auto divisor = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
        auto matrix = Matrix<3, 3, double>(
                b.x * c.y - c.x * b.y, b.y - c.y, c.x - b.x,
                c.x * a.y - a.x * c.y, c.y - a.y, a.x - c.x,
                a.x * b.y - b.x * a.y, a.y - b.y, b.x - a.x) / divisor;
        Vector<2, int> min, max;
        min.x = (int)std::min(a.x, std::min(b.x, c.x));
        min.y = (int)std::min(a.y, std::min(b.y, c.y));
        max.x = (int)std::max(a.x, std::max(b.x, c.x));
        max.y = (int)std::max(a.y, std::max(b.y, c.y));
        std::vector<Fragment> result;
        for (int x = min.x; x < max.x; x++) {
            for (int y = min.y; y < max.y; y++) {
                auto barycentric = matrix * Vector<3, double>(1., (double)x, (double)y);
                if (barycentric.x >= 0. && barycentric.y >= 0. && barycentric.z >= 0.) {
                    Fragment fragment;
                    auto z = (int)(a.z * barycentric.x + b.z * barycentric.y + c.z * barycentric.z);
                    fragment.position() = Vector<3, int>(x, y, z);
                    result.push_back(fragment);
                }
            }
        }
        return result;
    };
};


