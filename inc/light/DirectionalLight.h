//
// Created by daniil on 17.02.2022.
//

#pragma once

#include "Color.h"
#include "mathematics.h"

class DirectionalLight {
private:
    double _intensity = 1.;
    Color _color = {1., 1., 1.};
    Vector<3, double> _direction;
public:
    explicit DirectionalLight(double intensity, const Vector<3, double>& direction)
    : _intensity(intensity), _direction(direction) {};
    [[nodiscard]] Color& color() {return _color;};
    [[nodiscard]] const Color& color() const {return _color;};
    [[nodiscard]] double& intensity() {return _intensity;};
    [[nodiscard]] double intensity() const {return _intensity;};
    [[nodiscard]] Vector<3, double>& direction() {return _direction;};
    [[nodiscard]] const Vector<3, double>& direction() const {return _direction;};
};


