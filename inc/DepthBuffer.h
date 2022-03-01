//
// Created by daniil on 16.02.2022.
//

#pragma once

#include "visual/Viewport.h"
#include "Fragment.h"
#include <vector>

class DepthBuffer {
private:
    std::vector<int> _buffer;
    int _minDepth = 0;
    int _width = 0;
public:
    explicit DepthBuffer(Viewport viewport) {
        _width = viewport.width();
        _buffer.resize(viewport.width() * viewport.height());
        _minDepth = viewport.nearDepth();
        std::fill(_buffer.begin(), _buffer.end(), viewport.farDepth());
    }
    [[nodiscard]] bool test(const Fragment& fragment) {
        if (fragment.position().z < _buffer[fragment.position().y * _width + fragment.position().x] &&
        fragment.position().z >= _minDepth) {
            _buffer[fragment.position().y * _width + fragment.position().x] = fragment.position().z;
            return true;
        }
        return false;
    }
};


