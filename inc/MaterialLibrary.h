//
// Created by daniil on 25.02.2022.
//

#pragma once

#include "Material.h"

class MaterialLibrary {
public:
    Material ruby;
    Material pearl;
    Material turquoise;
    Material emerald;
    MaterialLibrary() {
        ruby.ambient() = {0.1745, 0.01175, 0.01175};
        ruby.diffuse() = {0.61424, 0.04136, 0.04136};
        ruby.specular() = {0.727811, 0.626959, 0.626959};
        ruby.shininess() = 0.6;
        turquoise.ambient() = {0.1, 0.18725, 0.1745};
        turquoise.diffuse() = {0.396, 0.74151, 0.69102};
        turquoise.specular() = {0.297254, 0.30829, 0.306678};
        turquoise.shininess() = 0.1;
        pearl.ambient() = {0.25, 0.20725, 0.20725};
        pearl.diffuse() = {1, 0.829, 0.829};
        pearl.specular() = {0.296648, 0.296648, 0.296648};
        pearl.shininess() = 0.088;
        emerald.ambient() = {0.0215, 0.1745, 0.0215};
        emerald.diffuse() = {0.07568, 0.61424, 0.07568};
        emerald.specular() = {0.633, 0.727811, 0.633};
        emerald.shininess() = 0.6;
    }
};


