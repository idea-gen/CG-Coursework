//
// Created by daniil on 15.02.2022.
//

#pragma once

#include "mathematics.h"
#include "transform/PositionTransform.h"
#include "transform/RotationTransform.h"
#include "transform/ScaleTransform.h"
#include "Vertex.h"
#include "VertexSpecification.h"
#include "PrimitiveSpecification.h"
#include <vector>

class Renderable {
private:
    std::vector<Vector<3, double>> _geometricVertices;
    std::vector<Vector<3, double>> _normals;
    std::vector<VertexSpecification> _vertexSpecifications;
    std::vector<PrimitiveSpecification> _primitiveSpecifications;
    PositionTransform _position;
    RotationTransform _rotation;
    ScaleTransform _scale;
public:
    [[nodiscard]] std::vector<Vector<3, double>>& geometricVertices() {return _geometricVertices;};
    [[nodiscard]] std::vector<Vector<3, double>> geometricVertices() const {return _geometricVertices;};
    [[nodiscard]] std::vector<Vector<3, double>>& normals() {return _normals;};
    [[nodiscard]] std::vector<Vector<3, double>> normals() const {return _normals;};
    [[nodiscard]] std::vector<PrimitiveSpecification>& primitiveSpecifications()
    {return _primitiveSpecifications;};
    [[nodiscard]] std::vector<PrimitiveSpecification> primitiveSpecifications() const
    {return _primitiveSpecifications;};
    [[nodiscard]] Matrix<4, 4, double> matrix() const
    {return _position.matrix() * _rotation.matrix() * _scale.matrix();};
};


