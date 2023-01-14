
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

void Dessiner(MinGL &Window, PacMan &Pac, nsShape::Triangle &bouche)
{
    // On dessine le Pac et on gère ses déplacements
    Window << nsShape::Circle (Pac.CenterPos, 25, nsGraphics::KYellow);
    if (Pac.DirectionActuelle== 'z'){
        Pac.BouchePosA = {Pac.CenterPos.getX()-20,Pac.CenterPos.getY()-25};
        Pac.BouchePosB = {Pac.CenterPos.getX()+20,Pac.CenterPos.getY()-25};}
    else if (Pac.DirectionActuelle== 's'){
        Pac.BouchePosA = {Pac.CenterPos.getX()-20,Pac.CenterPos.getY()+25};
        Pac.BouchePosB = {Pac.CenterPos.getX()+20,Pac.CenterPos.getY()+25};}
    else if (Pac.DirectionActuelle == 'q'){
        Pac.BouchePosA = {Pac.CenterPos.getX()-25,Pac.CenterPos.getY()-20};
        Pac.BouchePosB = {Pac.CenterPos.getX()-25,Pac.CenterPos.getY()+20};}
    else if (Pac.DirectionActuelle == 'd'){
        Pac.BouchePosA = {Pac.CenterPos.getX()+25,Pac.CenterPos.getY()-20};
        Pac.BouchePosB = {Pac.CenterPos.getX()+25,Pac.CenterPos.getY()+20};}
    bouche.setFirstPosition(Pac.CenterPos);
    bouche.setSecondPosition(Pac.BouchePosA);
    bouche.setThirdPosition(Pac.BouchePosB);
    Window << bouche;
    if (Pac.DirectionActuelle == 'z' || Pac.DirectionActuelle == 's') {
        Window << nsShape::Triangle(Pac.CenterPos, {Pac.BouchePosA.getX()+10, Pac.BouchePosA.getY()},
                                    {Pac.BouchePosB.getX()-10, Pac.BouchePosB.getY()}, KBlack);
    } else {
        Window << nsShape::Triangle(Pac.CenterPos, {Pac.BouchePosA.getX(), Pac.BouchePosA.getY()+10},
                                                    {Pac.BouchePosB.getX(), Pac.BouchePosB.getY()-10}, KBlack);
    }
}
