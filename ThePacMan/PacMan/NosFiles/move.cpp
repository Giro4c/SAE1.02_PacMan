
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


void ChangeDirectionVars (PacMan & Pac, const CMyParam & Parameters, vector<nsGraphics::Vec2D> & VecteurMurs, map<string, unsigned> & MapNextMur,const unsigned & Combo, const char & Touche)
{
    Pac.DirectionPred = Pac.DirectionActuelle;
    Pac.DirectionActuelle = Touche;
    // Traduction : s'il y a changement de tarjectoire
    if (Pac.DirectionPred != Pac.DirectionActuelle){
        // Changement de direction donc nouvelle recherche du mur le plus proche
        MapNextMur["PacNextMur"] = CoNextMur(Pac, Parameters.MapParamSize.find("CaseSize")->second, VecteurMurs, Parameters);
        // Rétablissement de la vitesse par défaut ou max puisque la direction est forcément différente donc le PacMan n'a plus à faire de sur place
        if (Combo > 0)
            Pac.Vitesse = Parameters.MapParamSpeed.find("PacMaxSpeed")->second;
        else 
            Pac.Vitesse = Parameters.MapParamSpeed.find("PacDefaultSpeed")->second;
    }
}

void MovePac(MinGL & Window, const CMyParam & Parameters, PacMan & Pac, vector<nsGraphics::Vec2D> & VecteurMurs, map<string, unsigned> & MapNextMur,const unsigned & Combo)
{
    // On vérifie si ZQSD est pressé, et met a jour la direction, pas de diagonale
    if (Window.isPressed({Parameters.MapParamChar.find("PacKeyUp")->second, false})){
        ChangeDirectionVars(Pac, Parameters, VecteurMurs, MapNextMur, Combo, Parameters.MapParamChar.find("PacKeyUp")->second);
    }
    else if (Window.isPressed({Parameters.MapParamChar.find("PacKeyDown")->second, false})){
        ChangeDirectionVars(Pac, Parameters, VecteurMurs, MapNextMur, Combo, Parameters.MapParamChar.find("PacKeyDown")->second);
    }
    else if (Window.isPressed({Parameters.MapParamChar.find("PacKeyLeft")->second, false})){
        ChangeDirectionVars(Pac, Parameters, VecteurMurs, MapNextMur, Combo, Parameters.MapParamChar.find("PacKeyLeft")->second);
    }
    else if (Window.isPressed({Parameters.MapParamChar.find("PacKeyRight")->second, false})){
        ChangeDirectionVars(Pac, Parameters, VecteurMurs, MapNextMur, Combo, Parameters.MapParamChar.find("PacKeyRight")->second);
    }

    // Mise à jour de la position
    if (Pac.DirectionActuelle == Parameters.MapParamChar.find("PacKeyUp")->second){
        if (CollisionPacMur (Pac, Pac.Vitesse, Parameters, MapNextMur.find("PacNextMur")->second).first == true)
            Pac.Vitesse = CollisionPacMur (Pac, Pac.Vitesse, Parameters, MapNextMur.find("PacNextMur")->second).second;
        Pac.CenterPos.setY(Pac.CenterPos.getY() - Pac.Vitesse);
    }
    else if (Pac.DirectionActuelle == Parameters.MapParamChar.find("PacKeyDown")->second){
        if (CollisionPacMur (Pac, Pac.Vitesse, Parameters, MapNextMur.find("PacNextMur")->second).first == true)
            Pac.Vitesse = CollisionPacMur (Pac, Pac.Vitesse, Parameters, MapNextMur.find("PacNextMur")->second).second;
        Pac.CenterPos.setY(Pac.CenterPos.getY() + Pac.Vitesse);
    }
    else if (Pac.DirectionActuelle == Parameters.MapParamChar.find("PacKeyLeft")->second){
        if (CollisionPacMur (Pac, Pac.Vitesse, Parameters, MapNextMur.find("PacNextMur")->second).first == true)
            Pac.Vitesse = CollisionPacMur (Pac, Pac.Vitesse, Parameters, MapNextMur.find("PacNextMur")->second).second;
        Pac.CenterPos.setX(Pac.CenterPos.getX() - Pac.Vitesse);
    }
    else if (Pac.DirectionActuelle == Parameters.MapParamChar.find("PacKeyRight")->second){
        if (CollisionPacMur (Pac, Pac.Vitesse, Parameters, MapNextMur.find("PacNextMur")->second).first == true)
            Pac.Vitesse = CollisionPacMur (Pac, Pac.Vitesse, Parameters, MapNextMur.find("PacNextMur")->second).second;
        Pac.CenterPos.setX(Pac.CenterPos.getX() + Pac.Vitesse);
    }

}

void MoveGhost(MinGL & window, const CMyParam & Parameters, GhostSprite & ghost, vector<nsGraphics::Vec2D> & VecteurMurs, map<string, unsigned> & MapNextMur)
{
    // On vérifie si les touches de movement sont pressées, et met a jour la CenterPos, pas de diagonale
    ghost.DirectionPred = ghost.DirectionActuelle;
    if (ghost.ID == 1)
        if (window.isPressed({Parameters.MapParamChar.find("G1KeyUp")->second, false})){
            ghost.DirectionActuelle = Parameters.MapParamChar.find("G1KeyUp")->second;
            MapNextMur["G1NextMur"] = CoNextMur(ghost, Parameters.MapParamSize.find("CaseSize")->second, VecteurMurs, Parameters);
            if (CollisionGhostMur (ghost, ghost.Vitesse, Parameters, MapNextMur.find("G1NextMur")->second).first == false)
                ghost.CenterPos.setY(ghost.CenterPos.getY() - ghost.Vitesse);

        }
        else if (window.isPressed({Parameters.MapParamChar.find("G1KeyDown")->second, false})){
            ghost.DirectionActuelle = Parameters.MapParamChar.find("G1KeyDown")->second;
            MapNextMur["G1NextMur"] = CoNextMur(ghost, Parameters.MapParamSize.find("CaseSize")->second, VecteurMurs, Parameters);
            if (CollisionGhostMur (ghost, ghost.Vitesse, Parameters, MapNextMur.find("G1NextMur")->second).first == false)
                ghost.CenterPos.setY(ghost.CenterPos.getY() + ghost.Vitesse);
        }
        else if (window.isPressed({Parameters.MapParamChar.find("G1KeyLeft")->second, false})){
            ghost.DirectionActuelle = Parameters.MapParamChar.find("G1KeyLeft")->second;
            MapNextMur["G1NextMur"] = CoNextMur(ghost, Parameters.MapParamSize.find("CaseSize")->second, VecteurMurs, Parameters);
            if (CollisionGhostMur (ghost, ghost.Vitesse, Parameters, MapNextMur.find("G1NextMur")->second).first == false)
                ghost.CenterPos.setX(ghost.CenterPos.getX() - ghost.Vitesse);
        }
        else if (window.isPressed({Parameters.MapParamChar.find("G1KeyRight")->second, false})){
            ghost.DirectionActuelle = Parameters.MapParamChar.find("G1KeyLeft")->second;
            MapNextMur["G1NextMur"] = CoNextMur(ghost, Parameters.MapParamSize.find("CaseSize")->second, VecteurMurs, Parameters);
            if (CollisionGhostMur (ghost, ghost.Vitesse, Parameters, MapNextMur.find("G1NextMur")->second).first == false)
                ghost.CenterPos.setX(ghost.CenterPos.getX() + ghost.Vitesse);
        }
    if (ghost.ID == 2)
        if (window.isPressed({Parameters.MapParamChar.find("G2KeyUp")->second, false})){
            ghost.DirectionActuelle = Parameters.MapParamChar.find("G2KeyUp")->second;
            MapNextMur["G2NextMur"] = CoNextMur(ghost, Parameters.MapParamSize.find("CaseSize")->second, VecteurMurs, Parameters);
            if (CollisionGhostMur (ghost, ghost.Vitesse, Parameters, MapNextMur.find("G2NextMur")->second).first == false)
                ghost.CenterPos.setY(ghost.CenterPos.getY() - ghost.Vitesse);

        }
        else if (window.isPressed({Parameters.MapParamChar.find("G2KeyDown")->second, false})){
            ghost.DirectionActuelle = Parameters.MapParamChar.find("G2KeyDown")->second;
            MapNextMur["G2NextMur"] = CoNextMur(ghost, Parameters.MapParamSize.find("CaseSize")->second, VecteurMurs, Parameters);
            if (CollisionGhostMur (ghost, ghost.Vitesse, Parameters, MapNextMur.find("G2NextMur")->second).first == false)
                ghost.CenterPos.setY(ghost.CenterPos.getY() + ghost.Vitesse);
        }
        else if (window.isPressed({Parameters.MapParamChar.find("G2KeyLeft")->second, false})){
            ghost.DirectionActuelle = Parameters.MapParamChar.find("G2KeyLeft")->second;
            MapNextMur["G2NextMur"] = CoNextMur(ghost, Parameters.MapParamSize.find("CaseSize")->second, VecteurMurs, Parameters);
            if (CollisionGhostMur (ghost, ghost.Vitesse, Parameters, MapNextMur.find("G2NextMur")->second).first == false)
                ghost.CenterPos.setX(ghost.CenterPos.getX() - ghost.Vitesse);
        }
        else if (window.isPressed({Parameters.MapParamChar.find("G2KeyRight")->second, false})){
            ghost.DirectionActuelle = Parameters.MapParamChar.find("G2KeyLeft")->second;
            MapNextMur["G2NextMur"] = CoNextMur(ghost, Parameters.MapParamSize.find("CaseSize")->second, VecteurMurs, Parameters);
            if (CollisionGhostMur (ghost, ghost.Vitesse, Parameters, MapNextMur.find("G2NextMur")->second).first == false)
                ghost.CenterPos.setX(ghost.CenterPos.getX() + ghost.Vitesse);
        }
}
