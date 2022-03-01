//
// Created by daniil on 20.02.2022.
//

#pragma once

#include "gui/PanelLabeledFrame.h"
#include <QPushButton>
#include <QLabel>

class MoveFrame : public PanelLabeledFrame {
public:
    QPushButton* up;
    QPushButton* down;
    QPushButton* right;
    QPushButton* left;
    QPushButton* forward;
    QPushButton* back;
    MoveFrame() : PanelLabeledFrame("Перемещение камеры") {
        up = new QPushButton("Вверх");
        layout->addWidget(up, 1, 1, 1, 2);
        left = new QPushButton("Влево");
        layout->addWidget(left, 2, 0);
        right = new QPushButton("Вправо");
        layout->addWidget(right, 2, 3);
        down = new QPushButton("Вниз");
        layout->addWidget(down, 3, 1, 1, 2);
        forward = new QPushButton("Вперед");
        layout->addWidget(forward, 2, 1);
        back = new QPushButton("Назад");
        layout->addWidget(back, 2, 2);
    }
};


