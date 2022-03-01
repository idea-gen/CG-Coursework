//
// Created by daniil on 16.02.2022.
//

#pragma once

#include "IPixelReceiver.h"
#include <QImage>

class PixelReceiver : public IPixelReceiver {
private:
    QImage* _image = nullptr;
public:
    PixelReceiver(int width, int height) {
        _image = new QImage(width, height, QImage::Format_ARGB32);
        _image->fill(QColor("black"));
    }
    PixelReceiver(const PixelReceiver& other) : _image(new QImage(other._image->copy())) {};
    [[nodiscard]] int width() const override {return _image->width();};
    [[nodiscard]] int height() const override {return _image->height();};

    [[nodiscard]] std::shared_ptr<IPixelReceiver> createCopy() const override {
        return std::make_shared<PixelReceiver>(*this);
    }

    [[nodiscard]] Color pixelColor(int x, int y) const override {
        auto color = _image->pixelColor(x, y);
        return {color.redF(), color.greenF(), color.blueF()};
    }

    void setPixelColor(int x, int y, Color color) override {
        if (color.red() < 0. || color.green() < 0. || color.blue() < 0. ||
                color.red() > 1. || color.green() > 1. || color.blue() > 1.)
            return;
        if (!_image->valid(x, y))
            return;
        QColor qColor((int)(254 * color.red()), (int)(254 * color.green()), (int)(254 * color.blue()), 255);
        if (!qColor.isValid())
            return;
        _image->setPixelColor(x, y, qColor);
    };
    void* data() override {return _image;};
};


