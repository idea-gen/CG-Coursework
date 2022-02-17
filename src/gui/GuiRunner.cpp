//
// Created by daniil on 16.02.2022.
//

#include "gui/GuiRunner.h"
#include "gui/MainWindow.h"
#include <QApplication>

void GuiRunner::run() {
    QApplication application(_argc, _argv);
    auto* mainWindow = new MainWindow;
    mainWindow->show();
    QApplication::exec();
}
