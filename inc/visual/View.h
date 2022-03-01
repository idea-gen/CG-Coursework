//
// Created by daniil on 16.02.2022.
//

#pragma once

#include "transform/PositionTransform.h"
#include "transform/RotationTransform.h"

class View {
private:
    PositionTransform _position;
    RotationTransform _rotation;
public:
    View() {
        _position = PositionTransform();
        _rotation = RotationTransform();
    };
    [[nodiscard]] PositionTransform& position() {return _position;};
    [[nodiscard]] PositionTransform position() const {return _position;};
    [[nodiscard]] RotationTransform& rotation() {return _rotation;};
    [[nodiscard]] Matrix<4, 4, double> matrix() const {
        return _rotation.matrix() * _position.matrix();
    };
};


