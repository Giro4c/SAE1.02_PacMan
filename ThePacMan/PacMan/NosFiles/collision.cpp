#include "collision.h"

using namespace std;

/* ************************  PacMan / Mur  ************************** */

unsigned CoNextMur (const PacMan & Pac, const unsigned & CaseSize, vector<nsGraphics::Vec2D> & VecteurMurs, const CMyParam & Parameters)
{
    // Si direction vers le haut
    if (Pac.DirectionActuelle == Parameters.MapParamChar.find("PacKeyUp")->second){
        unsigned ValCoNextMurY (0);
        for (nsGraphics::Vec2D & Mur : VecteurMurs){

            if (Mur.getY() + CaseSize <= Pac.CenterPos.getY() - Pac.Size){ // Traduction sur la fenetre : point au dessus de pacman
                if (Pac.CenterPos.getX() - Pac.Size <= Mur.getX() && Mur.getX() <= Pac.CenterPos.getX() + Pac.Size){
                    ValCoNextMurY = max(ValCoNextMurY, Mur.getY() + CaseSize);
                }
                else if (Pac.CenterPos.getX() - Pac.Size <= Mur.getX() + CaseSize && Mur.getX() + CaseSize <= Pac.CenterPos.getX() + Pac.Size){
                    ValCoNextMurY = max(ValCoNextMurY, Mur.getY() + CaseSize);
                }
            }
            // Else if car (y + CaseSize) est forcément plus grand que (y) sachant que CaseSize >= 0
            else if (Mur.getY() <= Pac.CenterPos.getY() - Pac.Size){ // Traduction sur la fenetre : point au dessus de pacman
                if (Pac.CenterPos.getX() - Pac.Size <= Mur.getX() && Mur.getX() <= Pac.CenterPos.getX() + Pac.Size){
                    ValCoNextMurY = max(ValCoNextMurY, unsigned( Mur.getY()));
                }
                else if (Pac.CenterPos.getX() - Pac.Size <= Mur.getX() + CaseSize && Mur.getX() + CaseSize <= Pac.CenterPos.getX() + Pac.Size){
                    ValCoNextMurY = max(ValCoNextMurY, unsigned( Mur.getY() ) );
                }
            }

        }
        return ValCoNextMurY;
    }
    // Si direction vers le bas
    else if (Pac.DirectionActuelle == Parameters.MapParamChar.find("PacKeyDown")->second){
        unsigned ValCoNextMurY (Parameters.MapParamSize.find("WindowHeight")->second);
        for (nsGraphics::Vec2D & Mur : VecteurMurs){

            if (Mur.getY() >= Pac.CenterPos.getY() + Pac.Size){ // Traduction sur la fenetre : point au dessus de pacman
                if (Pac.CenterPos.getX() - Pac.Size <= Mur.getX() && Mur.getX() <= Pac.CenterPos.getX() + Pac.Size){
                    ValCoNextMurY = min(ValCoNextMurY, unsigned( Mur.getY() ) );
                }
                else if (Pac.CenterPos.getX() - Pac.Size <= Mur.getX() + CaseSize && Mur.getX() + CaseSize <= Pac.CenterPos.getX() + Pac.Size){
                    ValCoNextMurY = min(ValCoNextMurY, unsigned( Mur.getY() ) );
                }
            }
            // Else if car (y) est forcément plus petit que (y + CaseSize) sachant que CaseSize >= 0
            else if (Mur.getY() + CaseSize >= Pac.CenterPos.getY() + Pac.Size){ // Traduction sur la fenetre : point au dessus de pacman
                if (Pac.CenterPos.getX() - Pac.Size <= Mur.getX() && Mur.getX() <= Pac.CenterPos.getX() + Pac.Size){
                    ValCoNextMurY = min(ValCoNextMurY, Mur.getY() + CaseSize);
                }
                else if (Pac.CenterPos.getX() - Pac.Size <= Mur.getX() + CaseSize && Mur.getX() + CaseSize <= Pac.CenterPos.getX() + Pac.Size){
                    ValCoNextMurY = min(ValCoNextMurY, Mur.getY() + CaseSize);
                }
            }

        }
        return ValCoNextMurY;
    }
    // Si direction à gauche
    else if (Pac.DirectionActuelle == Parameters.MapParamChar.find("PacKeyLeft")->second){
        unsigned ValCoNextMurX (0);
        for (nsGraphics::Vec2D & Mur : VecteurMurs){

            if (Mur.getX() + CaseSize <= Pac.CenterPos.getX() - Pac.Size){ // Traduction sur la fenetre : point à gauche de pacman
                if (Pac.CenterPos.getY() - Pac.Size <= Mur.getY() && Mur.getY() <= Pac.CenterPos.getY() + Pac.Size){
                    ValCoNextMurX = max(ValCoNextMurX, Mur.getX() + CaseSize);
                }
                if (Pac.CenterPos.getY() - Pac.Size <= Mur.getY() + CaseSize && Mur.getY() + CaseSize <= Pac.CenterPos.getY() + Pac.Size){
                    ValCoNextMurX = max(ValCoNextMurX, Mur.getX() + CaseSize);
                }
            }
            // Else if car (x + CaseSize) est forcément plus grand que (x) sachant que CaseSize >= 0
            if (Mur.getX() <= Pac.CenterPos.getX() - Pac.Size){ // Traduction sur la fenetre : point à gauche de pacman
                if (Pac.CenterPos.getY() - Pac.Size <= Mur.getY() && Mur.getY() <= Pac.CenterPos.getY() + Pac.Size){
                    ValCoNextMurX = max(ValCoNextMurX, unsigned( Mur.getX()));
                }
                if (Pac.CenterPos.getY() - Pac.Size <= Mur.getY() + CaseSize && Mur.getY() + CaseSize <= Pac.CenterPos.getY() + Pac.Size){
                    ValCoNextMurX = max(ValCoNextMurX, unsigned( Mur.getX()));
                }
            }

        }
        return ValCoNextMurX;
    }
    // Si direction à droite
    else if (Pac.DirectionActuelle == Parameters.MapParamChar.find("PacKeyRight")->second){
        unsigned ValCoNextMurX (Parameters.MapParamSize.find("WindowWidth")->second);
        for (nsGraphics::Vec2D & Mur : VecteurMurs){

            if (Mur.getX() <= Pac.CenterPos.getX() + Pac.Size){ // Traduction sur la fenetre : point à gauche de pacman
                if (Pac.CenterPos.getY() - Pac.Size <= Mur.getY() && Mur.getY() <= Pac.CenterPos.getY() + Pac.Size){
                    ValCoNextMurX = min(ValCoNextMurX, unsigned( Mur.getX()));
                }
                if (Pac.CenterPos.getY() - Pac.Size <= Mur.getY() + CaseSize && Mur.getY() + CaseSize <= Pac.CenterPos.getY() + Pac.Size){
                    ValCoNextMurX = min(ValCoNextMurX, unsigned( Mur.getX()));
                }
            }
            // Else if car (x) est forcément plus petit que (x + CaseSize) sachant que CaseSize >= 0
            else if (Mur.getX() + CaseSize <= Pac.CenterPos.getX() + Pac.Size){ // Traduction sur la fenetre : point à gauche de pacman
                if (Pac.CenterPos.getY() - Pac.Size <= Mur.getY() && Mur.getY() <= Pac.CenterPos.getY() + Pac.Size){
                    ValCoNextMurX = min(ValCoNextMurX, Mur.getX() + CaseSize);
                }
                if (Pac.CenterPos.getY() - Pac.Size <= Mur.getY() + CaseSize && Mur.getY() + CaseSize <= Pac.CenterPos.getY() + Pac.Size){
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
    if (Pac.DirectionActuelle == Parameters.MapParamChar.find("PacKeyUp")->second){
        yVerif = Pac.CenterPos.getY() - Pac.Size - Vitesse;
        if (ValCoNextMur >= yVerif)
            return {true, Vitesse - (ValCoNextMur - yVerif) - 1};
        else 
            return {false, 0}; // Puisque pas de collision
    }
    // Bas
    else if (Pac.DirectionActuelle == Parameters.MapParamChar.find("PacKeyDown")->second){
        yVerif = Pac.CenterPos.getY() + Pac.Size + Vitesse;
        if (ValCoNextMur <= yVerif)
            return {true, Vitesse - (yVerif - ValCoNextMur) - 1};
        else
            return {false, 0}; // Puisque pas de collision
    }
    // Gauche
    else if (Pac.DirectionActuelle == Parameters.MapParamChar.find("PacKeyLeft")->second){
        xVerif = Pac.CenterPos.getX() - Pac.Size - Vitesse;
        if (ValCoNextMur >= xVerif)
            return {true, Vitesse - (ValCoNextMur - xVerif) - 1};
        else
            return {false, 0}; // Puisque pas de collision
    }
    // Droite
    else if (Pac.DirectionActuelle == Parameters.MapParamChar.find("PacKeyRight")->second){
        xVerif = Pac.CenterPos.getX() + Pac.Size + Vitesse;
        if (ValCoNextMur <= xVerif)
            return {true, Vitesse - (xVerif - ValCoNextMur) - 1};
        else
            return {false, 0}; // Puisque pas de collision
    }
    else 
        return {false, 0}; // Puisque pas de collision car mauvaise direction en entrée
}


/* ************************  Fantome / Mur  ************************** */




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
            valAbsDiffXPacFantome = XCenterPac - XPointFantome;
        
        if ((YCenterPac - SizePac/2) - (SizePac - valAbsDiffXPacFantome) <= YPointFantome && (YCenterPac + SizePac/2) + (SizePac - valAbsDiffXPacFantome) >= YPointFantome)
            return true;
        else
            return false;
    }
    return false;
}


bool RealHitGhost (const PacMan & Pac, const unsigned & xGFirstContact, const unsigned & yGFirstContact, const unsigned & SizeGhost)
{
    if (xFInsideHitBoxPacX(Pac.CenterPos.getX(), xGFirstContact + (SizeGhost/2), Pac.Size) == true || xFInsideHitBoxPacX(Pac.CenterPos.getX(), xGFirstContact + (SizeGhost /2), Pac.Size) == true)
        return true;
    else if (yFInsideHitBoxPacY(Pac.CenterPos.getY(), yGFirstContact, Pac.Size, Pac.CenterPos.getX(), xGFirstContact) == true)
        return true;
    else 
        return false;
}

bool CollisionPacGhost (const PacMan & Pac, vector<GhostSprite> & VecteurGhost)
{
    /* Si un Ghost n'as pas de collision avec PacMan, la fonction ne renvoie pas false immédiatement : cette valeur n'est envoyée seulement si AUCUN n'a de collision d'où le renvoie false APRES la boucle for*/
    for (GhostSprite & Fantome : VecteurGhost)
    {   
        // Avec xMax 
        unsigned xMaxGhost = Fantome.CenterPos.getX() + Fantome.Size;
        if (xFInsideHitBoxPacX(Pac.CenterPos.getX(), xMaxGhost, Pac.Size) == true)
        {
            // yMax
            unsigned yMaxGhost = Fantome.CenterPos.getY() + Fantome.Size;
            if (yFInsideHitBoxPacY(Pac.CenterPos.getY(), yMaxGhost, Pac.Size, Pac.CenterPos.getX(), xMaxGhost) == true) 
                return true;
            // yMin
            else{
                unsigned yMinGhost = Fantome.CenterPos.getY() - Fantome.Size;
                if (yFInsideHitBoxPacY(Pac.CenterPos.getY(), yMinGhost, Pac.Size, Pac.CenterPos.getX(), xMaxGhost) == true && RealHitGhost(Pac, xMaxGhost, yMinGhost, Fantome.Size))
                    return true;
                else 
                    continue;
            }
        }

        // Avec xMin
        else 
        {
            unsigned xMinGhost = Fantome.CenterPos.getX() - Fantome.Size;
            if (xFInsideHitBoxPacX(Pac.CenterPos.getX(), xMinGhost, Pac.Size) == true)
                {
                unsigned yMaxGhost = Fantome.CenterPos.getY() + Fantome.Size;
                if (yFInsideHitBoxPacY(Pac.CenterPos.getY(), yMaxGhost, Pac.Size, Pac.CenterPos.getX(), xMinGhost) == true) 
                    return true;
                else{
                    unsigned yMinGhost = Fantome.CenterPos.getY() - Fantome.Size;
                    if (yFInsideHitBoxPacY(Pac.CenterPos.getY(), yMinGhost, Pac.Size, Pac.CenterPos.getX(), xMinGhost) == true && RealHitGhost(Pac, xMinGhost, yMinGhost, Fantome.Size))
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

void CollisionBPPossible (const PacMan & Pac, map<nsGraphics::Vec2D, bool> & MapBP, const CMyParam & Parameters, map<nsGraphics::Vec2D, bool> & MapBPPossible)
{
    if (Pac.DirectionPred != Pac.DirectionActuelle){ // Evite d'avoir à tout reconstruire à chaque appel de la procedure
        MapBPPossible.erase(MapBPPossible.begin(), MapBPPossible.end());
        unsigned taillePac = Pac.Size;
        // Trajectoire Verticale
        if (Pac.DirectionActuelle == Parameters.MapParamChar.find("PacKeyUp")->second){
            for (auto & BP : MapBP){
                if (BP.first.getY() <= Pac.CenterPos.getY()){
                    if (Pac.CenterPos.getX() - taillePac <= BP.first.getX() && BP.first.getX() <= Pac.CenterPos.getX() + taillePac)
                        MapBPPossible[BP.first] = BP.second;
                }
            }
        }
        else if (Pac.DirectionActuelle == Parameters.MapParamChar.find("PacKeyDown")->second){
            for (auto & BP : MapBP){
                if (BP.first.getY() >= Pac.CenterPos.getY()){
                    if (Pac.CenterPos.getX() - taillePac <= BP.first.getX() && BP.first.getX() <= Pac.CenterPos.getX() + taillePac)
                        MapBPPossible[BP.first] = BP.second;
                }
            }
        }
        // Ligne alignée avec le pacman
        else if (Pac.DirectionActuelle == Parameters.MapParamChar.find("PacKeyLeft")->second){
            for (auto & BP : MapBP){
                if (BP.first.getX() <= Pac.CenterPos.getX()){
                    if (Pac.CenterPos.getY() - taillePac <= BP.first.getY() && BP.first.getY() <= Pac.CenterPos.getY() + taillePac)
                        MapBPPossible[BP.first] = BP.second;
                }
            }
        }
        else if (Pac.DirectionActuelle == Parameters.MapParamChar.find("PacKeyRight")->second){
            for (auto & BP : MapBP){
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
    unsigned tailleBP = Parameters.MapParamSize.find("BPSize")->second;
    for (auto & BPPossible : MapBPPossible){
        if (BPPossible.second == true){
            if (Pac.CenterPos.isColliding(nsGraphics::Vec2D((BPPossible.first.getX() - tailleBP), (BPPossible.first.getY() - tailleBP)), nsGraphics::Vec2D((BPPossible.first.getX() + tailleBP), (BPPossible.first.getY() + tailleBP))) == true)
                return {true, BPPossible.first};
        }
    }
    return {false, 0};
}
