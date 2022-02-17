//
// Created by daniil on 16.02.2022.
//

#pragma once


class Color {
private:
    int _red = 0;
    int _green = 0;
    int _blue = 0;
    int _alpha = 255;
public:
    Color(int red, int green, int blue) : _red(red), _green(green), _blue(blue) {};
    Color(int red, int green, int blue, int alpha) : _red(red), _green(green), _blue(blue), _alpha(alpha) {};
    [[nodiscard]] int& red() {return _red;};
    [[nodiscard]] int red() const {return _red;};
    [[nodiscard]] int& green() {return _green;};
    [[nodiscard]] int green() const {return _green;};
    [[nodiscard]] int& blue() {return _blue;};
    [[nodiscard]] int blue() const {return _blue;};
    [[nodiscard]] int& alpha() {return _alpha;};
    [[nodiscard]] int alpha() const {return _alpha;};
};


