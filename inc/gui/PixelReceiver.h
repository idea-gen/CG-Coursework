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
    [[nodiscard]] int width() const override {return _image->width();};
    [[nodiscard]] int height() const override {return _image->height();};
    void setPixelColor(int x, int y, Color color) override {
        QColor qColor(color.red(), color.green(), color.blue(), color.alpha());
        _image->setPixelColor(x, y, qColor);
    };
    void* data() override {return _image;};
};


