//
// Created by daniil on 15.02.2022.
//

#pragma once

#include "mathematics.h"
#include "transform/PositionTransform.h"
#include "SceneEntity.h"
#include "transform/RotationTransform.h"
#include "transform/ScaleTransform.h"
#include "Vertex.h"
#include "Color.h"
#include "VertexSpecification.h"
#include "PrimitiveSpecification.h"
#include "Material.h"
#include <vector>

class Renderable : public SceneEntity {
private:
    std::vector<Vector<3, double>> _vertices;
    std::vector<Vector<2, double>> _textures;
    std::vector<Vector<3, double>> _vertexNormals;
    std::vector<Vector<3, double>> _faceNormals;
    std::vector<VertexSpecification> _vertexSpecifications;
    std::vector<PrimitiveSpecification> _primitiveSpecifications;
    std::vector<Vector<3, double>> _worldVertices;
    PositionTransform _position;
    RotationTransform _rotation;
    ScaleTransform _scale;
    Material _material;
public:
    [[nodiscard]] std::vector<Vector<3, double>>& vertices() {return _vertices;};
    [[nodiscard]] std::vector<Vector<3, double>> vertices() const {return _vertices;};
    [[nodiscard]] std::vector<Vector<2, double>>& textures() {return _textures;};
    [[nodiscard]] std::vector<Vector<2, double>> textures() const {return _textures;};
    [[nodiscard]] std::vector<Vector<3, double>>& vertexNormals() {return _vertexNormals;};
    [[nodiscard]] std::vector<Vector<3, double>> vertexNormals() const {return _vertexNormals;};
    [[nodiscard]] std::vector<Vector<3, double>>& faceNormals() {return _faceNormals;};
    [[nodiscard]] const std::vector<Vector<3, double>>& faceNormals() const {return _faceNormals;};
    [[nodiscard]] std::vector<Vector<3, double>>& worldVertices() {return _worldVertices;};
    [[nodiscard]] std::vector<Vector<3, double>> worldVertices() const {return _worldVertices;};
    [[nodiscard]] std::vector<VertexSpecification>& vertexSpecifications()
    {return _vertexSpecifications;};
    [[nodiscard]] const std::vector<VertexSpecification>& vertexSpecifications() const
    {return _vertexSpecifications;};
    [[nodiscard]] std::vector<PrimitiveSpecification>& primitiveSpecifications()
    {return _primitiveSpecifications;};
    [[nodiscard]] std::vector<PrimitiveSpecification> primitiveSpecifications() const
    {return _primitiveSpecifications;};
    PositionTransform& positionTransform() {return _position;};
    [[nodiscard]] Matrix<4, 4, double> matrix() const
    {return _position.matrix() * _rotation.matrix() * _scale.matrix();};
    [[nodiscard]] Material& material() {return _material;};
    [[nodiscard]] const Material& material() const {return _material;};
};


