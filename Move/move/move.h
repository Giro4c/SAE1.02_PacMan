#ifndef MOVE_H
#define MOVE_H

#include <vector>

#include "mingl/mingl.h"
#include "mingl/gui/sprite.h"
#include "mingl/graphics/vec2d.h"
#include "mingl/shape/triangle.h"

using namespace std;

struct Pacman
{
    nsGraphics::Vec2D Position;
    string DirectionActuelle;
    string DirectionPrecedent;
    unsigned vitesse;
    const unsigned rayon;
    nsGraphics::Vec2D BouchePosA;
    nsGraphics::Vec2D BouchePosB;
};

void clavier(MinGL &window, Pacman &pacman);
void dessiner(MinGL &window, Pacman &pacman, nsShape::Triangle &bouche);

#endif // MOVE_H
