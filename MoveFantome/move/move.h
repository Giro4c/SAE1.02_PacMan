#ifndef MOVE_H
#define MOVE_H

#include <string>
#include <vector>

#include "mingl/mingl.h"
#include "mingl/gui/sprite.h"
#include "mingl/graphics/vec2d.h"
#include "mingl/shape/triangle.h"

using namespace std;

struct Ghost{
    nsGraphics::Vec2D Position;
    string DirectionActuelle;
    string DirectionPrecedent;
    unsigned vitesse;
};

void clavier(MinGL &window, Ghost &ghost);
void dessiner(MinGL &window, Ghost &ghost);
#endif // MOVE_H
