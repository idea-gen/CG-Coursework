//
// Created by daniil on 15.02.2022.
//

#pragma once

#include "mathematics.h"
#include <cstdlib>
#include "Vertex.h"
#include <array>
#include <utility>

class Primitive {
private:
    std::array<Vertex, 3> _vertices = {};
    Vector<3, double> _normal = Vector<3, double>(0., 0., 0.);

public:
    Primitive() = default;
    Primitive(std::array<Vertex, 3> vertices, const Vector<3, double>& normal)
    : _vertices(std::move(vertices)), _normal(normal) {};
    [[nodiscard]] std::array<Vertex, 3>& vertices() {return _vertices;};
    [[nodiscard]] const std::array<Vertex, 3>& vertices() const {return _vertices;};
    [[nodiscard]] Vector<3, double>& normal() {return _normal;};
    [[nodiscard]] const Vector<3, double>& normal() const {return _normal;};
};


