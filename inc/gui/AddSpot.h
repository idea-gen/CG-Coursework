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

class AddSpot : public QDialog {
public:
    QGridLayout* layout;
    QLineEdit* name{};
    QDoubleSpinBox* xPos;
    QDoubleSpinBox* yPos;
    QDoubleSpinBox* zPos;
    QDoubleSpinBox* xDir;
    QDoubleSpinBox* yDir;
    QDoubleSpinBox* zDir;
    QDoubleSpinBox* rColor;
    QDoubleSpinBox* gColor;
    QDoubleSpinBox* bColor;
    QPushButton* accepter;
    Scene& scene;
    void acceptfunc() {
        auto xp = xPos->value();
        auto yp = yPos->value();
        auto zp = zPos->value();
        auto xd = xDir->value();
        auto yd = yDir->value();
        auto zd = zDir->value();
        SpotLight light(Vector<3, double>(xp, yp, zp), Vector<3, double>(xd, yd, zd));
        light.name = name->text().toStdString();
        auto r = rColor->value();
        auto g = gColor->value();
        auto b = bColor->value();
        light.color() = {r, g, b};
        scene.lights().spot().push_back(light);
        accept();
    };
    explicit AddSpot(Scene& s) : scene(s) {
        layout = new QGridLayout;
        setLayout(layout);
        auto* nameLabel = new QLabel("Название");
        layout->addWidget(nameLabel, 0, 0);
        name = new QLineEdit;
        layout->addWidget(name, 0, 1);
        auto* xLabel = new QLabel("Позиция по X");
        layout->addWidget(xLabel, 1, 0);
        xPos = new QDoubleSpinBox;
        xPos->setMinimum(-10);
        xPos->setMaximum(10);
        layout->addWidget(xPos, 1, 1);
        auto* yLabel = new QLabel("Позиция по Y");
        layout->addWidget(yLabel, 2, 0);
        yPos = new QDoubleSpinBox;
        yPos->setMinimum(-10);
        yPos->setMaximum(10);
        layout->addWidget(yPos, 2, 1);
        auto* zLabel = new QLabel("Позиция по Z");
        layout->addWidget(zLabel, 3, 0);
        zPos = new QDoubleSpinBox;
        zPos->setMinimum(-10);
        zPos->setMaximum(10);
        layout->addWidget(zPos, 3, 1);
        auto* xDirLabel = new QLabel("Направление по X");
        layout->addWidget(xDirLabel, 4, 0);
        xDir = new QDoubleSpinBox;
        xDir->setMinimum(-1);
        xDir->setMaximum(1);
        layout->addWidget(xDir, 4, 1);
        auto* yDirLabel = new QLabel("Направление по Y");
        layout->addWidget(yDirLabel, 5, 0);
        yDir = new QDoubleSpinBox;
        yDir->setMinimum(-1);
        yDir->setMaximum(1);
        layout->addWidget(yDir, 5, 1);
        auto* zDirLabel = new QLabel("Направление по Z");
        layout->addWidget(zDirLabel, 6, 0);
        zDir = new QDoubleSpinBox;
        zDir->setMinimum(-1);
        zDir->setMaximum(1);
        layout->addWidget(zDir, 6, 1);
        auto* rLabel = new QLabel("Цвет красный");
        layout->addWidget(rLabel, 7, 0);
        rColor = new QDoubleSpinBox;
        rColor->setMinimum(0);
        rColor->setMaximum(1);
        layout->addWidget(rColor, 7, 1);
        auto* gLabel = new QLabel("Цвет зеленый");
        layout->addWidget(gLabel, 8, 0);
        gColor = new QDoubleSpinBox;
        gColor->setMinimum(0);
        gColor->setMaximum(1);
        layout->addWidget(gColor, 8, 1);
        auto* bLabel = new QLabel("Цвет синий");
        layout->addWidget(bLabel, 9, 0);
        bColor = new QDoubleSpinBox;
        bColor->setMinimum(0);
        bColor->setMaximum(1);
        layout->addWidget(bColor, 9, 1);
        accepter = new QPushButton("Добавить");
        layout->addWidget(accepter, 10, 1);
        connect(accepter, &QPushButton::clicked, this, [this](){ acceptfunc();});
    }
};
