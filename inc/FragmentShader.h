//
// Created by daniil on 16.02.2022.
//

#pragma once

#include <utility>

#include "Fragment.h"
#include "Lights.h"
#include "Material.h"

class FragmentShader {
private:
    Fragment _fragment;
    static Material _material;
    static Lights _lights;
    static Vector<3, double> _faceNormal;
public:
    explicit FragmentShader(Fragment fragment) : _fragment(std::move(fragment)) {};
    static void SetFaceNormal(const Vector<3, double>& normal) {_faceNormal = normal;};
    static void SetLights(Lights lights) {_lights = std::move(lights);};
    static void SetMaterial(Material material) {_material = std::move(material);};
    [[nodiscard]] Color execute() {
        Color result = _material.ambient();
//        for (auto ambient : _lights.ambient()) {
//
//        }
        for (auto light : _lights.directional()) {
            auto faceReflectionIntensity = std::max(scalarProduct(light.direction(), _faceNormal), 0.);
            auto directColor = light.color() * faceReflectionIntensity * light.intensity();
            auto diffuseColor = directColor * _material.diffuse();
            result += diffuseColor;
        }
        if (_faceNormal.y == -1.) {
            int a = 5;
        }
        for (auto light : _lights.point()) {
            auto lightPointingVector = light.position() - _fragment.worldPosition();
            auto distance = (lightPointingVector).length();
            auto directColor = light.color() * light.intensity(distance);
            auto diffuseColor = directColor * _material.diffuse();
            auto lightPointingNormal = lightPointingVector;
            lightPointingNormal.normalize();
            auto fragmentReflectionIntensity = scalarProduct(_fragment.normal(), lightPointingNormal);
            auto highlight = fragmentReflectionIntensity < 0. ? 0. :
                    std::pow(fragmentReflectionIntensity,_material.shininess() * 128.) * light.intensity(distance);
            auto specularColor = (light.color() * _material.specular() * highlight);
            result += diffuseColor + specularColor;
        }
        auto maxComponent = std::max(result.red(), std::max(result.green(), result.blue()));
        if (maxComponent > 1.)
            for (auto& component : result) component /= maxComponent;
        return result;
    }
};


