//
// Created by daniil on 16.02.2022.
//

#pragma once

#include "mathematics.h"

class ScaleTransform {
private:
    Vector<3, double> _scale;
    Matrix<4, 4, double> _matrix = Matrix<4, 4, double>::Identity();
public:
    ScaleTransform() = default;
    [[nodiscard]] const Matrix<4, 4, double>& matrix() const {return _matrix;};
};


