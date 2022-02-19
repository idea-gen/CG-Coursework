//
// Created by daniil on 17.02.2022.
//

#pragma once

#include "Color.h"
#include "mathematics.h"

class PointLight {
private:
    double _intensity = 1.;
    Color _color = {1., 1., 1.};
    Vector<3, double> _position;
    double _constantAttenuation = 1.;
    double _linearAttenuation = .2;
public:
    explicit PointLight(double intensity, const Vector<3, double>& position)
            : _intensity(intensity), _position(position) {};
    [[nodiscard]] Color& color() {return _color;};
    [[nodiscard]] const Color& color() const {return _color;};
    [[nodiscard]] double& intensity() {return _intensity;};
    [[nodiscard]] double intensity() const {return _intensity;};
    [[nodiscard]] double intensity(double distance) const
    {return _intensity / (_constantAttenuation + _linearAttenuation * distance);};
    [[nodiscard]] Vector<3, double>& position() {return _position;};
    [[nodiscard]] const Vector<3, double>& position() const {return _position;};
};


