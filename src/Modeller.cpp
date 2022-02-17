//
// Created by daniil on 04.12.2021.
//

#include "Modeller.h"
#include <string>
#include <sstream>
#include <fstream>

Modeller::Modeller() {
    auto vertexReader = [](std::istringstream iss, Renderable& renderable) {
        double x, y, z;
        iss >> x >> y >> z;
        renderable.geometricVertices().push_back(Vector<3, double>(x, y, z));
    };
    auto normalReader = [](std::istringstream iss, Renderable& renderable) {
        double x, y, z;
        iss >> x >> y >> z;
        renderable.normals().push_back(Vector<3, double>(x, y, z));
    };
    auto faceReader = [](std::istringstream iss, Renderable& renderable) {
        int vertex0, vertex1, vertex2, faceNormal;
        iss >> vertex0 >> vertex1 >> vertex2 >> faceNormal;
        vertex0--; vertex1--; vertex2--; faceNormal--;
        renderable.primitiveSpecifications()
        .push_back({{vertex0, vertex1, vertex2}, faceNormal});
    };
    _actions["v"] = vertexReader;
    _actions["vn"] = normalReader;
    _actions["f"] = faceReader;
}

void Modeller::init(const std::string& objFolder) {
    {// cylinder reading
        std::ifstream cylinderFile(objFolder + _cylinderPath);
        if (cylinderFile.fail())
            throw std::runtime_error("Failed to open cylinder file");
        _cylinder = readModel(std::move(cylinderFile));
    }
    {// pyramid reading
        std::ifstream pyramidFile(objFolder + _pyramidPath);
        if (pyramidFile.fail())
            throw std::runtime_error("failed to open pyramid file");
        _pyramid = readModel(std::move(pyramidFile));
    }
    {// cube reading
        std::ifstream cubeFile(objFolder + _cubePath);
        if (cubeFile.fail())
            throw std::runtime_error("Failed to open cube file");
        _cube = readModel(std::move(cubeFile));
    }
    {// cone reading
        std::ifstream coneFile(objFolder + _conePath);
        if (coneFile.fail())
            throw std::runtime_error("Failed to open cone file");
        _cone = readModel(std::move(coneFile));
    }
}

Renderable Modeller::readModel(std::ifstream file) {
    Renderable model;
    for (std::string data; std::getline(file, data);) {
        if (data.empty())
            continue;
        std::istringstream iss(data.c_str());
        std::string dataType;
        iss >> dataType;
        if (_actions.contains(dataType))
            _actions[dataType](std::move(iss), model);
    }
    return model;
}
