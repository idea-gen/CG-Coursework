//
// Created by daniil on 27.02.2022.
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

class EditDirect : public QDialog {
public:
    QGridLayout* layout;
    QLineEdit* name{};
    QDoubleSpinBox* xDir;
    QDoubleSpinBox* yDir;
    QDoubleSpinBox* zDir;
    QDoubleSpinBox* rColor;
    QDoubleSpinBox* gColor;
    QDoubleSpinBox* bColor;
    QPushButton* accepter;
    QPushButton* deletor;
    int index;
    Scene& scene;
    void acceptfunc() {
        auto x = xDir->value();
        auto y = yDir->value();
        auto z = zDir->value();
        auto r = rColor->value();
        auto g = gColor->value();
        auto b = bColor->value();
        scene.lights().directional()[index].color() = {r, g, b};
        scene.lights().directional()[index].direction() = Vector<3, double>(x, y, z);
        accept();
    };
    void deleteFunc() {
        scene.lights().directional().erase(scene.lights().directional().begin() + index);
        accept();
    }
    explicit EditDirect(Scene& s, int i) : scene(s), index(i) {
        layout = new QGridLayout;
        setLayout(layout);
        auto* xLabel = new QLabel("Направление по X");
        layout->addWidget(xLabel, 1, 0);
        xDir = new QDoubleSpinBox;
        xDir->setMinimum(-1);
        xDir->setMaximum(1);
        layout->addWidget(xDir, 1, 1);
        auto* yLabel = new QLabel("Направление по Y");
        layout->addWidget(yLabel, 2, 0);
        yDir = new QDoubleSpinBox;
        yDir->setMinimum(-1);
        yDir->setMaximum(1);
        layout->addWidget(yDir, 2, 1);
        auto* zLabel = new QLabel("Направление по Z");
        layout->addWidget(zLabel, 3, 0);
        zDir = new QDoubleSpinBox;
        zDir->setMinimum(-1);
        zDir->setMaximum(1);
        layout->addWidget(zDir, 3, 1);
        auto* rLabel = new QLabel("Цвет красный");
        layout->addWidget(rLabel, 4, 0);
        rColor = new QDoubleSpinBox;
        rColor->setMinimum(0);
        rColor->setMaximum(1);
        layout->addWidget(rColor, 4, 1);
        auto* gLabel = new QLabel("Цвет зеленый");
        layout->addWidget(gLabel, 5, 0);
        gColor = new QDoubleSpinBox;
        gColor->setMinimum(0);
        gColor->setMaximum(1);
        layout->addWidget(gColor, 5, 1);
        auto* bLabel = new QLabel("Цвет синий");
        layout->addWidget(bLabel, 6, 0);
        bColor = new QDoubleSpinBox;
        bColor->setMinimum(0);
        bColor->setMaximum(1);
        layout->addWidget(bColor, 6, 1);
        accepter = new QPushButton("Изменить");
        layout->addWidget(accepter, 7, 0);
        deletor = new QPushButton("Удалить");
        layout->addWidget(deletor, 7, 1);
        connect(accepter, &QPushButton::clicked, this, [this](){ acceptfunc();});
        connect(deletor, &QPushButton::clicked, this, [this](){ deleteFunc();});
    }
};


