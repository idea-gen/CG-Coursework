//
// Created by daniil on 15.02.2022.
//

#pragma once

#include "IPixelReceiver.h"
#include "Scene.h"
#include <memory>

class Renderer {
public:
    std::unique_ptr<IPixelReceiver> render(std::unique_ptr<IPixelReceiver> pReceiver, const Scene& scene);
};


