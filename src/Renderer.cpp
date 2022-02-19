//
// Created by daniil on 15.02.2022.
//

#include "VertexShader.h"
#include "PrimitiveAssembler.h"
#include "FragmentShader.h"
#include "BackfaceCuller.h"
#include "DepthBuffer.h"
#include "Rasterizer.h"
#include "Clipper.h"
#include "Renderer.h"
#include <iostream>


std::unique_ptr<IPixelReceiver> Renderer::render(std::unique_ptr<IPixelReceiver> pReceiver, const Scene &scene) {
    DepthBuffer depthBuffer(scene.camera().viewport());
    VertexShader::SetViewMatrix(scene.camera().view().matrix());
    VertexShader::SetProjectionMatrix(scene.camera().fieldOfView().matrix());
    VertexShader::SetViewportMatrix(scene.camera().viewport().matrix());
    BackfaceCuller::SetViewMatrix(scene.camera().view().matrix());
    FragmentShader::SetLights(scene.lights());
    for (auto renderable : scene.renderables()) {
        VertexShader::SetModelMatrix(renderable.matrix());
        for (auto& vertex : renderable.vertices()) {
            VertexShader shader(vertex, renderable);
            vertex = shader.execute();
        }
        BackfaceCuller::SetModelMatrix(renderable.matrix());
        FragmentShader::SetMaterial(renderable.material());
        for (auto face : renderable.primitiveSpecifications()) {
            PrimitiveAssembler assembler(face, renderable);
            auto primitive = assembler.assemble();
            FragmentShader::SetFaceNormal(primitive.normal());
            //BackfaceCuller culler(primitive.normals());
//            if (culler.cull())
//                continue;
            Clipper clipper(primitive, scene.camera().viewport());
            auto clipped = clipper.clip();
            for (const auto& clippedPrimitive : clipped) {
                Rasterizer rasterizer(clippedPrimitive);
                auto fragments = rasterizer.rasterize();
                for (const auto& fragment : fragments) {
                    if (depthBuffer.test(fragment)) {
                        FragmentShader fragmentShader(fragment);
                        auto color = fragmentShader.execute();
                        pReceiver->setPixelColor(fragment.position().x, fragment.position().y, color);
                    }
                }
            }
        }
    }
    return pReceiver;
}
