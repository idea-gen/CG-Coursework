//
// Created by daniil on 16.02.2022.
//

#pragma once

#include "mathematics.h"
#include "RotationTransform.h"

class DirectionTransform : public RotationTransform {
private:
    Vector<3, double> _direction;
public:
    DirectionTransform() : RotationTransform() {};
};


