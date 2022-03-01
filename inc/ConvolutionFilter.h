//
// Created by daniil on 24.02.2022.
//

#pragma once

#include "IPixelReceiver.h"
#include <memory>
#include <utility>

class ConvolutionFilter {
public:
    std::shared_ptr<IPixelReceiver> _pReceiver;
    explicit ConvolutionFilter(std::shared_ptr<IPixelReceiver> pReceiver) : _pReceiver(std::move(pReceiver)) {};
    void filter() {
        auto lastW = _pReceiver->width() - 1;
        auto lastH = _pReceiver->height() - 1;
        std::shared_ptr<IPixelReceiver> pFilter = _pReceiver->createCopy();
        { // corners
//            Color tl = (pFilter->pixelColor(0, 0) * 16. + pFilter->pixelColor(0, 1) * 4. +
//                    pFilter->pixelColor(1, 0) * 4. + pFilter->pixelColor(1, 1)) / 25.;
            Color tl = (pFilter->pixelColor(0, 0) + pFilter->pixelColor(0, 1) +
                        pFilter->pixelColor(1, 0) + pFilter->pixelColor(1, 1)) / 4.;
            _pReceiver->setPixelColor(0, 0, tl);
//            Color tr = (pFilter->pixelColor(lastW, 0) * 16. + pFilter->pixelColor(lastW, 1) * 4. +
//                        pFilter->pixelColor(lastW - 1, 0) * 4. + pFilter->pixelColor(lastW - 1, 1)) / 25.;
            Color tr = (pFilter->pixelColor(lastW, 0) + pFilter->pixelColor(lastW, 1) +
                        pFilter->pixelColor(lastW - 1, 0) + pFilter->pixelColor(lastW - 1, 1)) / 4.;
            _pReceiver->setPixelColor(0, 0, tr);
//            Color bl = (pFilter->pixelColor(0, lastH) * 16. + pFilter->pixelColor(0, lastH - 1) * 4. +
//                        pFilter->pixelColor(1, lastH) * 4. + pFilter->pixelColor(1, lastH - 1)) / 25.;
            Color bl = (pFilter->pixelColor(0, lastH) + pFilter->pixelColor(0, lastH - 1) +
                        pFilter->pixelColor(1, lastH) + pFilter->pixelColor(1, lastH - 1)) / 4.;
            _pReceiver->setPixelColor(0, 0, bl);
//            Color br = (pFilter->pixelColor(lastW, lastH) * 16. + pFilter->pixelColor(lastW, lastH - 1) * 4. +
//                        pFilter->pixelColor(lastW - 1, lastH) * 4. +
//                        pFilter->pixelColor(lastW - 1, lastH - 1)) / 25.;
            Color br = (pFilter->pixelColor(lastW, lastH) + pFilter->pixelColor(lastW, lastH - 1) +
                        pFilter->pixelColor(lastW - 1, lastH) +
                        pFilter->pixelColor(lastW - 1, lastH - 1)) / 4.;
            _pReceiver->setPixelColor(0, 0, br);
        }
        { // edges
            for (int i = 1, y = 0; i < lastW; i++) {
//                Color res = (pFilter->pixelColor(i, y) * 16. + pFilter->pixelColor(i + 1, y) * 4. +
//                        pFilter->pixelColor(i - 1, y) * 4. + pFilter->pixelColor(i, y + 1) * 4. +
//                        pFilter->pixelColor(i - 1, y + 1) + pFilter->pixelColor(i + 1, y + 1)) / 30.;
                Color res = (pFilter->pixelColor(i, y) + pFilter->pixelColor(i + 1, y) +
                             pFilter->pixelColor(i - 1, y) + pFilter->pixelColor(i, y + 1) +
                             pFilter->pixelColor(i - 1, y + 1) + pFilter->pixelColor(i + 1, y + 1)) / 6.;
                _pReceiver->setPixelColor(i, 0, res);
            }
            for (int i = 1, y = lastH; i < lastW; i++) {
//                Color res = (pFilter->pixelColor(i, y) * 16. + pFilter->pixelColor(i + 1, y) * 4. +
//                             pFilter->pixelColor(i - 1, y) * 4. + pFilter->pixelColor(i, y - 1) * 4. +
//                             pFilter->pixelColor(i - 1, y - 1) + pFilter->pixelColor(i + 1, y - 1)) / 30.;
                Color res = (pFilter->pixelColor(i, y) + pFilter->pixelColor(i + 1, y) +
                             pFilter->pixelColor(i - 1, y) + pFilter->pixelColor(i, y - 1) +
                             pFilter->pixelColor(i - 1, y - 1) + pFilter->pixelColor(i + 1, y - 1)) / 6.;
                _pReceiver->setPixelColor(i, y, res);
            }
            for (int i = 1, x = 0; i < lastH; i++) {
//                Color res = (pFilter->pixelColor(x, i) * 16. + pFilter->pixelColor(x, i + 1) * 4. +
//                             pFilter->pixelColor(x, i - 1) * 4. + pFilter->pixelColor(x + 1, i) * 4. +
//                             pFilter->pixelColor(x + 1, i - 1) + pFilter->pixelColor(x + 1, i + 1)) / 30.;
                Color res = (pFilter->pixelColor(x, i) + pFilter->pixelColor(x, i + 1) +
                             pFilter->pixelColor(x, i - 1) + pFilter->pixelColor(x + 1, i) +
                             pFilter->pixelColor(x + 1, i - 1) + pFilter->pixelColor(x + 1, i + 1)) / 6.;
                _pReceiver->setPixelColor(x, i, res);
            }
            for (int i = 1, x = lastW; i < lastH; i++) {
//                Color res = (pFilter->pixelColor(x, i) * 16. + pFilter->pixelColor(x, i + 1) * 4. +
//                             pFilter->pixelColor(x, i - 1) * 4. + pFilter->pixelColor(x - 1, i) * 4. +
//                             pFilter->pixelColor(x - 1, i - 1) + pFilter->pixelColor(x - 1, i + 1)) / 30.;
                Color res = (pFilter->pixelColor(x, i) + pFilter->pixelColor(x, i + 1) +
                             pFilter->pixelColor(x, i - 1) + pFilter->pixelColor(x - 1, i) +
                             pFilter->pixelColor(x - 1, i - 1) + pFilter->pixelColor(x - 1, i + 1)) / 6.;
                _pReceiver->setPixelColor(x, i, res);
            }
        }
        for (int x = 1; x < lastW; x++) {
            for (int y = 1; y < lastH; y++) {
//                Color res = (pFilter->pixelColor(x, y) * 16. + pFilter->pixelColor(x + 1, y) * 4. +
//                        pFilter->pixelColor(x - 1, y) * 4. + pFilter->pixelColor(x, y + 1) * 4. +
//                        pFilter->pixelColor(x, y - 1) * 4. + pFilter->pixelColor(x - 1, y - 1) +
//                        pFilter->pixelColor(x + 1, y - 1) + pFilter->pixelColor(x - 1, y + 1) +
//                        pFilter->pixelColor(x + 1, y + 1)) / 36.;
                Color res = (pFilter->pixelColor(x, y) + pFilter->pixelColor(x + 1, y) +
                             pFilter->pixelColor(x - 1, y) + pFilter->pixelColor(x, y + 1) +
                             pFilter->pixelColor(x, y - 1)  + pFilter->pixelColor(x - 1, y - 1) +
                             pFilter->pixelColor(x + 1, y - 1) + pFilter->pixelColor(x - 1, y + 1) +
                             pFilter->pixelColor(x + 1, y + 1)) / 9.;
                _pReceiver->setPixelColor(x, y, res);
            }
        }
    }
};


