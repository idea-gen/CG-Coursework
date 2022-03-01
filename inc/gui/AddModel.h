//
// Created by daniil on 25.02.2022.
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

class AddModel : public QDialog {
public:
    QGridLayout* layout;
    QLineEdit* name;
    QComboBox* type;
    QComboBox* material;
    std::map<std::string, Renderable> typeMap;
    std::map<std::string, Material> materialMap;
    QDoubleSpinBox* xPos;
    QDoubleSpinBox* yPos;
    QDoubleSpinBox* zPos;
    QPushButton* accepter;
    Scene& scene;
    Modeller modeller;
    MaterialLibrary materials;
    void acceptfunc() {
        Renderable renderable;
        auto data = name->text();
        auto data2 = data.toStdString();
        if (type->currentText() == "Куб")
            renderable = modeller.getCube();
        else if (type->currentText() == "Конус")
            renderable = modeller.getCone();
        else if (type->currentText() == "Цилиндр")
            renderable = modeller.getCylinder();
        else if (type->currentText() == "Пирамида")
            renderable = modeller.getPyramid();
        else
            throw std::runtime_error("Add model type fail");
        renderable.name = data.toStdString();
        if (material->currentText() == "Рубин")
            renderable.material() = materials.ruby;
        else if (material->currentText() == "Изумруд")
            renderable.material() = materials.emerald;
        else if (material->currentText() == "Бирюза")
            renderable.material() = materials.turquoise;
        else if (material->currentText() == "Жемчуг")
            renderable.material() = materials.pearl;
        else
            throw std::runtime_error("Add model material fail");
        auto x = xPos->value();
        auto y = yPos->value();
        auto z = zPos->value();
        renderable.positionTransform().set(Vector<3, double>(x, y, z));
        scene.renderables().push_back(renderable);
        accept();
    };
    explicit AddModel(Scene& s, Modeller m) : scene(s), modeller(std::move(m)) {
        layout = new QGridLayout;
        setLayout(layout);
        auto* nameLabel = new QLabel("Название");
        layout->addWidget(nameLabel, 0, 0);
        name = new QLineEdit;
        layout->addWidget(name, 0, 1);
        auto* typeLabel = new QLabel("Тип модели");
        layout->addWidget(typeLabel, 1, 0);
        type = new QComboBox;
        layout->addWidget(type, 1, 1);
        type->addItem("Куб");
        type->addItem("Конус");
        type->addItem("Цилиндр");
        type->addItem("Пирамида");
        auto* materialLabel = new QLabel("Материал");
        layout->addWidget(materialLabel, 2, 0);
        material = new QComboBox;
        layout->addWidget(material, 2, 1);
        material->addItem("Рубин");
        material->addItem("Изумруд");
        material->addItem("Бирюза");
        material->addItem("Жемчуг");
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
        accepter = new QPushButton("Добавить");
        layout->addWidget(accepter, 6, 1);
        connect(accepter, &QPushButton::clicked, this, [this](){ acceptfunc();});
    }
};


