//
// Created by daniil on 24.02.2022.
//

#pragma once

#include "PanelLabeledFrame.h"
#include <QSplitter>
#include <QListWidget>
#include <QPushButton>

class SceneManager : public PanelLabeledFrame {
public:
    QListWidget* models;
    QPushButton* addModel;
    QListWidget* directs;
    QPushButton* addDirect;
    QListWidget* points;
    QPushButton* addPoint;
    QListWidget* spots;
    QPushButton* addSpot;
    SceneManager() : PanelLabeledFrame("Объекты сцены") {
        auto* modelLabel = new QLabel("Модели");
        layout->addWidget(modelLabel, 0, 0);
        models = new QListWidget;
        layout->addWidget(models, 1, 0);
        addModel = new QPushButton("Добавить");
        layout->addWidget(addModel, 2, 0);

        auto* directLabel = new QLabel("Направленный свет");
        layout->addWidget(directLabel, 3, 0);
        directs = new QListWidget;
        layout->addWidget(directs, 4, 0);
        addDirect = new QPushButton("Добавить");
        layout->addWidget(addDirect, 5, 0);

        auto* pointLabel = new QLabel("Точечный свет");
        layout->addWidget(pointLabel, 0, 1);
        points = new QListWidget;
        layout->addWidget(points, 1, 1);
        addPoint = new QPushButton("Добавить");
        layout->addWidget(addPoint, 2, 1);

        auto* spotLabel = new QLabel("Прожекторы");
        layout->addWidget(spotLabel, 3, 1);
        spots = new QListWidget;
        layout->addWidget(spots, 4, 1);
        addSpot = new QPushButton("Добавить");
        layout->addWidget(addSpot, 5, 1);
    }
};


