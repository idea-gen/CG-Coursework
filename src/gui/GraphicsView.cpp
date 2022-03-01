//
// Created by daniil on 23.02.2022.
//

#include "gui/GraphicsView.h"
#include <QDebug>

void GraphicsView::resizeEvent(QResizeEvent *event) {
    if (timerId){
        killTimer(timerId);
        timerId = 0;
    }
    timerId = startTimer(100);
}

void GraphicsView::timerEvent(QTimerEvent *te) {
    qDebug() << "resized";
    emit resized();
    killTimer(te->timerId());
    timerId = 0;
}
