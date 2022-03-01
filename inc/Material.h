//
// Created by daniil on 19.02.2022.
//

#pragma once

#include "Color.h"

/**
 * @note VRML material
 */
class Material {
private:
    Color _ambient;
    Color _diffuse;
    Color _specular;
    double _shininess = 0.;
public:
    [[nodiscard]] Color& ambient() {return _ambient;};
    [[nodiscard]] const Color& ambient() const {return _diffuse;};
    [[nodiscard]] Color& diffuse() {return _diffuse;};
    [[nodiscard]] const Color& diffuse() const {return _diffuse;};
    [[nodiscard]] Color& specular() {return _specular;};
    [[nodiscard]] const Color& specular() const {return _specular;};
    [[nodiscard]] double& shininess() {return _shininess;};
    [[nodiscard]] double shininess() const {return _shininess;};
};


