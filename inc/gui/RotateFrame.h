//
// Created by daniil on 23.02.2022.
//

#pragma once

#include "gui/PanelLabeledFrame.h"
#include <QPushButton>
#include <QLabel>

class RotateFrame : public PanelLabeledFrame {
public:
    QPushButton* up;
    QPushButton* down;
    QPushButton* right;
    QPushButton* left;
    QPushButton* forward;
    QPushButton* back;
    RotateFrame() : PanelLabeledFrame("Поворот камеры") {
        up = new QPushButton("Вверх");
        layout->addWidget(up, 1, 1);
        left = new QPushButton("Влево");
        layout->addWidget(left, 2, 0);
        right = new QPushButton("Вправо");
        layout->addWidget(right, 2, 3);
        down = new QPushButton("Вниз");
        layout->addWidget(down, 3, 1);
    }

};


