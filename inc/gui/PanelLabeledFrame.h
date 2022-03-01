//
// Created by daniil on 20.02.2022.
//

#pragma once

#include <QFrame>
#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QSpacerItem>

class PanelLabeledFrame : public QFrame {
    QVBoxLayout* _baseLayout;
    QWidget* _contents;
    QLabel* _label;
public:
    QGridLayout* layout;
    explicit PanelLabeledFrame(const std::string& label) {
        setFrameStyle(QFrame::Panel);
        setLineWidth(2);
        _baseLayout = new QVBoxLayout;
        setLayout(_baseLayout);
        _label = new QLabel(label.c_str());
        _baseLayout->addWidget(_label);
        _contents = new QWidget;
        _baseLayout->addWidget(_contents);
        layout = new QGridLayout;
        _contents->setLayout(layout);

        _baseLayout->setSpacing(0);
        _baseLayout->addStretch();
    }
};


