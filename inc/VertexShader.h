//
// Created by daniil on 15.02.2022.
//

#pragma once

#include "mathematics.h"
#include "Vertex.h"

class VertexShader {
private:
    Vector<3, double> _vertex;
    static Matrix<4, 4, double> _model;
    static Matrix<4, 4, double> _view;
    static Matrix<4, 4, double> _projection;
    static Matrix<4, 4, double> _viewport;
    static Matrix<4, 4, double> _mvpv;
    static void UpdateMvpv() {
        _mvpv = _viewport * _projection * _view * _model;
    }
public:
    explicit VertexShader(const Vector<3, double>& vertex) : _vertex(vertex) {};
    [[nodiscard]] Vector<3, double> execute() const {
        auto homogeneous = Vector<4, double>(_vertex, 1);
        homogeneous = _model * homogeneous;
        homogeneous = _view * homogeneous;
        homogeneous = _projection * homogeneous;
        auto perspectiveDivisor = std::abs(homogeneous.w);
        for (auto& coordinate : homogeneous) coordinate /= perspectiveDivisor;
        homogeneous = _viewport * homogeneous;
        return Vector<3, double>(homogeneous.x,
                                 homogeneous.y,
                                 homogeneous.z);
        //auto homogeneous = _mvpv * Vector<4, double>(_vertex, 1);
        //return Vector<3, double>(homogeneous.x / homogeneous.w,
        //                         homogeneous.y / homogeneous.w,
        //                         homogeneous.z / homogeneous.w);
    };
    static void SetModelMatrix(Matrix<4, 4, double> matrix) {_model = matrix;};
    static void SetViewMatrix(Matrix<4, 4, double> matrix) {_view = matrix;};
    static void SetProjectionMatrix(Matrix<4, 4, double> matrix) {_projection = matrix;};
    static void SetViewportMatrix(Matrix<4, 4, double> matrix) {_viewport = matrix;};
};


