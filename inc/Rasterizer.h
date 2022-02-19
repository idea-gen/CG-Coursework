//
// Created by daniil on 16.02.2022.
//

#pragma once

#include "Primitive.h"
#include "Fragment.h"
#include "BarycentricCalculator.h"
#include <utility>

class Rasterizer {
private:
    Primitive _primitive;
public:
    explicit Rasterizer(Primitive primitive) : _primitive(std::move(primitive)) {

    };
    [[nodiscard]] std::vector<Fragment> rasterize() const {
        auto& vertices = _primitive.vertices();
        auto& a = vertices[0];
        auto& b = vertices[1];
        auto& c = vertices[2];
        BarycentricCalculator calculator(a.position, b.position, c.position);
        auto matrix = calculator.calculate();
        Vector<2, int> min, max;
        min.x = (int)std::min(a.position.x, std::min(b.position.x, c.position.x));
        min.y = (int)std::min(a.position.y, std::min(b.position.y, c.position.y));
        max.x = (int)std::max(a.position.x, std::max(b.position.x, c.position.x));
        max.y = (int)std::max(a.position.y, std::max(b.position.y, c.position.y));
        std::vector<Fragment> result;
        for (int x = min.x; x < max.x; x++) {
            for (int y = min.y; y < max.y; y++) {
                auto barycentric = matrix * Vector<3, double>(1., (double)x, (double)y);
                if (barycentric.x >= 0. && barycentric.y >= 0. && barycentric.z >= 0.) {
                    Fragment fragment;
                    auto depths = Vector<3, double>(a.position.z, b.position.z, c.position.z);
                    auto bcDepths = barycentric * depths;
                    auto z = (int)(bcDepths.x + bcDepths.y + bcDepths.z);
                    fragment.position() = Vector<3, int>(x, y, z);
                    fragment.worldPosition() = (a.worldPosition * barycentric.x + b.worldPosition * barycentric.y +
                            c.worldPosition * barycentric.z);
                    auto textureXs = Vector<3, double>(a.texture.x, b.texture.x, c.texture.x);
                    auto bcTextureXs = barycentric * textureXs;
                    fragment.texture().x = bcTextureXs.x + bcTextureXs.y + bcTextureXs.z;
                    auto textureYs = Vector<3, double>(a.texture.y, b.texture.y, c.texture.y);
                    auto bcTextureYs = barycentric * textureYs;
                    fragment.texture().y = bcTextureYs.x + bcTextureYs.y + bcTextureYs.z;
                    fragment.normal() = (a.normal * barycentric.x + b.normal *
                            barycentric.y + c.normal * barycentric.z).normalize();
                    result.push_back(fragment);
                }
            }
        }
        return result;
    };
};


