//
// Created by daniil on 16.02.2022.
//

#pragma once

#include "Scene.h"
#include "Renderer.h"
#include "Modeller.h"
#include "PixelReceiver.h"
#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPushButton>
#include <QPixmap>

class MainWindow : public QMainWindow {
private:
    QWidget* _centralWidget = nullptr;
    QGridLayout* _gridLayout = nullptr;
    QGraphicsView* _graphicsView = nullptr;
    QGraphicsScene* _graphicsScene = nullptr;
    QPushButton* _button = nullptr;
    Scene _scene;
    Renderer _renderer;
    Modeller _modeller;
    void sceneSetup() {
        _modeller.init("obj");

        auto cube = _modeller.getCube();
//        cube.material().ambient() = Color(1., 1., 1.);
        cube.material().ambient() = Color(.1745, .01175, .01175);
        cube.material().diffuse() = Color(.61424, .04136, .04136);
        cube.material().specular() = Color(0.727811, 0.626959, 0.626959);
//        cube.material().shininess() = 0.6;
        cube.material().shininess() = 0.1;
        _scene.renderables().push_back(cube);
        _scene.camera().view().position().set(Vector<3, double>(0., 4., 4.5));

        PointLight light(1., Vector<3, double>(0., 0., -9.5));
        _scene.lights().point().push_back(light);
    }
public:
    void updateScene() {
        _scene.camera().viewport().setWidth(_graphicsView->width());
        _scene.camera().viewport().setHeight(_graphicsView->height());
        std::unique_ptr<IPixelReceiver> pReceiver = std::make_unique<PixelReceiver>(_graphicsView->width(),
                                                         _graphicsView->height());
        pReceiver = _renderer.render(std::move(pReceiver), _scene);
        _graphicsScene->clear();
        _graphicsScene->addPixmap(QPixmap::fromImage(*(QImage*)(pReceiver->data())));
    }
    MainWindow() {
        sceneSetup();

        _centralWidget = new QWidget;
        setCentralWidget(_centralWidget);
        _gridLayout = new QGridLayout;
        _centralWidget->setLayout(_gridLayout);
        _graphicsView = new QGraphicsView;
        _graphicsView->resize(500, 500);
        _gridLayout->addWidget(_graphicsView);
        _graphicsScene = new QGraphicsScene;
        _gridLayout->addWidget(_graphicsView, 0, 0);
        _graphicsScene = new QGraphicsScene;
        _graphicsView->setScene(_graphicsScene);
        updateScene();

        // TODO delete testing
        _button = new QPushButton("Rotate Y");
        _gridLayout->addWidget(_button, 0, 1);
        connect(_button, &QPushButton::clicked,
                this, [&](){_scene.camera().view().rotation().rotateY(5.); updateScene();});
    }
};


