#ifndef MOVE_H
#define MOVE_H

#include <string>
#include <vector>

#include "type.h"
#include "mingl/mingl.h"
#include "mingl/gui/sprite.h"
#include "mingl/graphics/vec2d.h"
#include "mingl/shape/triangle.h"

using namespace std;

void clavier(MinGL &window, PacMan &pacman);
void dessiner(MinGL &window, PacMan &pacman, nsShape::Triangle &bouche);

#endif // MOVE_H
