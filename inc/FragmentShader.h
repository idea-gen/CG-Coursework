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
            auto reflectionIntensity = std::max(-scalarProduct(light.direction(), _fragment.normal()), 0.);
            if (reflectionIntensity < 0.0005)
                continue;
            auto directColor = light.color() * reflectionIntensity;
            auto diffuseColor = directColor * _material.diffuse();
            auto highlight = std::pow(reflectionIntensity,_material.shininess() * 128.) * light.intensity();
            auto specularColor = light.color() * _material.specular() * highlight;
            result += diffuseColor + specularColor;
        }
        for (auto light : _lights.point()) {
            auto lightPointingVector = _fragment.worldPosition() - light.position();
            auto lightPointingNormal = lightPointingVector;
            lightPointingNormal.normalize();
            auto reflectionIntensity = std::max(-scalarProduct(lightPointingNormal, _fragment.normal()), 0.);
            if (reflectionIntensity < 0.0005)
                continue;
            auto distance = (lightPointingVector).length();
            auto lightIntensity = light.intensity(distance);
            auto directColor = light.color() * lightIntensity * reflectionIntensity;
            auto diffuseColor = directColor * _material.diffuse();
            auto highlight = std::pow(reflectionIntensity,_material.shininess() * 128.) * lightIntensity;
            auto specularColor = light.color() * _material.specular() * highlight;
            result += diffuseColor + specularColor;
        }
        for (auto light : _lights.spot()) {
            auto lightPointingVector = light.position() - _fragment.worldPosition();
            auto lightPointingNormal = lightPointingVector;
            lightPointingNormal.normalize();
            auto reflectionIntensity = std::max(-scalarProduct(light.direction(), _fragment.normal()), 0.);
            reflectionIntensity *= std::max(-scalarProduct(light.direction(), lightPointingNormal), 0.);
            if (reflectionIntensity < 0.0005)
                continue;
            auto distance = (lightPointingVector).length();
            auto lightIntensity = light.intensity(distance);
            auto directColor = light.color() * lightIntensity * reflectionIntensity;
            auto diffuseColor = directColor * _material.diffuse();
            auto highlight = std::pow(reflectionIntensity,_material.shininess() * 128.) * lightIntensity;
            auto specularColor = light.color() * _material.specular() * highlight;
            result += diffuseColor + specularColor;
        }
        auto maxComponent = std::max(result.red(), std::max(result.green(), result.blue()));
        if (maxComponent > 1.)
            for (auto& component : result) component /= maxComponent;
        return result;
    }
};


