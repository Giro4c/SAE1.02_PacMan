/**
 *
 * @file    pixel.h
 * @author  Camille Girodengo
 * @date    Janvier 2022
 * @version 1.0
 * @brief   Représente un pixel
 *
 **/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

#include "../transition/itransitionable.h"

namespace nsShape
{

/**
 * @class Pixel
 * @brief Classe représentant un pixel
 */
class Pixel : public Shape, public nsTransition::ITransitionable
{

public:
