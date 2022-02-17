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
    PrimitiveAssembler(PrimitiveSpecification face, Renderable renderable) : _face(face), _renderable(std::move(renderable)) {};
    [[nodiscard]] Primitive assemble() const {
        const auto& vertices = _renderable.geometricVertices();
        auto& indices = _face.vertices;
        std::array<Vertex, 3> primitiveVertices = {vertices[indices[0]], vertices[indices[1]], vertices[indices[2]]};
        auto normal = _renderable.normals()[_face.normal];
        return {primitiveVertices, normal};
    }
};


