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
        renderable.vertices().emplace_back(x, y, z);
    };
    auto textureReader = [](std::istringstream iss, Renderable& renderable) {
        double x, y;
        iss >> x >> y;
        renderable.textures().emplace_back(x, y);
    };
    auto normalReader = [](std::istringstream iss, Renderable& renderable) {
        double x, y, z;
        iss >> x >> y >> z;
        renderable.vertexNormals().emplace_back(x, y, z);
    };
    auto faceReader = [](std::istringstream iss, Renderable& renderable) {
        char separator0, separator1;
        auto normalSum = Vector<3, double>(0., 0., 0.);
        int vertexCounter = 0;
        while (!iss.eof()) {
            VertexSpecification specification;
            iss >> specification.vertex >> separator0 >> specification.texture >> separator1 >> specification.normal;
            specification.vertex--; specification.texture--; specification.normal--;
            normalSum = normalSum + renderable.vertexNormals()[specification.normal];
            renderable.vertexSpecifications().push_back(specification);
            vertexCounter++;
        }
        auto faceNormalIndex = 0;
        {
            auto faceNormal = normalSum;
            faceNormal.normalize();
            renderable.faceNormals().push_back(faceNormal);
            faceNormalIndex = renderable.faceNormals().size() - 1;
        }
        auto totalFaceTriangles = vertexCounter - 2;
        auto lastVertex = renderable.vertexSpecifications().size() - 1;
        for (int i = 0; i < totalFaceTriangles; i++) {
            PrimitiveSpecification specification;
            specification.vertices[0] = lastVertex;
            specification.vertices[1] = lastVertex - 1 - i;
            specification.vertices[2] = lastVertex - 2 - i;
//            for (auto counter = 0; auto& vertexIndex : specification.vertices) {
//                vertexIndex = lastVertex - i - counter++;
//            }
            specification.normal = faceNormalIndex;
            renderable.primitiveSpecifications().push_back(specification);
        }
    };
    _actions["v"] = vertexReader;
    _actions["vt"] = textureReader;
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
