
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

void ChangeDirectionVars (GhostSprite & Ghost, const CMyParam & Parameters, vector<nsGraphics::Vec2D> & VecteurMurs, map<string, unsigned> & MapNextMur,const unsigned & Combo, const char & Touche)
{
    Ghost.DirectionPred = Ghost.DirectionActuelle;
    Ghost.DirectionActuelle = Touche;
    // Traduction : s'il y a changement de tarjectoire
    if (Ghost.DirectionPred != Ghost.DirectionActuelle){
        // Changement de direction donc nouvelle recherche du mur le plus proche
        MapNextMur["G" + string(Ghost.ID) + "NextMur"] = CoNextMur(Ghost, Parameters.MapParamSize.find("CaseSize")->second, VecteurMurs, Parameters);
        // Rétablissement de la vitesse par défaut
        Ghost.Vitesse = Parameters.MapParamSpeed.find("GhostSpeed")->second;
    }
}


void MoveGhost(MinGL & window, const CMyParam & Parameters, GhostSprite & ghost, vector<nsGraphics::Vec2D> & VecteurMurs, map<string, unsigned> & MapNextMur)
{
    // On vérifie si les touches de movement sont pressées, et met a jour la CenterPos, pas de diagonale
    ghost.DirectionPred = ghost.DirectionActuelle;
    if (window.isPressed({Parameters.MapParamChar.find("G" + string(ghost.ID) + "KeyUp")->second, false})){
        ghost.DirectionActuelle = Parameters.MapParamChar.find("G" + string(ghost.ID) + "KeyUp")->second;
        MapNextMur["G" + string(ghost.ID) + "NextMur"] = CoNextMur(ghost, Parameters.MapParamSize.find("CaseSize")->second, VecteurMurs, Parameters);
        if (CollisionPacMur (Pac, Pac.Vitesse, Parameters, MapNextMur.find("G" + string(ghost.ID) + "NextMur")->second).first == true) break;
        ghost.CenterPos.setY(ghost.CenterPos.getY() - ghost.Vitesse);

    }
    else if (window.isPressed({Parameters.MapParamChar.find("G" + string(ghost.ID) + "KeyDown")->second, false})){
        ghost.DirectionActuelle = Parameters.MapParamChar.find("G" + string(ghost.ID) + "KeyDown")->second;
        MapNextMur["G" + string(ghost.ID) + "NextMur"] = CoNextMur(ghost, Parameters.MapParamSize.find("CaseSize")->second, VecteurMurs, Parameters);
        if (CollisionPacMur (Pac, Pac.Vitesse, Parameters, MapNextMur.find("G" + string(ghost.ID) + "NextMur")->second).first == true) break;
        ghost.CenterPos.setY(ghost.CenterPos.getY() + ghost.Vitesse);
    }
    else if (window.isPressed({Parameters.MapParamChar.find("G" + string(ghost.ID) + "KeyLeft")->second, false})){
        ghost.DirectionActuelle = Parameters.MapParamChar.find("G" + string(ghost.ID) + "KeyLeft")->second;
        MapNextMur["G" + string(ghost.ID) + "NextMur"] = CoNextMur(ghost, Parameters.MapParamSize.find("CaseSize")->second, VecteurMurs, Parameters);
        if (CollisionPacMur (Pac, Pac.Vitesse, Parameters, MapNextMur.find("G" + string(ghost.ID) + "NextMur")->second).first == true) break;
        ghost.CenterPos.setX(ghost.CenterPos.getX() - ghost.Vitesse);
    }
    else if (window.isPressed({Parameters.MapParamChar.find("G" + string(ghost.ID) + "KeyRight")->second, false})){
        ghost.DirectionActuelle = Parameters.MapParamChar.find("G" + string(ghost.ID) + "KeyRight")->second;
        MapNextMur["G" + string(ghost.ID) + "NextMur"] = CoNextMur(ghost, Parameters.MapParamSize.find("CaseSize")->second, VecteurMurs, Parameters);
        if (CollisionPacMur (Pac, Pac.Vitesse, Parameters, MapNextMur.find("G" + string(ghost.ID) + "NextMur")->second).first == true) break;
        ghost.CenterPos.setX(ghost.CenterPos.getX() + ghost.Vitesse);
    }
}

void dessiner(MinGL &window, Ghost &ghost)
{
    // On dessine le pacman et on gère ses déplacements
    window << nsShape::Circle (ghost.CenterPos, 12, nsGraphics::KBlue);
    window << nsShape::Rectangle (nsGraphics::Vec2D(ghost.CenterPos.getX() - 12, ghost.CenterPos.getY()), nsGraphics::Vec2D(ghost.CenterPos.getX() + 12, ghost.CenterPos.getY() + 25 - 12), nsGraphics::KBlue);
    nsGraphics::Vec2D CenterPos;
}
