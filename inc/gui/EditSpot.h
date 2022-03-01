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

class EditSpot : public QDialog {
public:
    QGridLayout* layout;
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
    QPushButton* deletor;
    int index;
    Scene& scene;
    void acceptfunc() {
        auto xp = xPos->value();
        auto yp = yPos->value();
        auto zp = zPos->value();
        auto xd = xDir->value();
        auto yd = yDir->value();
        auto zd = zDir->value();
        auto r = rColor->value();
        auto g = gColor->value();
        auto b = bColor->value();
        scene.lights().spot()[index].position() = Vector<3, double>(xp, yp, zp);
        scene.lights().spot()[index].direction() = Vector<3, double>(xd, yd, zd);
        scene.lights().spot()[index].color() = {r, g, b};
        accept();
    };
    void deleteFunc() {
        scene.lights().spot().erase(scene.lights().spot().begin() + index);
        accept();
    }
    explicit EditSpot(Scene& s, int i) : scene(s), index(i) {
        layout = new QGridLayout;
        setLayout(layout);
        auto* xLabel = new QLabel("Позиция по X");
        layout->addWidget(xLabel, 0, 0);
        xPos = new QDoubleSpinBox;
        xPos->setMinimum(-10);
        xPos->setMaximum(10);
        layout->addWidget(xPos, 0, 1);
        auto* yLabel = new QLabel("Позиция по Y");
        layout->addWidget(yLabel, 1, 0);
        yPos = new QDoubleSpinBox;
        yPos->setMinimum(-10);
        yPos->setMaximum(10);
        layout->addWidget(yPos, 1, 1);
        auto* zLabel = new QLabel("Позиция по Z");
        layout->addWidget(zLabel, 2, 0);
        zPos = new QDoubleSpinBox;
        zPos->setMinimum(-10);
        zPos->setMaximum(10);
        layout->addWidget(zPos, 2, 1);

        auto* xDirLabel = new QLabel("Позиция по X");
        layout->addWidget(xDirLabel, 3, 0);
        xDir = new QDoubleSpinBox;
        xDir->setMinimum(-10);
        xDir->setMaximum(10);
        layout->addWidget(xDir, 3, 1);
        auto* yDirLabel = new QLabel("Позиция по Y");
        layout->addWidget(yDirLabel, 4, 0);
        yDir = new QDoubleSpinBox;
        yDir->setMinimum(-10);
        yDir->setMaximum(10);
        layout->addWidget(yDir, 4, 1);
        auto* zDirLabel = new QLabel("Позиция по Z");
        layout->addWidget(zDirLabel, 5, 0);
        zDir = new QDoubleSpinBox;
        zDir->setMinimum(-10);
        zDir->setMaximum(10);
        layout->addWidget(zDir, 5, 1);
        
        auto* rLabel = new QLabel("Цвет красный");
        layout->addWidget(rLabel, 6, 0);
        rColor = new QDoubleSpinBox;
        rColor->setMinimum(0);
        rColor->setMaximum(1);
        layout->addWidget(rColor, 6, 1);
        auto* gLabel = new QLabel("Цвет зеленый");
        layout->addWidget(gLabel, 7, 0);
        gColor = new QDoubleSpinBox;
        gColor->setMinimum(0);
        gColor->setMaximum(1);
        layout->addWidget(gColor, 7, 1);
        auto* bLabel = new QLabel("Цвет синий");
        layout->addWidget(bLabel, 8, 0);
        bColor = new QDoubleSpinBox;
        bColor->setMinimum(0);
        bColor->setMaximum(1);
        layout->addWidget(bColor, 8, 1);
        accepter = new QPushButton("Изменить");
        layout->addWidget(accepter, 9, 0);
        deletor = new QPushButton("Удалить");
        layout->addWidget(deletor, 9, 1);
        connect(accepter, &QPushButton::clicked, this, [this](){ acceptfunc();});
        connect(deletor, &QPushButton::clicked, this, [this](){ deleteFunc();});
    }
};
