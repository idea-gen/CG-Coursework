//
// Created by daniil on 15.02.2022.
//

#include "VertexShader.h"

Matrix<4, 4, double> VertexShader::_model = Matrix<4, 4, double>::Identity();
Matrix<4, 4, double> VertexShader::_view = Matrix<4, 4, double>::Identity();
Matrix<4, 4, double> VertexShader::_projection = Matrix<4, 4, double>::Identity();
Matrix<4, 4, double> VertexShader::_viewport = Matrix<4, 4, double>::Identity();
Matrix<4, 4, double> VertexShader::_mvpv = Matrix<4, 4, double>::Identity();
