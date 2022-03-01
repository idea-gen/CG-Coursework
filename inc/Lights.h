//
// Created by daniil on 17.02.2022.
//

#pragma once

#include "light/DirectionalLight.h"
#include "light/PointLight.h"
#include "light/SpotLight.h"
#include <vector>

class Lights {
private:
    std::vector<DirectionalLight> _directionalLights;
    std::vector<PointLight> _pointLights;
    std::vector<SpotLight> _spotLights;
public:
    [[nodiscard]] std::vector<DirectionalLight>& directional() {return _directionalLights;};
    [[nodiscard]] const std::vector<DirectionalLight>& directional() const {return _directionalLights;};
    [[nodiscard]] std::vector<PointLight>& point() {return _pointLights;};
    [[nodiscard]] const std::vector<PointLight>& point() const {return _pointLights;};
    [[nodiscard]] std::vector<SpotLight>& spot() {return _spotLights;};
    [[nodiscard]] const std::vector<SpotLight>& spot() const {return _spotLights;};
};


