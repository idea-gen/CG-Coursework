//
// Created by daniil on 24.02.2022.
//

#pragma once

#include "PanelLabeledFrame.h"
#include "VectorEdit.h"

class ModelTransformFrame : public PanelLabeledFrame {
public:
    VectorEdit* position;
    VectorEdit* rotation;
    VectorEdit* scale;
    ModelTransformFrame() : PanelLabeledFrame("Модель") {
        position = new VectorEdit("Позиция");
        rotation = new VectorEdit("Поворот");
        scale = new VectorEdit("Масштаб");
        layout->addWidget(position);
        //layout->addWidget(rotation);
        //layout->addWidget(scale);
    }
};


