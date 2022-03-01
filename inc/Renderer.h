//
// Created by daniil on 15.02.2022.
//

#pragma once

#include "IPixelReceiver.h"
#include "Scene.h"
#include <memory>

class Renderer {
public:
    void render(std::shared_ptr<IPixelReceiver> pReceiver, const Scene& scene);
};


