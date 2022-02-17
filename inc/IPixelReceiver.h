//
// Created by daniil on 15.02.2022.
//

#pragma once

#include "Color.h"

class IPixelReceiver {
public:
    [[nodiscard]] virtual int height() const = 0;
    [[nodiscard]] virtual int width() const = 0;
    virtual void setPixelColor(int x, int y, Color color) = 0;
    virtual void* data() = 0;
};


