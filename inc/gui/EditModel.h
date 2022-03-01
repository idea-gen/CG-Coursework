//
// Created by daniil on 26.02.2022.
//

#pragma once

#include "Scene.h"
#include "Modeller.h"
#include "MaterialLibrary.h"
#include <QWidget>
#include <QColorDialog>
#include <QGridLayout>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QDialog>
#include <QPushButton>
#include <map>
#include <utility>

class EditModel : public QDialog {
public:
    QGridLayout* layout;
    QDoubleSpinBox* xPos;
    QDoubleSpinBox* yPos;
    QDoubleSpinBox* zPos;
    QPushButton* accepter;
    QPushButton* deletor;
    Scene& scene;
    int index;
    void acceptfunc() {
        Renderable renderable;
        auto x = xPos->value();
        auto y = yPos->value();
        auto z = zPos->value();
        scene.renderables()[index].positionTransform().set(Vector<3, double>(x, y, z));
        accept();
    };
    void deleteFunc() {
        scene.renderables().erase(scene.renderables().begin() + index);
        accept();
    }
    explicit EditModel(Scene& s, int i) : scene(s), index(i) {
        layout = new QGridLayout;
        setLayout(layout);
        auto* xLabel = new QLabel("Позиция по X");
        layout->addWidget(xLabel, 3, 0);
        xPos = new QDoubleSpinBox;
        xPos->setMinimum(-10);
        xPos->setMaximum(10);
        layout->addWidget(xPos, 3, 1);
        auto* yLabel = new QLabel("Позиция по Y");
        layout->addWidget(yLabel, 4, 0);
        yPos = new QDoubleSpinBox;
        yPos->setMinimum(-10);
        yPos->setMaximum(10);
        layout->addWidget(yPos, 4, 1);
        auto* zLabel = new QLabel("Позиция по Z");
        layout->addWidget(zLabel, 5, 0);
        zPos = new QDoubleSpinBox;
        zPos->setMinimum(-10);
        zPos->setMaximum(10);
        layout->addWidget(zPos, 5, 1);
        accepter = new QPushButton("Изменить");
        layout->addWidget(accepter, 6, 0);
        deletor = new QPushButton("Удалить");
        layout->addWidget(deletor, 6, 1);
        connect(accepter, &QPushButton::clicked, this, [this](){ acceptfunc();});
        connect(deletor, &QPushButton::clicked, this, [this](){ deleteFunc();});
    }
};


