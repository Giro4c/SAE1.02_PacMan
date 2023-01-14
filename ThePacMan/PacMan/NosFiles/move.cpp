#include <fstream>
#include <thread>
#include <vector>

#include "move.h"
#include "mingl/mingl.h"
#include "mingl/graphics/vec2d.h"

using namespace std;
using namespace nsGraphics;
using namespace nsGui;
using namespace chrono;


void ChangeDirectionVars (PacMan & Pac, const CMyParam & Parameters, const vector<nsGraphics::Vec2D> & VecteurMurs, map<string, unsigned> & MapNextMur,const unsigned & Combo, const char & Touche)
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

void clavier(MinGL & Window, const CMyParam & Parameters, PacMan & Pac, const vector<nsGraphics::Vec2D> & VecteurMurs, map<string, unsigned> & MapNextMur,const unsigned & Combo)
{
    // On vérifie si ZQSD est pressé, et met a jour la direction, pas de diagonale
    if (Window.isPressed({Parameters.MapParamChar.find("PacKeyUp")->second, false})){
        ChangeDirectionVars(Pac, Parameters, VecteurMurs, MapNextMur, Combo, Parameters.MapParamChar.find("PacKeyUp")->second);
    }
    else if (Window.isPressed({Parameters.MapParamChar.find("PacKeyDown")->second, false})){
        ChangeDirectionVars(Pac, Parameters, VecteurMurs, MapNextMur, Combo, Parameters.MapParamChar.find("PacKeyUp")->second);
    }
    else if (Window.isPressed({Parameters.MapParamChar.find("PacKeyLeft")->second, false})){
        ChangeDirectionVars(Pac, Parameters, VecteurMurs, MapNextMur, Combo, Parameters.MapParamChar.find("PacKeyUp")->second);
    }
    else if (Window.isPressed({Parameters.MapParamChar.find("PacKeyRight")->second, false})){
        ChangeDirectionVars(Pac, Parameters, VecteurMurs, MapNextMur, Combo, Parameters.MapParamChar.find("PacKeyUp")->second);
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
        Pac.CenterPos.setY(Pac.CenterPos.getY() + Pac.vitesse);
    }
    else if (Pac.DirectionActuelle == Parameters.MapParamChar.find("PacKeyLeft")->second){
        if (CollisionPacMur (Pac, Pac.Vitesse, Parameters, MapNextMur.find("PacNextMur")->second).first == true)
            Pac.Vitesse = CollisionPacMur (Pac, Pac.Vitesse, Parameters, MapNextMur.find("PacNextMur")->second).second;
        Pac.CenterPos.setX(Pac.CenterPos.getX() - Pac.vitesse);
    }
    else if (Pac.DirectionActuelle == Parameters.MapParamChar.find("PacKeyRight")->second){
        if (CollisionPacMur (Pac, Pac.Vitesse, Parameters, MapNextMur.find("PacNextMur")->second).first == true)
            Pac.Vitesse = CollisionPacMur (Pac, Pac.Vitesse, Parameters, MapNextMur.find("PacNextMur")->second).second;
        Pac.CenterPos.setX(Pac.CenterPos.getX() + Pac.vitesse);
    }

}
