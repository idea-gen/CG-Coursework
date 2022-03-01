//
// Created by daniil on 16.02.2022.
//

#pragma once

#include "Scene.h"
#include "Renderer.h"
#include "Modeller.h"
#include "PixelReceiver.h"
#include "VectorEdit.h"
#include "ModelTransformFrame.h"
#include "AddDirect.h"
#include "AddPoint.h"
#include "AddSpot.h"
#include "AddModel.h"
#include "EditDirect.h"
#include "EditPoint.h"
#include "EditSpot.h"
#include "EditModel.h"
#include "SceneManager.h"
#include "GraphicsView.h"
#include "MoveFrame.h"
#include "RotateFrame.h"
#include <QMainWindow>
#include <QGridLayout>
#include <QSplitter>
#include <QWidget>
#include <QGraphicsScene>
#include <QDialog>
#include <QPushButton>
#include <QPixmap>
#include <iostream>
#include <thread>

class MainWindow : public QMainWindow {
private:
    GraphicsView* _graphicsView = nullptr;
    QGraphicsScene* _graphicsScene = nullptr;
    SceneManager* _manager;
    QSplitter* _vSplitter;
    QSplitter* _htSplitter;
    QSplitter* _hbSplitter;
    MoveFrame* _moveFrame;
    RotateFrame* _rotateFrame;
    Scene _scene;
    QWidget* _parameters;
    Renderer _renderer;
    Modeller _modeller;
    std::thread _thread;
    void sceneSetup0() {
        auto cube0 = _modeller.getCube();
        cube0.material().ambient() = Color(.1745, .01175, .01175);
        cube0.material().diffuse() = Color(.61424, .04136, .04136);
        cube0.material().specular() = Color(0.727811, 0.626959, 0.626959);
        cube0.material().shininess() = 0.1;
        cube0.positionTransform().set(Vector<3, double>(0., 0., 2.));
        _scene.renderables().push_back(cube0);

        auto cube1 = _modeller.getCube();
        cube1.material().ambient() = Color(.01175, .1745, .01175);
        cube1.material().diffuse() = Color(.04136,.61424, .04136);
        cube1.material().specular() = Color(0.626959, 0.727811, 0.626959);
        cube1.material().shininess() = 1.;
        cube1.positionTransform().set(Vector<3, double>(2., 0., 2.));
        _scene.renderables().push_back(cube1);

        auto cube2 = _modeller.getCube();
        cube2.material().ambient() = Color(.01175, .01175, .1745);
        cube2.material().diffuse() = Color(.04136, .04136,.61424);
        cube2.material().specular() = Color(0.626959, 0.626959, 0.727811);
        cube2.material().shininess() = 0.8;
        cube2.positionTransform().set(Vector<3, double>(-2., 0., 2.));
        _scene.renderables().push_back(cube2);

        _scene.camera().view().position().set(Vector<3, double>(0., 0., 0.));

        {
            PointLight light(Vector<3, double>(-2., 1., 2.));
            light.color() = Color(.4, .4, .4);
            _scene.lights().point().push_back(light);
        }
        {
            SpotLight light(Vector<3, double>(2.2, .55, 2.), Vector<3, double>(.0, -1., 1.).normalize());
            light.color() = Color(1., 1., 1.);
            _scene.lights().spot().push_back(light);
        }
        {
            DirectionalLight light(Vector<3, double>(0., 0., 1.));
            light.color() = Color(.2, .2, .2);
            _scene.lights().directional().push_back(light);
        }
    }
    void sceneSetup1() {
        {
            auto model = _modeller.getCylinder();
            model.material().ambient() = Color(.1, .1, .1);
            model.material().diffuse() = Color(.5, .5, .5);
            model.material().specular() = Color(.7, .7, .7);
            model.material().shininess() = 0.6;
            model.positionTransform().set(Vector<3, double>(1., 0., 2.));
            _scene.renderables().push_back(model);
        }
        {
            auto model = _modeller.getCube();
            model.material().ambient() = Color(.1, .1, .1);
            model.material().diffuse() = Color(.9, .4, .4);
            model.material().specular() = Color(0., 0., 0.);
            model.material().shininess() = 0.1;
            model.positionTransform().set(Vector<3, double>(-1., 0., 2.));
            _scene.renderables().push_back(model);
        }
        {
            auto model = _modeller.getCone();
            model.material().ambient() = Color(.1, .1, .1);
            model.material().diffuse() = Color(.9, .4, .4);
            model.material().specular() = Color(0., 0., 0.);
            model.material().shininess() = 0.1;
            model.positionTransform().set(Vector<3, double>(-3., 0., 2.));
            _scene.renderables().push_back(model);
        }
        {
            auto model = _modeller.getPyramid();
            model.material().ambient() = Color(.1, .1, .1);
            model.material().diffuse() = Color(.9, .4, .4);
            model.material().specular() = Color(0., 0., 0.);
            model.material().shininess() = 0.1;
            model.positionTransform().set(Vector<3, double>(3., 0., 2.));
            _scene.renderables().push_back(model);
        }

        _scene.camera().view().position().set(Vector<3, double>(0., 0., 0.));

        {
            PointLight light(Vector<3, double>(0., 0., .0));
            light.color() = Color(.9, .9, .9);
            _scene.lights().point().push_back(light);
        }
    }
    void sceneSetup2() {
        {
            auto model = _modeller.getCube();
            model.material().ambient() = Color(1., 1., 1.);
            model.material().diffuse() = Color(.9, .4, .4);
            model.material().specular() = Color(0., 0., 0.);
            model.material().shininess() = 0.1;
            model.positionTransform().set(Vector<3, double>(-1., 0., 3.));
            _scene.renderables().push_back(model);
        }
        {
            auto model = _modeller.getCube();
            model.material().ambient() = Color(1., 1., 1.);
            model.material().diffuse() = Color(.9, .4, .4);
            model.material().specular() = Color(0., 0., 0.);
            model.material().shininess() = 0.1;
            model.positionTransform().set(Vector<3, double>(1., 0., 3.));
            _scene.renderables().push_back(model);
        }
        {
            auto model = _modeller.getCube();
            model.material().ambient() = Color(1., 1., 1.);
            model.material().diffuse() = Color(.9, .4, .4);
            model.material().specular() = Color(0., 0., 0.);
            model.material().shininess() = 0.1;
            model.positionTransform().set(Vector<3, double>(0., 1., 3.));
            _scene.renderables().push_back(model);
        }
        {
            auto model = _modeller.getCube();
            model.material().ambient() = Color(1., 1., 1.);
            model.material().diffuse() = Color(.9, .4, .4);
            model.material().specular() = Color(0., 0., 0.);
            model.material().shininess() = 0.1;
            model.positionTransform().set(Vector<3, double>(0., -1., 3.));
            _scene.renderables().push_back(model);
        }
        {
            auto model = _modeller.getCube();
            model.material().ambient() = Color(1., 1., 1.);
            model.material().diffuse() = Color(.9, .4, .4);
            model.material().specular() = Color(0., 0., 0.);
            model.material().shininess() = 0.1;
            model.positionTransform().set(Vector<3, double>(0., 0., 3.));
            _scene.renderables().push_back(model);
        }

        _scene.camera().view().position().set(Vector<3, double>(0., 0., 0.));

//        {
//            PointLight light(1., Vector<3, double>(0., 0., .0));
//            light.color() = Color(.9, .9, .9);
//            _scene.lights().point().push_back(light);
//        }
    }
    void updateManager() {
        _manager->models->clear();
        for (auto& renderable : _scene.renderables()) {
            static int i = 0;
            if (renderable.name.empty()) {
                renderable.name = std::string("БезНазвания") + std::to_string(i);
                i++;
            }
            _manager->models->addItem(renderable.name.c_str());
        }
        _manager->directs->clear();
        for (auto& light : _scene.lights().directional()) {
            static int i = 0;
            if (light.name.empty()) {
                light.name = std::string("БезНазвания") + std::to_string(i);
                i++;
            }
            _manager->directs->addItem(light.name.c_str());
        }
        _manager->points->clear();
        for (auto& light : _scene.lights().point()) {
            static int i = 0;
            if (light.name.empty()) {
                light.name = std::string("БезНазвания") + std::to_string(i);
                i++;
            }
            _manager->points->addItem(light.name.c_str());
        }
        _manager->spots->clear();
        for (auto& light : _scene.lights().spot()) {
            static int i = 0;
            if (light.name.empty()) {
                light.name = std::string("БезНазвания") + std::to_string(i);
                i++;
            }
            _manager->spots->addItem(light.name.c_str());
        }
    }
    void move(const Vector<4, double>& direction) {
        auto matrix = _scene.camera().view().rotation().invMatrix();
        auto hDirected = matrix * direction;
        auto directed = Vector<3, double>(hDirected.x, hDirected.y, hDirected.z);
        auto updated = _scene.camera().view().position().get() + directed;
        _scene.camera().view().position().set(updated);
    };
    void connects() {
        connect(_graphicsView, &GraphicsView::resized, this, [&](){updateScene();});

        connect(_rotateFrame->up, &QPushButton::clicked,
                this, [&](){_scene.camera().view().rotation().rotateX(-5.); updateScene();});
        connect(_rotateFrame->down, &QPushButton::clicked,
                this, [&](){_scene.camera().view().rotation().rotateX(5.); updateScene();});
        connect(_rotateFrame->left, &QPushButton::clicked,
                this, [&](){_scene.camera().view().rotation().rotateY(5.); updateScene();});
        connect(_rotateFrame->right, &QPushButton::clicked,
                this, [&](){_scene.camera().view().rotation().rotateY(-5.); updateScene();});


        connect(_moveFrame->forward, &QPushButton::clicked,this,
                [&](){move(Vector<4, double>(0., 0., -1., 0.)); updateScene();});
        connect(_moveFrame->back, &QPushButton::clicked,this,
                [&](){move(Vector<4, double>(0., 0., 1., 0.)); updateScene();});
        connect(_moveFrame->down, &QPushButton::clicked,this,
                [&](){move(Vector<4, double>(0., 1., 0., 0.)); updateScene();});
        connect(_moveFrame->up, &QPushButton::clicked,this,
                [&](){move(Vector<4, double>(0., -1., 0., 0.)); updateScene();});
        connect(_moveFrame->left, &QPushButton::clicked,this,
                [&](){move(Vector<4, double>(1., 0., 0., 0.)); updateScene();});
        connect(_moveFrame->right, &QPushButton::clicked,this,
                [&](){move(Vector<4, double>(-1., 0., 0., 0.)); updateScene();});

        connect(_manager->addModel, &QPushButton::clicked, this,[&](){
            auto* addWidget = new AddModel(_scene, _modeller);
            addWidget->exec(); updateScene();
            updateManager();
        });
        connect(_manager->models, &QListWidget::doubleClicked, this, [&]() {
            auto* editWidget = new EditModel(_scene, _manager->models->currentRow());
            editWidget->exec();
            updateScene();
            updateManager();
        });
        connect(_manager->addDirect, &QPushButton::clicked, this,[&](){
            auto* addWidget = new AddDirect(_scene);
            addWidget->exec(); updateScene();
            updateManager();
        });
        connect(_manager->directs, &QListWidget::doubleClicked, this, [&]() {
            auto* editWidget = new EditDirect(_scene, _manager->directs->currentRow());
            editWidget->exec();
            updateScene();
            updateManager();
        });
        connect(_manager->addPoint, &QPushButton::clicked, this,[&](){
            auto* addWidget = new AddPoint(_scene);
            addWidget->exec(); updateScene();
            updateManager();
        });
        connect(_manager->points, &QListWidget::doubleClicked, this, [&]() {
            auto* editWidget = new EditPoint(_scene, _manager->points->currentRow());
            editWidget->exec();
            updateScene();
            updateManager();
        });
        connect(_manager->addSpot, &QPushButton::clicked, this,[&](){
            auto* addWidget = new AddSpot(_scene);
            addWidget->exec(); updateScene();
            updateManager();
        });
        connect(_manager->spots, &QListWidget::doubleClicked, this, [&]() {
            auto* editWidget = new EditSpot(_scene, _manager->spots->currentRow());
            editWidget->exec();
            updateScene();
            updateManager();
        });
    }
public:
    void updateScene() {
        _scene.camera().viewport().setWidth(_graphicsView->width());
        _scene.camera().viewport().setHeight(_graphicsView->height());
        auto ratio = double(_graphicsView->width()) / double(_graphicsView->height());
        auto bottom = _scene.camera().fieldOfView().bottom();
        _scene.camera().fieldOfView().setLeft(bottom * ratio);
        auto top = _scene.camera().fieldOfView().top();
        _scene.camera().fieldOfView().setRight(top * ratio);
//        _scene.camera().fieldOfView()
        std::shared_ptr<IPixelReceiver> pReceiver = std::make_shared<PixelReceiver>(_graphicsView->width(),
                                                         _graphicsView->height());
        _renderer.render(pReceiver, _scene);
        _graphicsScene->clear();
        _graphicsScene->addPixmap(QPixmap::fromImage(*(QImage*)(pReceiver->data())));
    }
    MainWindow() {
        _modeller.init("obj");
        sceneSetup0();

        _vSplitter = new QSplitter(Qt::Vertical);
        setCentralWidget(_vSplitter);
        _htSplitter = new QSplitter(Qt::Horizontal);
        _vSplitter->addWidget(_htSplitter);
        _hbSplitter = new QSplitter(Qt::Horizontal);
        _vSplitter->addWidget(_hbSplitter);

        _manager = new SceneManager;
        _htSplitter->addWidget(_manager);

        _graphicsView = new GraphicsView;
        _graphicsScene = new QGraphicsScene;
        _graphicsView->setScene(_graphicsScene);
        _htSplitter->addWidget(_graphicsView);

        _moveFrame = new MoveFrame;
        _hbSplitter->addWidget(_moveFrame);
        _rotateFrame = new RotateFrame;
        _hbSplitter->addWidget(_rotateFrame);

        //_parameters = new ModelTransformFrame;
        //_htSplitter->addWidget(_parameters);

        connects();
        updateScene();
        updateManager();
    }
};


