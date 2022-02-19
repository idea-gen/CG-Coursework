//
// Created by daniil on 17.02.2022.
//

#pragma once

#include "Color.h"
#include "mathematics.h"

class SpotLight {
private:
    double _intensity = 0.;
    Color _color = {255, 255, 255};
    Vector<3, double> _position;
    Vector<3, double> _direction;
public:
    explicit SpotLight(double intensity, const Vector<3, double>& position, const Vector<3, double>& direction)
            : _intensity(intensity), _position(position), _direction(direction) {};
    [[nodiscard]] Color& color() {return _color;};
    [[nodiscard]] const Color& color() const {return _color;};
    [[nodiscard]] double& intensity() {return _intensity;};
    [[nodiscard]] double intensity() const {return _intensity;};
    [[nodiscard]] Vector<3, double>& position() {return _position;};
    [[nodiscard]] const Vector<3, double>& position() const {return _position;};
    [[nodiscard]] Vector<3, double>& direction() {return _direction;};
    [[nodiscard]] const Vector<3, double>& direction() const {return _direction;};
};


