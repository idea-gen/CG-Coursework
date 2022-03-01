//
// Created by daniil on 24.02.2022.
//

#pragma once

#include "PanelLabeledFrame.h"
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QLabel>

class VectorEdit : public PanelLabeledFrame {
public:
    QLabel* xLabel;
    QLineEdit* xEdit;
    QLabel* yLabel;
    QLineEdit* yEdit;
    QLabel* zLabel;
    QLineEdit* zEdit;
    QDoubleSpinBox* xBox;
    QDoubleSpinBox* yBox;
    QDoubleSpinBox* zBox;
    explicit VectorEdit(const std::string& name) : PanelLabeledFrame(name) {
        xLabel = new QLabel("X");
        xBox = new QDoubleSpinBox;
        xBox->setMaximum(100);
        xBox->setMinimum(-100);
        yLabel = new QLabel("Y");
        yBox = new QDoubleSpinBox;
        yBox->setMaximum(100);
        yBox->setMinimum(-100);
        zLabel = new QLabel("Z");
        zBox = new QDoubleSpinBox;
        zBox->setMaximum(100);
        zBox->setMinimum(-100);

        layout->addWidget(xLabel, 0, 0);
        layout->addWidget(xBox, 0, 1);
        layout->addWidget(yLabel, 1, 0);
        layout->addWidget(yBox, 1, 1);
        layout->addWidget(zLabel, 2, 0);
        layout->addWidget(zBox, 2, 1);
    }
};


