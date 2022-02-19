//
// Created by daniil on 17.02.2022.
//

#pragma once

#include "mathematics.h"

class BackfaceCuller {
private:
    Vector<3, double> _normal;
    static Matrix<4, 4, double> _model;
    static Matrix<4, 4, double> _view;
    static Matrix<4, 4, double> _matrix;
    static void updateMatrix() {
        _matrix = _view * _model;
    }
public:
    explicit BackfaceCuller(const std::array<Vector<3, double>, 3>& normals)
    : _normal((normals[0] + normals[1] + normals[2]).normalize()) {};
    bool cull() {
        auto homogeneous = Vector<4, double>(_normal, 0.);
        homogeneous = _matrix * homogeneous;
        auto viewNormal = Vector<3, double>(homogeneous.x, homogeneous.y, homogeneous.z);
        return scalarProduct(viewNormal, Vector<3, double>(0., 0., 1.)) > 0;
    }
    static void SetModelMatrix(Matrix<4, 4, double> matrix) {_model = matrix; updateMatrix();};
    static void SetViewMatrix(Matrix<4, 4, double> matrix) {_view = matrix; updateMatrix();};
};


