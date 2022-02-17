//
// Created by daniil on 15.02.2022.
//

#pragma once

#include <utility>

#include "Renderable.h"
#include "visual/Camera.h"

class Scene {
private:
    std::vector<Renderable> _renderables;
    Camera _camera;
public:
    Scene() = default;
    explicit Scene(Camera camera) : _camera(std::move(camera)) {};
    [[nodiscard]] std::vector<Renderable>& renderables() {return _renderables;};
    [[nodiscard]] std::vector<Renderable> renderables() const {return _renderables;};
    [[nodiscard]] Camera& camera() {return _camera;};
    [[nodiscard]] const Camera& camera() const {return _camera;};
};


