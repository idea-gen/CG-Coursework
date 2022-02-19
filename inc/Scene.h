//
// Created by daniil on 15.02.2022.
//

#pragma once

#include "Renderable.h"
#include "visual/Camera.h"
#include "Lights.h"
#include <utility>

class Scene {
private:
    std::vector<Renderable> _renderables;
    Camera _camera;
    Lights _lights;
public:
    Scene() = default;
    explicit Scene(Camera camera) : _camera(std::move(camera)) {};
    [[nodiscard]] std::vector<Renderable>& renderables() {return _renderables;};
    [[nodiscard]] std::vector<Renderable> renderables() const {return _renderables;};
    [[nodiscard]] Camera& camera() {return _camera;};
    [[nodiscard]] const Camera& camera() const {return _camera;};
    [[nodiscard]] Lights& lights() {return _lights;};
    [[nodiscard]] const Lights& lights() const {return _lights;};
};


