//
// Created by daniil on 16.02.2022.
//

#pragma once

#include "mathematics.h"

class Color : public Vector<3, double> {
public:
    Color() = default;
    Color(double red, double green, double blue) : Vector<3, double>(red, green, blue) {};
    [[nodiscard]] double& red() {return x;};
    [[nodiscard]] double red() const {return x;};
    [[nodiscard]] double& green() {return y;};
    [[nodiscard]] double green() const {return y;};
    [[nodiscard]] double& blue() {return z;};
    [[nodiscard]] double blue() const {return z;};
};


