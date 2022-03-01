//
// Created by daniil on 15.02.2022.
//

#pragma once

#include "Color.h"
#include <memory>

class IPixelReceiver {
public:
    [[nodiscard]] virtual int height() const = 0;
    [[nodiscard]] virtual int width() const = 0;
    virtual std::shared_ptr<IPixelReceiver> createCopy() const = 0;
    virtual void setPixelColor(int x, int y, Color color) = 0;
    virtual Color pixelColor(int x, int y) const = 0;
    virtual void* data() = 0;
};


