//
// Created by daniil on 15.02.2022.
//

#pragma once

#include <utility>

#include "View.h"
#include "FieldOfView.h"
#include "Viewport.h"

class Camera {
private:
    View _view;
    FieldOfView _fieldOfView;
    Viewport _viewport;
public:
    Camera() = default;
    Camera(View view, FieldOfView fieldOfView, Viewport viewport)
    : _view(std::move(view)), _fieldOfView(fieldOfView), _viewport(viewport) {};
    [[nodiscard]] View& view() {return _view;};
    [[nodiscard]] const View& view() const {return _view;};
    [[nodiscard]] FieldOfView& fieldOfView() {return _fieldOfView;};
    [[nodiscard]] FieldOfView fieldOfView() const {return _fieldOfView;};
    [[nodiscard]] Viewport& viewport() {return _viewport;};
    [[nodiscard]] Viewport viewport() const {return _viewport;};

};


