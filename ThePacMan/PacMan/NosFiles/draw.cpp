#include "draw.h"

using namespace std;

void DrawGhost(MinGL & Window, const CMyParam & Parameters, const vector<GhostSprite> & VecteurGhost)
{
    for (auto & Ghost : VecteurGhost){
        Window << nsShape::Circle(Ghost.CenterPos, Ghost.Size, Ghost.Color);
        Window << nsShape::Rectangle(nsGraphics::Vec2D(Ghost.CenterPos.getX() - Ghost.Size, Ghost.CenterPos.getY()), Ghost.Size*2, Ghost.Color);
    }
}

void DrawBP(MinGL & Window, const CMyParam & Parameters, const map<bool, nsGraphics::Vec2D> & MapBP)
{
    unsigned sizeBP = Parameters.MapParamSize.find("BPSize")->second;
    for (auto & BP : MapBP){
        if (BP.first == false)
            Window << nsShape::Circle(BP.second, sizeBP, nsGraphics::KWhite);
    }
}

void DrawMurs(MinGL & Window, const CMyParam & Parameters, const vector<nsGraphics::Vec2D> & VecteurMurs)
{ 
    unsigned sizeMur = Parameters.MapParamSize.find("CaseSize")->second;
    for (size_t i (0); i < VecteurMurs.size(); ++i){
        Window << nsShape::Rectangle(VecteurMurs[i], sizeMur, sizeMur, nsGraphics::KBlue);
    }
}

void dessiner(MinGL &Window, PacMan & Pac, nsShape::Triangle & Bouche)
{
    // On dessine le Pac et on gère ses déplacements
    Window << nsShape::Circle (Pac.CenterPos, Pac.Size, nsGraphics::KYellow);
    if (Pac.DirectionActuelle== 'z'){
        Pac.BouchePosA = {Pac.CenterPos.getX()-20,Pac.CenterPos.getY()-Pac.Size};
        Pac.BouchePosB = {Pac.CenterPos.getX()+20,Pac.CenterPos.getY()-Pac.Size};}
    else if (Pac.DirectionActuelle== 's'){
        Pac.BouchePosA = {Pac.CenterPos.getX()-20,Pac.CenterPos.getY()+Pac.Size};
        Pac.BouchePosB = {Pac.CenterPos.getX()+20,Pac.CenterPos.getY()+Pac.Size};}
    else if (Pac.DirectionActuelle == 'q'){
        Pac.BouchePosA = {Pac.CenterPos.getX()-Pac.Size,Pac.CenterPos.getY()-20};
        Pac.BouchePosB = {Pac.CenterPos.getX()-Pac.Size,Pac.CenterPos.getY()+20};}
    else if (Pac.DirectionActuelle == 'd'){
        Pac.BouchePosA = {Pac.CenterPos.getX()+Pac.Size,Pac.CenterPos.getY()-20};
        Pac.BouchePosB = {Pac.CenterPos.getX()+Pac.Size,Pac.CenterPos.getY()+20};}
    Bouche.setFirstPosition(Pac.CenterPos);
    Bouche.setSecondPosition(Pac.BouchePosA);
    Bouche.setThirdPosition(Pac.BouchePosB);
    Window << bouche;
    if (Pac.DirectionActuelle == 'z' || Pac.DirectionActuelle == 's') {
        Window << nsShape::Triangle(Pac.CenterPos, {Pac.BouchePosA.getX()+10, Pac.BouchePosA.getY()},
                                    {Pac.BouchePosB.getX()-10, Pac.BouchePosB.getY()}, KBlack);
    } else {
        Window << nsShape::Triangle(Pac.CenterPos, {Pac.BouchePosA.getX(), Pac.BouchePosA.getY()+10},
                                                    {Pac.BouchePosB.getX(), Pac.BouchePosB.getY()-10}, KBlack);
    }
}
