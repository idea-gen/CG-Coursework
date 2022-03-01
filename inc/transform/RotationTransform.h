//
// Created by daniil on 16.02.2022.
//

#pragma once

#include "mathematics.h"

class RotationTransform {
private:
    Vector<3, double> _rotation = Vector<3, double>(0., 0., 0.);
    Matrix<4, 4, double> _xMatrix = Matrix<4, 4, double>::Identity();
    Matrix<4, 4, double> _xInvMatrix = Matrix<4, 4, double>::Identity();
    Matrix<4, 4, double> _yMatrix = Matrix<4, 4, double>::Identity();
    Matrix<4, 4, double> _yInvMatrix = Matrix<4, 4, double>::Identity();
    Matrix<4, 4, double> _zMatrix = Matrix<4, 4, double>::Identity();
    Matrix<4, 4, double> _zInvMatrix = Matrix<4, 4, double>::Identity();
    Matrix<4, 4, double> _matrix = Matrix<4, 4, double>::Identity();
    Matrix<4, 4, double> _invMatrix = Matrix<4, 4, double>::Identity();
    void updateMatrix() {
        _matrix = _xMatrix * _yMatrix * _zMatrix;
        _invMatrix = _xInvMatrix * _yInvMatrix * _zInvMatrix;
    }
public:
    RotationTransform() {
        _xMatrix = Matrix<4, 4, double>::Identity();
        _yMatrix = Matrix<4, 4, double>::Identity();
        _zMatrix = Matrix<4, 4, double>::Identity();
        _matrix = Matrix<4, 4, double>::Identity();
    };
    void rotateX(double angle) {
        _rotation.x += angle;
        auto radians = _rotation.x * M_PI / 180.;
        _xMatrix = Matrix<4, 4, double>(
                1., 0., 0., 0.,
                0., std::cos(radians), std::sin(radians), 0.,
                0., -std::sin(radians), std::cos(radians), 0.,
                0., 0., 0., 1.);
        _xInvMatrix = Matrix<4, 4, double>(
                1., 0., 0., 0.,
                0., std::cos(radians), -std::sin(radians), 0.,
                0., std::sin(radians), std::cos(radians), 0.,
                0., 0., 0., 1.);
        updateMatrix();
    }
    void rotateY(double angle) {
        _rotation.y += angle;
        auto radians = _rotation.y * M_PI / 180.;
        _yMatrix = Matrix<4, 4, double>(
                std::cos(radians), 0., std::sin(radians), 0.,
                0., 1., 0., 0.,
                -std::sin(radians), 0., std::cos(radians), 0.,
                0., 0., 0., 1.);
        _yInvMatrix = Matrix<4, 4, double>(
                std::cos(radians), 0., -std::sin(radians), 0.,
                0., 1., 0., 0.,
                std::sin(radians), 0., std::cos(radians), 0.,
                0., 0., 0., 1.);
        updateMatrix();
    }
    [[nodiscard]] const Matrix<4, 4, double>& matrix() const {return _matrix;};
    [[nodiscard]] const Matrix<4, 4, double>& invMatrix() const {return _invMatrix;};
};


