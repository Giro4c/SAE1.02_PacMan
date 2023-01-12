#include "collision.h"

using namespace std;

/* ************************  PacMan / Mur  ************************** */

unsigned CoNextMur (const PacMan & Pac, const unsigned & CaseSize, const vector<Cposition> & VecteurMurs, const CMyParam & Parameters)
{
    // Si direction vers le haut
    if (Pac.DirectionActuelle == MapParamStrPac.find("TurnUp")->second){
        unsigned ValCoNextMurY (0);
        for (Cposition & Mur : VecteurMurs){

            if (Mur.getY() + CaseSize <= Pac.CenterPos.getY()){ // Traduction sur la fenetre : point au dessus de pacman
                if (Pac.CenterPos.getX() - Pac.size <= Mur.getX() && Mur.getX() <= Pac.CenterPos.getX() + Pac.size){
                    ValCoNextMurY = max(ValCoNextMurY, Mur.getY() + CaseSize);
                }
                else if (Pac.CenterPos.getX() - Pac.size <= Mur.getX() + CaseSize && Mur.getX() + CaseSize <= Pac.CenterPos.getX() + Pac.size){
                    ValCoNextMurY = max(ValCoNextMurY, Mur.getY() + CaseSize);
                }
            }
            // Else if car (y + CaseSize) est forcément plus grand que (y) sachant que CaseSize >= 0
            else if (Mur.getY() <= Pac.CenterPos.getY()){ // Traduction sur la fenetre : point au dessus de pacman
                if (Pac.CenterPos.getX() - Pac.size <= Mur.getX() && Mur.getX() <= Pac.CenterPos.getX() + Pac.size){
                    ValCoNextMurY = max(ValCoNextMurY, Mur.getY());
                }
                else if (Pac.CenterPos.getX() - Pac.size <= Mur.getX() + CaseSize && Mur.getX() + CaseSize <= Pac.CenterPos.getX() + Pac.size){
                    ValCoNextMurY = max(ValCoNextMurY, Mur.getY());
                }
            }

        }
        return ValCoNextMurY;
    }
    // Si direction vers le bas
    else if (Pac.DirectionActuelle == MapParamStrPac.find("TurnDown")->second){
        unsigned ValCoNextMurY (Parameters.MapParamUnsigned.find("WindowHeight")->second);
        for (Cposition & Mur : VecteurMurs){

            if (Mur.getY() >= Pac.CenterPos.getY()){ // Traduction sur la fenetre : point au dessus de pacman
                if (Pac.CenterPos.getX() - Pac.size <= Mur.getX() && Mur.getX() <= Pac.CenterPos.getX() + Pac.size){
                    ValCoNextMurY = min(ValCoNextMurY, Mur.getY());
                }
                else if (Pac.CenterPos.getX() - Pac.size <= Mur.getX() + CaseSize && Mur.getX() + CaseSize <= Pac.CenterPos.getX() + Pac.size){
                    ValCoNextMurY = min(ValCoNextMurY, Mur.getY());
                }
            }
            // Else if car (y) est forcément plus petit que (y + CaseSize) sachant que CaseSize >= 0            
            else if (Mur.getY() + CaseSize >= Pac.CenterPos.getY()){ // Traduction sur la fenetre : point au dessus de pacman
                if (Pac.CenterPos.getX() - Pac.size <= Mur.getX() && Mur.getX() <= Pac.CenterPos.getX() + Pac.size){
                    ValCoNextMurY = min(ValCoNextMurY, Mur.getY() + CaseSize);
                }
                else if (Pac.CenterPos.getX() - Pac.size <= Mur.getX() + CaseSize && Mur.getX() + CaseSize <= Pac.CenterPos.getX() + Pac.size){
                    ValCoNextMurY = min(ValCoNextMurY, Mur.getY() + CaseSize);
                }
            }

        }
        return ValCoNextMurY;
    }
    // Si direction à gauche
    else if (Pac.DirectionActuelle == MapParamStrPac.find("TurnLeft")->second){
        unsigned ValCoNextMurX (0);
        for (Cposition & Mur : VecteurMurs){

            if (Mur.getX() + CaseSize <= Pac.CenterPos.getX()){ // Traduction sur la fenetre : point à gauche de pacman
                if (Pac.CenterPos.getY() - Pac.size <= Mur.getY() && Mur.getY() <= Pac.CenterPos.getY() + Pac.size){
                    ValCoNextMurX = max(ValCoNextMurX, Mur.getX() + CaseSize);
                }
                if (Pac.CenterPos.getY() - Pac.size <= Mur.getY() + CaseSize && Mur.getY() + CaseSize <= Pac.CenterPos.getY() + Pac.size){
                    ValCoNextMurX = max(ValCoNextMurX, Mur.getX() + CaseSize);
                }
            }
            // Else if car (x + CaseSize) est forcément plus grand que (x) sachant que CaseSize >= 0
            if (Mur.getX() <= Pac.CenterPos.getX()){ // Traduction sur la fenetre : point à gauche de pacman
                if (Pac.CenterPos.getY() - Pac.size <= Mur.getY() && Mur.getY() <= Pac.CenterPos.getY() + Pac.size){
                    ValCoNextMurX = max(ValCoNextMurX, Mur.getX());
                }
                if (Pac.CenterPos.getY() - Pac.size <= Mur.getY() + CaseSize && Mur.getY() + CaseSize <= Pac.CenterPos.getY() + Pac.size){
                    ValCoNextMurX = max(ValCoNextMurX, Mur.getX());
                }
            }

        }
        return ValCoNextMurX;
    }
    // Si direction à droite
    else if (Pac.DirectionActuelle == Parameters.MapParamStrPac.find("TurnRight")->second){
        unsigned ValCoNextMurX (Parameters.MapParamUnsigned.find("WindowWidth")->second);
        for (Cposition & Mur : VecteurMurs){

            if (Mur.getX() <= Pac.CenterPos.getX()){ // Traduction sur la fenetre : point à gauche de pacman
                if (Pac.CenterPos.getY() - Pac.size <= Mur.getY() && Mur.getY() <= Pac.CenterPos.getY() + Pac.size){
                    ValCoNextMurX = min(ValCoNextMurX, Mur.getX());
                }
                if (Pac.CenterPos.getY() - Pac.size <= Mur.getY() + CaseSize && Mur.getY() + CaseSize <= Pac.CenterPos.getY() + Pac.size){
                    ValCoNextMurX = min(ValCoNextMurX, Mur.getX());
                }
            }
            // Else if car (x) est forcément plus petit que (x + CaseSize) sachant que CaseSize >= 0            
            else if (Mur.getX() + CaseSize <= Pac.CenterPos.getX()){ // Traduction sur la fenetre : point à gauche de pacman
                if (Pac.CenterPos.getY() - Pac.size <= Mur.getY() && Mur.getY() <= Pac.CenterPos.getY() + Pac.size){
                    ValCoNextMurX = min(ValCoNextMurX, Mur.getX() + CaseSize);
                }
                if (Pac.CenterPos.getY() - Pac.size <= Mur.getY() + CaseSize && Mur.getY() + CaseSize <= Pac.CenterPos.getY() + Pac.size){
                    ValCoNextMurX = min(ValCoNextMurX, Mur.getX() + CaseSize);
                }
            }

        }
        return ValCoNextMurX;
    }
    else
        return 0;
}

pair <bool, unsigned> CollisionPacMur (const PacMan & Pac, const unsigned & Vitesse, const CMyParam & Parameters, const unsigned & ValCoNextMur)
{    
    // Déclaration des coordonnées d'extrémités dépendantes de la direction actuelle du pacman
    unsigned xVerif; // Coordonnées x max du point potentiel de contact
    unsigned yVerif; // Coordonnées y max du point potentiel de contact

    // Vérification en fonction de la direction actuelle du PacMan
    // Haut
    if (Pac.DirectionActuelle == MapParamStrPac.find("TurnUp")->second){
        yVerif = Pac.CenterPos.getY() - Pac.Size - Vitesse;
        if (ValCoNextMur >= yVerif)
            return {true, PointMur.getY() - yVerif - 1};
        else 
            return {false, 0}; // Puisque pas de collision
    }
    // Bas
    else if (Pac.Direction == MapParamStrPac.find("TurnDown")->second){
        yVerif = Pac.CenterPos.getY() + Pac.Size + Vitesse;
        if (ValCoNextMur <= yVerif)
            return {true, yVerif - PointMur.getY() - 1};
        else
            return {false, 0}; // Puisque pas de collision
    }
    // Gauche
    else if (Pac.Direction == MapParamStrPac.find("TurnLeft")->second){
        xVerif = Pac.CenterPos.getX() - Pac.Size - Vitesse;
        if (ValCoNextMur >= xVerif)
            return {true, PointMur.getx() - xVerif - 1};
        else
            return {false, 0}; // Puisque pas de collision
    }
    else if (Pac.Direction == MapParamStrPac.find("TurnRight")->second){
        xVerif = Pac.CenterPos.getX() + Pac.Size + Vitesse;
        if (ValCoNextMur <= xVerif)
            return {true, xVerif - PointMur.getx() - 1};
        else
            return {false, 0}; // Puisque pas de collision
    }
    else 
        return {false, 0}; // Puisque pas de collision car mauvaise direction en entrée
}

/* ************************  PacMan / Fantome (Ghost) ************************** */

bool xFInsideHitBoxPacX (const unsigned & XCenterPac, const unsigned XPointFantome, const unsigned SizePac) 
{
    if ((XCenterPac - SizePac) <= XPointFantome && (XCenterPac + SizePac) >= XPointFantome)
        return true;
    else
        return false;
}

bool yFInsideHitBoxPacY (const unsigned & YCenterPac, const unsigned YPointFantome, const unsigned SizePac,const unsigned & XCenterPac, const unsigned XPointFantome) 
{
    if ((YCenterPac - SizePac) <= YPointFantome && (YCenterPac + SizePac) >= YPointFantome){ // Cette condition empeche que y sortent de la HitBox
        unsigned valAbsDiffXPacFantome;
        if (XCenterPac < XPointFantome)
            valAbsDiffXPacFantome = XPointFantome - XCenterPac;
        else
            valAbsDiffXPacFantome = XCenterPac - XPointFantome
        
        if ((YCenterPac - SizePac/2) - (SizePac - valAbsDiffXPacFantome) <= YPointFantome && (YCenterPac + SizePac/2) + (SizePac - valAbsDiffXPacFantome) >= YPointFantome)
            return true;
        else
            return false;
    }
}

bool RealHitGhost (const PacMan & Pac, const unsigned & xGFirstContact, const unsigned & yGFirstContact, const GhostSprite & Ghost);
{
    if (xFInsideHitBoxPacX(Pac.CenterPos.getX(), xGFirstContact + (Ghost.Size /2), Pac.Size) == true || xFInsideHitBoxPacX(Pac.CenterPos.getX(), xGFirstContact + (Ghost.Size /2), Pac.Size) == true)
        return true;
    else if (yFInsideHitBoxPacY(Pac.CenterPos.getY(), yGFirstContact, Pac.Size, Pac.CenterPos.getX(), xGFirstContact) == true)
        return true;
    else 
        return false;
}

bool CollisionPacGhost (const PacMan & Pac, const map <unsigned, GhostSprite> & MapGhost)
{
    /* Si un Ghost n'as pas de collision avec PacMan, la fonction ne renvoie pas false immédiatement : cette valeur n'est envoyée seulement si AUCUN n'a de collision d'où le renvoie false APRES la boucle for*/
    for (pair <unsigned, GhostSprite> & Fantome : MapGhost){
        
        // Avec xMax 
        unsigned xMaxGhost = Fantome.second.CenterPos.getX() + Fantome.second.Size;
        if (xFInsideHitBoxPacX(Pac.CenterPos.getX(), xMaxGhost, Pac.Size) == true)
        {
            // yMax
            unsigned yMaxGhost = Fantome.second.CenterPos.second + Fantome.second.Size;
            if (yFInsideHitBoxPacY(Pac.CenterPos.getY(), yMaxGhost, Pac.Size, Pac.CenterPos.getX(), xMaxGhost) == true) 
                return true;
            // yMin
            else{
                unsigned yMinGhost = Fantome.second.CenterPos.second - Fantome.second.Size;
                if (yFInsideHitBoxPacY(Pac.CenterPos.getY(), yMinGhost, Pac.Size, Pac.CenterPos.getX(), xMaxGhost) == true && RealHitGhost(Pac, xMaxGhost, yMinGhost, Fantome.second.Size))
                    return true;
                else 
                    continue;
            }
        }

        // Avec xMin
        else 
        {
            unsigned xMinGhost = Fantome.second.CenterPos.first - Fantome.second.Size;
            if (xFInsideHitBoxPacX(Pac.CenterPos.getX(), xMinGhost, Pac.Size) == true)
                {
                unsigned yMaxGhost = Fantome.second.CenterPos.second + Fantome.second.Size;
                if (yFInsideHitBoxPacY(Pac.CenterPos.getY(), yMaxGhost, Pac.Size, Pac.CenterPos.getX(), xMinGhost) == true) 
                    return true;
                else{
                    unsigned yMinGhost = Fantome.second.CenterPos.second - Fantome.second.Size;
                    if (yFInsideHitBoxPacY(Pac.CenterPos.getY(), yMinGhost, Pac.Size, Pac.CenterPos.getX(), xMinGhost) == true && RealHitGhost(Pac, xMinGhost, yMinGhost, Fantome.second.Size))
                        return true;
                    else
                        continue;
                }
            }
            else 
                continue;
        }
    }
    return false;
}


/* ************************  PacMan / Boule-Point (BP)  ************************** */

void CollisionBPPossible (const PacMan & Pac, const map<nsGraphics::Vec2D, bool> & MapBP, const CMyParam & Parameters, map<nsGraphics::Vec2D, bool> & MapBPPossible)
{
    if (Pac.DirectionPrev != Pac.DirectionActuelle){ // Evite d'avoir à tout reconstruire à chaque appel de la procedure
        MapBPPossible.erase(MapBPPossible.begin(), MapBPPossible.end());
        taillePac = Pac.Size;
        // Trajectoire Verticale
        if (Pac.DirectionActuelle == MapParamStrPac.find("TurnUp")->second){
            for (pair <nsGraphics::Vec2D, bool> & BP : MapBP ){
                if (BP.first.getY() <= Pac.CenterPos.getY()){
                    if (Pac.CenterPos.getX() - taillePac <= BP.first.getX() && BP.first.getX() <= Pac.CenterPos.getX() + taillePac)
                        MapBPPossible[BP.first] = BP.second;
                }
            }
        }
        else if (Pac.DirectionActuelle == MapParamStrPac.find("TurnDown")->second){
            for (pair <nsGraphics::Vec2D, bool> & BP : MapBP ){
                if (BP.first.getY() >= Pac.CenterPos.getY()){
                    if (Pac.CenterPos.getX() - taillePac <= BP.first.getX() && BP.first.getX() <= Pac.CenterPos.getX() + taillePac)
                        MapBPPossible[BP.first] = BP.second;
                }
            }
        }
        // Ligne alignée avec le pacman
        else if (Pac.DirectionActuelle == MapParamStrPac.find("TurnLeft")->second){
            for (pair <nsGraphics::Vec2D, bool> & BP : MapBP ){
                if (BP.first.getX() <= Pac.CenterPos.getX()){
                    if (Pac.CenterPos.getY() - taillePac <= BP.first.getY() && BP.first.getY() <= Pac.CenterPos.getY() + taillePac)
                        MapBPPossible[BP.first] = BP.second;
                }
            }
        }
        else if (Pac.DirectionActuelle == MapParamStrPac.find("TurnRight")->second){
            for (pair <nsGraphics::Vec2D, bool> & BP : MapBP ){
                if (BP.first.getX() >= Pac.CenterPos.getX()){
                    if (Pac.CenterPos.getY() - taillePac <= BP.first.getY() && BP.first.getY() <= Pac.CenterPos.getY() + taillePac)
                        MapBPPossible[BP.first] = BP.second;
                }
            }
        }
    }
}

pair <bool, nsGraphics::Vec2D> CollisionPacBP (const PacMan & Pac, const CMyParam & Parameters, const map <nsGraphics::Vec2D, bool> & MapBPPossible)
{
    tailleBP = Parameters.MapParamUnsigned.find("BPSize")->second;
    for (auto & BPPossible : MapBPPossible){
        if (BPPossible == true){
            if (Pac.CenterPos.isColliding(nsGraphics::Vec2D((BPPossible.first.getX() - tailleBP), (BPPossible.first.getY() - tailleBP)), nsGraphics::Vec2D((BPPossible.first.getX() + tailleBP), (BPPossible.first.getY() + tailleBP))) == true)
                return {true, BPPossible.first};
        }
    }
}
