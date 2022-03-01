//
// Created by daniil on 23.02.2022.
//

#pragma once

#include <QResizeEvent>
#include <QGraphicsView>

class GraphicsView : public QGraphicsView {
    Q_OBJECT
private:
    int timerId = 0;
public:
    GraphicsView() : QGraphicsView() {
        this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    }
    void resizeEvent(QResizeEvent *) override;

    void timerEvent(QTimerEvent *te) override;
signals:
    void resized();
};


