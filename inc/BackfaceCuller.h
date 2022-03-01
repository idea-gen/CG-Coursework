//
// Created by daniil on 17.02.2022.
//

#pragma once

#include "mathematics.h"
#include "Primitive.h"

class BackfaceCuller {
private:
    Primitive _primitive;
    static Matrix<4, 4, double> _model;
    static Matrix<4, 4, double> _view;
    static Matrix<4, 4, double> _matrix;
    static void updateMatrix() {
        _matrix = _view * _model;
    }
public:
    explicit BackfaceCuller(Primitive& primitive) : _primitive(primitive) {};
    bool cull() {
        auto hNormal = _matrix * Vector<4, double>(_primitive.normal(), 0.);
        auto avgVertex = (_primitive.vertices()[0].worldPosition +
                _primitive.vertices()[1].worldPosition +
                _primitive.vertices()[2].worldPosition) / 3.;
        auto hVertex = _view * Vector<4, double>(avgVertex, 1.);
        return scalarProduct(hNormal, hVertex) > 0;
    }
    static void SetModelMatrix(Matrix<4, 4, double> matrix) {_model = matrix; updateMatrix();};
    static void SetViewMatrix(Matrix<4, 4, double> matrix) {_view = matrix; updateMatrix();};
};


