//
// Created by daniil on 16.02.2022.
//

#pragma once

#include "mathematics.h"

class PositionTransform {
protected:
    Vector<3, double> _position;
    Matrix<4, 4, double> _matrix = Matrix<4, 4, double>(
            1., 0., 0., 0.,
            0., 1., 0., 0.,
            0., 0., 1., 0.,
            0., 0., 0., 1.);
    void updateMatrix() {
        _matrix = Matrix<4, 4, double>(
                1., 0., 0., _position.x,
                0., 1., 0., _position.y,
                0., 0., 1., _position.z,
                0., 0., 0., 1.);
    }
public:
    PositionTransform() = default;
    void set(const Vector<3, double>& position) {
        _position = position;
        updateMatrix();
    }
    [[nodiscard]] const Matrix<4, 4, double>& matrix() const {
        return _matrix;
    }
};


