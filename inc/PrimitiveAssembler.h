//
// Created by daniil on 15.02.2022.
//

#pragma once

#include "PrimitiveSpecification.h"
#include "Renderable.h"
#include "Primitive.h"
#include <memory>
#include <utility>

class PrimitiveAssembler {
    PrimitiveSpecification _face;
    Renderable _renderable;
public:
    PrimitiveAssembler(PrimitiveSpecification face, Renderable renderable)
    : _face(face), _renderable(std::move(renderable)) {};
    [[nodiscard]] Primitive assemble() const {
        Primitive primitive;
        primitive.normal() = _renderable.faceNormals()[_face.normal];
        for (int i = 0; auto specificationIndex : _face.vertices) {
            auto specification = _renderable.vertexSpecifications()[specificationIndex];
            Vertex vertex;
            vertex.position = _renderable.vertices()[specification.vertex];
            vertex.worldPosition = _renderable.worldVertices()[specification.vertex];
            vertex.texture = _renderable.textures()[specification.texture];
            auto modelNormal = Vector<4, double>(_renderable.vertexNormals()[specification.normal], 0.);
            auto viewNormal = _renderable.matrix() * modelNormal;
            vertex.normal = Vector<3, double>(viewNormal.x, viewNormal.y, viewNormal.z);
            primitive.vertices()[i++] = vertex;
        }
        return primitive;
    }
};


