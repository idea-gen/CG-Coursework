//
// Created by daniil on 17.02.2022.
//

#include "BackfaceCuller.h"

Matrix<4, 4, double> BackfaceCuller::_model = Matrix<4, 4, double>::Identity();
Matrix<4, 4, double> BackfaceCuller::_view = Matrix<4, 4, double>::Identity();
Matrix<4, 4, double> BackfaceCuller::_matrix = Matrix<4, 4, double>::Identity();