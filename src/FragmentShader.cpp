//
// Created by daniil on 16.02.2022.
//

#include "FragmentShader.h"

Lights FragmentShader::_lights = Lights();
Material FragmentShader::_material = Material();
Vector<3, double> FragmentShader::_faceNormal = Vector<3, double>(0., 0., 1.);
