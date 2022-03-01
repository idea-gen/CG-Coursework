//
// Created by daniil on 16.02.2022.
//

#pragma once

#include "mathematics.h"

class Fragment {
private:
    Vector<3, int> _position;
    Vector<3, double> _worldPosition;
    Vector<2, double> _texture;
    Vector<3, double> _normal;
public:
    [[nodiscard]] Vector<3, int>& position() {return _position;};
    [[nodiscard]] Vector<3, int> position() const {return _position;};
    [[nodiscard]] Vector<3, double>& worldPosition() {return _worldPosition;};
    [[nodiscard]] Vector<3, double> worldPosition() const {return _worldPosition;};
    [[nodiscard]] Vector<2, double>& texture() {return _texture;};
    [[nodiscard]] Vector<2, double> texture() const {return _texture;};
    [[nodiscard]] Vector<3, double>& normal() {return _normal;};
    [[nodiscard]] Vector<3, double> normal() const {return _normal;};
};

