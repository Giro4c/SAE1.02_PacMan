
unsigned CoNextMur (const GhostSprite & Ghost, const unsigned & CaseSize, vector<nsGraphics::Vec2D> & VecteurMurs, const CMyParam & Parameters)
{
    // Si direction vers le haut
    if (Ghost.DirectionActuelle == Parameters.MapParamChar.find("G" + string(Ghost.ID) + "KeyUp")->second){
        unsigned ValCoNextMurY (0);
        for (nsGraphics::Vec2D & Mur : VecteurMurs){

            if (Mur.getY() + CaseSize <= Ghost.CenterPos.getY() - Ghost.Size){ // Traduction sur la fenetre : point au dessus de Ghost
                if (Ghost.CenterPos.getX() - Ghost.Size <= Mur.getX() && Mur.getX() <= Ghost.CenterPos.getX() + Ghost.Size){
                    ValCoNextMurY = max(ValCoNextMurY, Mur.getY() + CaseSize);
                }
                else if (Ghost.CenterPos.getX() - Ghost.Size <= Mur.getX() + CaseSize && Mur.getX() + CaseSize <= Ghost.CenterPos.getX() + Ghost.Size){
                    ValCoNextMurY = max(ValCoNextMurY, Mur.getY() + CaseSize);
                }
            }
            // Else if car (y + CaseSize) est forcément plus grand que (y) sachant que CaseSize >= 0
            else if (Mur.getY() <= Ghost.CenterPos.getY() - Ghost.Size){ // Traduction sur la fenetre : point au dessus de Ghost
                if (Ghost.CenterPos.getX() - Ghost.Size <= Mur.getX() && Mur.getX() <= Ghost.CenterPos.getX() + Ghost.Size){
                    ValCoNextMurY = max(ValCoNextMurY, unsigned( Mur.getY()));
                }
                else if (Ghost.CenterPos.getX() - Ghost.Size <= Mur.getX() + CaseSize && Mur.getX() + CaseSize <= Ghost.CenterPos.getX() + Ghost.Size){
                    ValCoNextMurY = max(ValCoNextMurY, unsigned( Mur.getY() ));
                }
            }

        }
        return ValCoNextMurY;
    }
    // Si direction vers le bas
    else if (Ghost.DirectionActuelle == Parameters.MapParamChar.find("G" + string(Ghost.ID) + "KeyDown")->second){
        unsigned ValCoNextMurY (Parameters.MapParamSize.find("WindowHeight")->second);
        for (nsGraphics::Vec2D & Mur : VecteurMurs){

            if (Mur.getY() >= Ghost.CenterPos.getY() + Ghost.Size){ // Traduction sur la fenetre : point au dessus de Ghost
                if (Ghost.CenterPos.getX() - Ghost.Size <= Mur.getX() && Mur.getX() <= Ghost.CenterPos.getX() + Ghost.Size){
                    ValCoNextMurY = min(ValCoNextMurY, unsigned( Mur.getY() ) );
                }
                else if (Ghost.CenterPos.getX() - Ghost.Size <= Mur.getX() + CaseSize && Mur.getX() + CaseSize <= Ghost.CenterPos.getX() + Ghost.Size){
                    ValCoNextMurY = min(ValCoNextMurY, unsigned( Mur.getY() ) );
                }
            }
            // Else if car (y) est forcément plus petit que (y + CaseSize) sachant que CaseSize >= 0
            else if (Mur.getY() + CaseSize >= Ghost.CenterPos.getY() + Ghost.Size){ // Traduction sur la fenetre : point au dessus de Ghost
                if (Ghost.CenterPos.getX() - Ghost.Size <= Mur.getX() && Mur.getX() <= Ghost.CenterPos.getX() + Ghost.Size){
                    ValCoNextMurY = min(ValCoNextMurY, Mur.getY() + CaseSize);
                }
                else if (Ghost.CenterPos.getX() - Ghost.Size <= Mur.getX() + CaseSize && Mur.getX() + CaseSize <= Ghost.CenterPos.getX() + Ghost.Size){
                    ValCoNextMurY = min(ValCoNextMurY, Mur.getY() + CaseSize);
                }
            }

        }
        return ValCoNextMurY;
    }
    // Si direction à gauche
    else if (Ghost.DirectionActuelle == Parameters.MapParamChar.find("G" + string(Ghost.ID) + "KeyLeft")->second){
        unsigned ValCoNextMurX (0);
        for (nsGraphics::Vec2D & Mur : VecteurMurs){

            if (Mur.getX() + CaseSize <= Ghost.CenterPos.getX() - Ghost.Size){ // Traduction sur la fenetre : point à gauche de Ghost
                if (Ghost.CenterPos.getY() - Ghost.Size <= Mur.getY() && Mur.getY() <= Ghost.CenterPos.getY() + Ghost.Size){
                    ValCoNextMurX = max(ValCoNextMurX, Mur.getX() + CaseSize);
                }
                if (Ghost.CenterPos.getY() - Ghost.Size <= Mur.getY() + CaseSize && Mur.getY() + CaseSize <= Ghost.CenterPos.getY() + Ghost.Size){
                    ValCoNextMurX = max(ValCoNextMurX, Mur.getX() + CaseSize);
                }
            }
            // Else if car (x + CaseSize) est forcément plus grand que (x) sachant que CaseSize >= 0
            if (Mur.getX() <= Ghost.CenterPos.getX() - Ghost.Size){ // Traduction sur la fenetre : point à gauche de Ghost
                if (Ghost.CenterPos.getY() - Ghost.Size <= Mur.getY() && Mur.getY() <= Ghost.CenterPos.getY() + Ghost.Size){
                    ValCoNextMurX = max(ValCoNextMurX, unsigned( Mur.getX()));
                }
                if (Ghost.CenterPos.getY() - Ghost.Size <= Mur.getY() + CaseSize && Mur.getY() + CaseSize <= Ghost.CenterPos.getY() + Ghost.Size){
                    ValCoNextMurX = max(ValCoNextMurX, unsigned( Mur.getX()));
                }
            }

        }
        return ValCoNextMurX;
    }
    // Si direction à droite
    else if (Ghost.DirectionActuelle == Parameters.MapParamChar.find("G" + string(Ghost.ID) + "KeyRight")->second){
        unsigned ValCoNextMurX (Parameters.MapParamSize.find("WindowWidth")->second);
        for (nsGraphics::Vec2D & Mur : VecteurMurs){

            if (Mur.getX() <= Ghost.CenterPos.getX() + Ghost.Size){ // Traduction sur la fenetre : point à gauche de Ghost
                if (Ghost.CenterPos.getY() - Ghost.Size <= Mur.getY() && Mur.getY() <= Ghost.CenterPos.getY() + Ghost.Size){
                    ValCoNextMurX = min(ValCoNextMurX, unsigned( Mur.getX()));
                }
                if (Ghost.CenterPos.getY() - Ghost.Size <= Mur.getY() + CaseSize && Mur.getY() + CaseSize <= Ghost.CenterPos.getY() + Ghost.Size){
                    ValCoNextMurX = min(ValCoNextMurX, unsigned( Mur.getX()));
                }
            }
            // Else if car (x) est forcément plus petit que (x + CaseSize) sachant que CaseSize >= 0
            else if (Mur.getX() + CaseSize <= Ghost.CenterPos.getX() + Ghost.Size){ // Traduction sur la fenetre : point à gauche de Ghost
                if (Ghost.CenterPos.getY() - Ghost.Size <= Mur.getY() && Mur.getY() <= Ghost.CenterPos.getY() + Ghost.Size){
                    ValCoNextMurX = min(ValCoNextMurX, Mur.getX() + CaseSize);
                }
                if (Ghost.CenterPos.getY() - Ghost.Size <= Mur.getY() + CaseSize && Mur.getY() + CaseSize <= Ghost.CenterPos.getY() + Ghost.Size){
                    ValCoNextMurX = min(ValCoNextMurX, Mur.getX() + CaseSize);
                }
            }

        }
        return ValCoNextMurX;
    }
    else
        return 0;
}

pair <bool, unsigned> CollisionGhostMur (const GhostSprite & Ghost, const unsigned & Vitesse, const CMyParam & Parameters, const unsigned & ValCoNextMur)
{    
    // Déclaration des coordonnées d'extrémités dépendantes de la direction actuelle du fantome
    unsigned xVerif; // Coordonnées x max du point potentiel de contact
    unsigned yVerif; // Coordonnées y max du point potentiel de contact

    // Vérification en fonction de la direction actuelle du Ghost
    // Haut
    if (Ghost.DirectionActuelle == Parameters.MapParamChar.find("G" + string(Ghost.ID) + "KeyUp")->second){
        yVerif = Ghost.CenterPos.getY() - Ghost.Size - Vitesse;
        if (ValCoNextMur >= yVerif)
            return {true, Vitesse - (ValCoNextMur - yVerif) - 1};
        else 
            return {false, 0}; // Puisque pas de collision
    }
    // Bas
    else if (Ghost.DirectionActuelle == Parameters.MapParamChar.find("G" + string(Ghost.ID) + "KeyDown")->second){
        yVerif = Ghost.CenterPos.getY() + Ghost.Size + Vitesse;
        if (ValCoNextMur <= yVerif)
            return {true, Vitesse - (yVerif - ValCoNextMur) - 1};
        else
            return {false, 0}; // Puisque pas de collision
    }
    // Gauche
    else if (Ghost.DirectionActuelle == Parameters.MapParamChar.find("G" + string(Ghost.ID) + "KeyLeft")->second){
        xVerif = Ghost.CenterPos.getX() - Ghost.Size - Vitesse;
        if (ValCoNextMur >= xVerif)
            return {true, Vitesse - (ValCoNextMur - xVerif) - 1};
        else
            return {false, 0}; // Puisque pas de collision
    }
    // Droite
    else if (Ghost.DirectionActuelle == Parameters.MapParamChar.find("G" + string(Ghost.ID) + "KeyRight")->second){
        xVerif = Ghost.CenterPos.getX() + Ghost.Size + Vitesse;
        if (ValCoNextMur <= xVerif)
            return {true, Vitesse - (xVerif - ValCoNextMur) - 1};
        else
            return {false, 0}; // Puisque pas de collision
    }
    else 
        return {false, 0}; // Puisque pas de collision car mauvaise direction en entrée
}
