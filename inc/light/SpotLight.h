//
// Created by daniil on 17.02.2022.
//

#pragma once

#include "Color.h"
#include "SceneEntity.h"
#include "mathematics.h"

class SpotLight : public SceneEntity {
private:
    double _intensity = 1.;
    Color _color = {255, 255, 255};
    Vector<3, double> _position;
    Vector<3, double> _direction;
    double _constantAttenuation = 1.;
    double _linearAttenuation = .8;
public:
    explicit SpotLight(const Vector<3, double>& position, const Vector<3, double>& direction)
            : _position(position), _direction(direction) {};
    [[nodiscard]] Color& color() {return _color;};
    [[nodiscard]] const Color& color() const {return _color;};
    [[nodiscard]] double& intensity() {return _intensity;};
    [[nodiscard]] double intensity() const {return _intensity;};
    [[nodiscard]] double intensity(double distance) const
    {return _intensity / (_constantAttenuation + _linearAttenuation * distance);};
    [[nodiscard]] Vector<3, double>& position() {return _position;};
    [[nodiscard]] const Vector<3, double>& position() const {return _position;};
    [[nodiscard]] Vector<3, double>& direction() {return _direction;};
    [[nodiscard]] const Vector<3, double>& direction() const {return _direction;};
};


