//
// Created by daniil on 15.02.2022.
//

#pragma once

#include "mathematics.h"

class Viewport {
private:
    int _width = 500.;
    int _height = 500.;
    int _width0 = 0.;
    int _height0 = 0.;
    int _nearDepth = 0.;
    int _farDepth = 1000.;
    Matrix<4, 4, double> _matrix = Matrix<4, 4, double>::Identity();
    void updateMatrix() {
        auto w = (double)_width;
        auto h = (double)_height;
        auto w0 = (double)_width0;
        auto h0 = (double)_height0;
        auto n = (double)_nearDepth;
        auto f = (double)_farDepth;
        _matrix = Matrix<4, 4, double>(
                w / 2., 0., 0., w0 + w / 2.,
                0., h / 2., 0., h0 + h / 2.,
                0., 0., (f - n) / 2., (f + n) / 2.,
                0., 0., 0., 1.);
    };
public:
    Viewport() {
        updateMatrix();
    };
    Viewport(int width, int height) : _width(width), _height(height) {};
    [[nodiscard]] int width() const {return _width;};
    void setWidth(int width) {_width = width;};
    [[nodiscard]] int height() const {return _height;};
    void setHeight(int height) {_height = height;};
    [[nodiscard]] int width0() const {return _width0;};
    [[nodiscard]] int height0() const {return _height0;};
    [[nodiscard]] int nearDepth() const {return _nearDepth;};
    [[nodiscard]] int farDepth() const {return _farDepth;};
    [[nodiscard]] Matrix<4, 4, double> matrix() const {return _matrix;};
};


