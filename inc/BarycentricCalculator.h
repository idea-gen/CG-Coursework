//
// Created by daniil on 18.02.2022.
//

#pragma once

#include "mathematics.h"
#include "Vertex.h"
#include <array>
#include <utility>

class BarycentricCalculator {
private:
    Vector<3, double> _a;
    Vector<3, double> _b;
    Vector<3, double> _c;
public:
    explicit BarycentricCalculator(const Vector<3, double>& a, const Vector<3, double>& b, const Vector<3, double>& c)
    : _a(a), _b(b), _c(c) {};
    [[nodiscard]] Matrix<3, 3, double> calculate() const {
        auto divisor = _a.x * (_b.y - _c.y) + _b.x * (_c.y - _a.y) + _c.x * (_a.y - _b.y);
        return Matrix<3, 3, double>(
                _b.x * _c.y - _c.x * _b.y, _b.y - _c.y, _c.x - _b.x,
                _c.x * _a.y - _a.x * _c.y, _c.y - _a.y, _a.x - _c.x,
                _a.x * _b.y - _b.x * _a.y, _a.y - _b.y, _b.x - _a.x) / divisor;
    }
};


