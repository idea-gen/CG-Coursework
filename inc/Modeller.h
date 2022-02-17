//
// Created by daniil on 04.12.2021.
//

#pragma once

#include "mathematics.h"
#include "Renderable.h"
#include <functional>
#include <vector>
#include <map>


class Modeller {
private:
    Renderable _cylinder;
    Renderable _pyramid;
    Renderable _cube;
    Renderable _cone;
    const std::string _cylinderPath = "/cylinder.obj";
    const std::string _pyramidPath = "/pyramid.obj";
    const std::string _cubePath = "/cube.obj";
    const std::string _conePath = "/cone.obj";
    std::map<std::string, std::function<void(std::istringstream, Renderable&)>> _actions;
    Renderable readModel(std::ifstream file);
public:
    Modeller();
    void init(const std::string& objFolder);
    Renderable getCylinder() {return _cylinder;};
    Renderable getPyramid() {return _pyramid;};
    Renderable getCube() {return _cube;};
    Renderable getCone() {return _cube;};
};
