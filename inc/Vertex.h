//
// Created by daniil on 15.02.2022.
//

#pragma once

#include "mathematics.h"

class Vertex {
public:
    Vector<3, double> position = Vector<3, double>(0., 0., 0.);
    Vector<3, double> worldPosition = Vector<3, double>(0., 0., 0.);
    Vector<2, double> texture = Vector<2, double>(0., 0.);
    Vector<3, double> normal = Vector<3, double>(0., 0., 0.);
};
