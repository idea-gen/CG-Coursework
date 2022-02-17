//
// Created by daniil on 16.02.2022.
//

#pragma once

#include "mathematics.h"

class Fragment {
private:
    Vector<3, int> _position;
public:
    [[nodiscard]] Vector<3, int>& position() {return _position;};
    [[nodiscard]] Vector<3, int> position() const {return _position;};
};

