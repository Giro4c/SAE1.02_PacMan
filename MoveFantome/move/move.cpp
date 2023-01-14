
#include <iostream>
#include <fstream>
#include <thread>
#include <vector>

#include "mingl/mingl.h"
#include "mingl/graphics/vec2d.h"
#include "mingl/shape/circle.h"
#include "mingl/shape/rectangle.h"
#include "move.h"

using namespace std;
using namespace nsGraphics;
using namespace nsGui;
using namespace chrono;

void clavier(MinGL &window, Ghost &ghost)
{
    // On vérifie si OKLM est pressé, et met a jour la position, pas de diagonale
    ghost.DirectionPrecedent= ghost.DirectionActuelle;
    if (window.isPressed({'o', false})){
        ghost.Position.setY(ghost.Position.getY() - ghost.vitesse);
            ghost.DirectionActuelle= "haut";
        }
    else if (window.isPressed({'l', false})){
        ghost.Position.setY(ghost.Position.getY() + ghost.vitesse);
        ghost.DirectionActuelle = "bas";
    }
    else if (window.isPressed({'k', false})){
        ghost.Position.setX(ghost.Position.getX() - ghost.vitesse);
        ghost.DirectionActuelle = "gauche";
    }
    else if (window.isPressed({'m', false})){
        ghost.Position.setX(ghost.Position.getX() + ghost.vitesse);
        ghost.DirectionActuelle = "droite";
    }
}

void dessiner(MinGL &window, Ghost &ghost)
{
    // On dessine le pacman et on gère ses déplacements
    window << nsShape::Circle (ghost.Position, 12, nsGraphics::KBlue);
    window << nsShape::Rectangle (nsGraphics::Vec2D(ghost.Position.getX() - 12, ghost.Position.getY()), nsGraphics::Vec2D(ghost.Position.getX() + 12, ghost.Position.getY() + 25 - 12), nsGraphics::KBlue);
    nsGraphics::Vec2D Position;
}
