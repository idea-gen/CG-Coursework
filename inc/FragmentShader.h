//
// Created by daniil on 16.02.2022.
//

#pragma once

#include "Fragment.h"
#include "Color.h"

class FragmentShader {
private:
    Fragment _fragment;
public:
    explicit FragmentShader(Fragment fragment) : _fragment(fragment) {};
    [[nodiscard]] Color execute() const {
        return {200, 0, 0};
    }
};


