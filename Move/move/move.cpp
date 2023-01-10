
#include <iostream>
#include <fstream>
#include <thread>
#include <vector>

#include "mingl/mingl.h"
#include "mingl/graphics/vec2d.h"
#include "mingl/shape/circle.h"
#include "mingl/shape/triangle.h"
#include "move.h"

using namespace std;
using namespace nsGraphics;
using namespace nsGui;
using namespace chrono;

void clavier(MinGL &window, Pacman &pacman)
{
    // On vérifie si ZQSD est pressé, et met a jour la position
    pacman.DirectionPrecedent= pacman.DirectionActuelle;
    if (window.isPressed({'z', false})){
        pacman.Position.setY(pacman.Position.getY() - pacman.vitesse);
            pacman.DirectionActuelle= "haut";
        }
    else if (window.isPressed({'s', false})){
        pacman.Position.setY(pacman.Position.getY() + pacman.vitesse);
        pacman.DirectionActuelle = "bas";
    }
    else if (window.isPressed({'q', false})){
        pacman.Position.setX(pacman.Position.getX() - pacman.vitesse);
        pacman.DirectionActuelle = "gauche";
    }
    else if (window.isPressed({'d', false})){
        pacman.Position.setX(pacman.Position.getX() + pacman.vitesse);
        pacman.DirectionActuelle = "droite";
    }
}

void dessiner(MinGL &window, Pacman &pacman, nsShape::Triangle &bouche)
{
    // On dessine le rectangle
    window << nsShape::Circle (pacman.Position, 25, nsGraphics::KYellow);
    if (pacman.DirectionActuelle== "haut"){
        pacman.BouchePosA = {pacman.Position.getX()-20,pacman.Position.getY()-25};
        pacman.BouchePosB = {pacman.Position.getX()+20,pacman.Position.getY()-25};}
    else if (pacman.DirectionActuelle== "bas"){
        pacman.BouchePosA = {pacman.Position.getX()-20,pacman.Position.getY()+25};
        pacman.BouchePosB = {pacman.Position.getX()+20,pacman.Position.getY()+25};}
    else if (pacman.DirectionActuelle == "gauche"){
        pacman.BouchePosA = {pacman.Position.getX()-25,pacman.Position.getY()-20};
        pacman.BouchePosB = {pacman.Position.getX()-25,pacman.Position.getY()+20};}
    else if (pacman.DirectionActuelle == "droite"){
        pacman.BouchePosA = {pacman.Position.getX()+25,pacman.Position.getY()-20};
        pacman.BouchePosB = {pacman.Position.getX()+25,pacman.Position.getY()+20};}
    bouche.setFirstPosition(pacman.Position);
    bouche.setSecondPosition(pacman.BouchePosA);
    bouche.setThirdPosition(pacman.BouchePosB);
    window << bouche;
    if (pacman.DirectionActuelle == "haut" || pacman.DirectionActuelle == "bas") {
        window << nsShape::Triangle(pacman.Position, {pacman.BouchePosA.getX()+10, pacman.BouchePosA.getY()},
                                    {pacman.BouchePosB.getX()-10, pacman.BouchePosB.getY()}, KBlack);
    } else {
        window << nsShape::Triangle(pacman.Position, {pacman.BouchePosA.getX(), pacman.BouchePosA.getY()+10},
                                                    {pacman.BouchePosB.getX(), pacman.BouchePosB.getY()-10}, KBlack);
    }
}
