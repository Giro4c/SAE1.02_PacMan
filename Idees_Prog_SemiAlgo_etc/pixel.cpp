"G" + string(Ghost.ID) + 

unsigned CoNextMur (const GhostSprite & Ghost, const unsigned & CaseSize, const std::vector<nsGraphics::Vec2D> & VecteurMurs, const CMyParam & Parameters)
{
    // Si direction vers le haut
    if (Ghost.DirectionActuelle == MapParamChar.find("KeyUp")->second){
        unsigned ValCoNextMurY (0);
        for (nsGraphics::Vec2D & Mur : VecteurMurs){

            if (Mur.getY() + CaseSize <= Ghost.CenterPos.getY() - Ghost.Size){ // Traduction sur la fenetre : point au dessus de Ghostman
                if (Ghost.CenterPos.getX() - Ghost.size <= Mur.getX() && Mur.getX() <= Ghost.CenterPos.getX() + Ghost.size){
                    ValCoNextMurY = max(ValCoNextMurY, Mur.getY() + CaseSize);
                }
                else if (Ghost.CenterPos.getX() - Ghost.size <= Mur.getX() + CaseSize && Mur.getX() + CaseSize <= Ghost.CenterPos.getX() + Ghost.size){
                    ValCoNextMurY = max(ValCoNextMurY, Mur.getY() + CaseSize);
                }
            }
            // Else if car (y + CaseSize) est forcément plus grand que (y) sachant que CaseSize >= 0
            else if (Mur.getY() <= Ghost.CenterPos.getY() - Ghost.Size){ // Traduction sur la fenetre : point au dessus de Ghostman
                if (Ghost.CenterPos.getX() - Ghost.size <= Mur.getX() && Mur.getX() <= Ghost.CenterPos.getX() + Ghost.size){
                    ValCoNextMurY = max(ValCoNextMurY, Mur.getY());
                }
                else if (Ghost.CenterPos.getX() - Ghost.size <= Mur.getX() + CaseSize && Mur.getX() + CaseSize <= Ghost.CenterPos.getX() + Ghost.size){
                    ValCoNextMurY = max(ValCoNextMurY, Mur.getY());
                }
            }

        }
        return ValCoNextMurY;
    }
    // Si direction vers le bas
    else if (Ghost.DirectionActuelle == MapParamChar.find("KeyDown")->second){
        unsigned ValCoNextMurY (Parameters.MapParamSize.find("WindowHeight")->second);
        for (nsGraphics::Vec2D & Mur : VecteurMurs){

            if (Mur.getY() >= Ghost.CenterPos.getY() + Ghost.Size){ // Traduction sur la fenetre : point au dessus de Ghostman
                if (Ghost.CenterPos.getX() - Ghost.size <= Mur.getX() && Mur.getX() <= Ghost.CenterPos.getX() + Ghost.size){
                    ValCoNextMurY = min(ValCoNextMurY, Mur.getY());
                }
                else if (Ghost.CenterPos.getX() - Ghost.size <= Mur.getX() + CaseSize && Mur.getX() + CaseSize <= Ghost.CenterPos.getX() + Ghost.size){
                    ValCoNextMurY = min(ValCoNextMurY, Mur.getY());
                }
            }
            // Else if car (y) est forcément plus petit que (y + CaseSize) sachant que CaseSize >= 0            
            else if (Mur.getY() + CaseSize >= Ghost.CenterPos.getY() + Ghost.Size){ // Traduction sur la fenetre : point au dessus de Ghostman
                if (Ghost.CenterPos.getX() - Ghost.size <= Mur.getX() && Mur.getX() <= Ghost.CenterPos.getX() + Ghost.size){
                    ValCoNextMurY = min(ValCoNextMurY, Mur.getY() + CaseSize);
                }
                else if (Ghost.CenterPos.getX() - Ghost.size <= Mur.getX() + CaseSize && Mur.getX() + CaseSize <= Ghost.CenterPos.getX() + Ghost.size){
                    ValCoNextMurY = min(ValCoNextMurY, Mur.getY() + CaseSize);
                }
            }

        }
        return ValCoNextMurY;
    }
    // Si direction à gauche
    else if (Ghost.DirectionActuelle == MapParamChar.find("KeyLeft")->second){
        unsigned ValCoNextMurX (0);
        for (nsGraphics::Vec2D & Mur : VecteurMurs){

            if (Mur.getX() + CaseSize <= Ghost.CenterPos.getX() - Ghost.Size){ // Traduction sur la fenetre : point à gauche de Ghostman
                if (Ghost.CenterPos.getY() - Ghost.size <= Mur.getY() && Mur.getY() <= Ghost.CenterPos.getY() + Ghost.size){
                    ValCoNextMurX = max(ValCoNextMurX, Mur.getX() + CaseSize);
                }
                if (Ghost.CenterPos.getY() - Ghost.size <= Mur.getY() + CaseSize && Mur.getY() + CaseSize <= Ghost.CenterPos.getY() + Ghost.size){
                    ValCoNextMurX = max(ValCoNextMurX, Mur.getX() + CaseSize);
                }
            }
            // Else if car (x + CaseSize) est forcément plus grand que (x) sachant que CaseSize >= 0
            if (Mur.getX() <= Ghost.CenterPos.getX() - Ghost.Size){ // Traduction sur la fenetre : point à gauche de Ghostman
                if (Ghost.CenterPos.getY() - Ghost.size <= Mur.getY() && Mur.getY() <= Ghost.CenterPos.getY() + Ghost.size){
                    ValCoNextMurX = max(ValCoNextMurX, Mur.getX());
                }
                if (Ghost.CenterPos.getY() - Ghost.size <= Mur.getY() + CaseSize && Mur.getY() + CaseSize <= Ghost.CenterPos.getY() + Ghost.size){
                    ValCoNextMurX = max(ValCoNextMurX, Mur.getX());
                }
            }

        }
        return ValCoNextMurX;
    }
    // Si direction à droite
    else if (Ghost.DirectionActuelle == Parameters.MapParamChar.find("KeyRight")->second){
        unsigned ValCoNextMurX (Parameters.MapParamSize.find("WindowWidth")->second);
        for (nsGraphics::Vec2D & Mur : VecteurMurs){

            if (Mur.getX() <= Ghost.CenterPos.getX() + Ghost.Size){ // Traduction sur la fenetre : point à gauche de Ghostman
                if (Ghost.CenterPos.getY() - Ghost.size <= Mur.getY() && Mur.getY() <= Ghost.CenterPos.getY() + Ghost.size){
                    ValCoNextMurX = min(ValCoNextMurX, Mur.getX());
                }
                if (Ghost.CenterPos.getY() - Ghost.size <= Mur.getY() + CaseSize && Mur.getY() + CaseSize <= Ghost.CenterPos.getY() + Ghost.size){
                    ValCoNextMurX = min(ValCoNextMurX, Mur.getX());
                }
            }
            // Else if car (x) est forcément plus petit que (x + CaseSize) sachant que CaseSize >= 0            
            else if (Mur.getX() + CaseSize <= Ghost.CenterPos.getX() + Ghost.Size){ // Traduction sur la fenetre : point à gauche de Ghostman
                if (Ghost.CenterPos.getY() - Ghost.size <= Mur.getY() && Mur.getY() <= Ghost.CenterPos.getY() + Ghost.size){
                    ValCoNextMurX = min(ValCoNextMurX, Mur.getX() + CaseSize);
                }
                if (Ghost.CenterPos.getY() - Ghost.size <= Mur.getY() + CaseSize && Mur.getY() + CaseSize <= Ghost.CenterPos.getY() + Ghost.size){
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
    // Déclaration des coordonnées d'extrémités dépendantes de la direction actuelle du Ghost
    unsigned xVerif; // Coordonnées x max du point potentiel de contact
    unsigned yVerif; // Coordonnées y max du point potentiel de contact

    // Vérification en fonction de la direction actuelle du GhostMan
    // Haut
    if (Ghost.DirectionActuelle == MapParamChar.find("KeyUp")->second){
        yVerif = Ghost.CenterPos.getY() - Ghost.Size - Vitesse;
        if (ValCoNextMur >= yVerif)
            return {true, Vitesse - (ValCoNextMur - yVerif) - 1};
        else 
            return {false, 0}; // Puisque pas de collision
    }
    // Bas
    else if (Ghost.Direction == MapParamChar.find("KeyDown")->second){
        yVerif = Ghost.CenterPos.getY() + Ghost.Size + Vitesse;
        if (ValCoNextMur <= yVerif)
            return {true, Vitesse - (yVerif - ValCoNextMur) - 1};
        else
            return {false, 0}; // Puisque pas de collision
    }
    // Gauche
    else if (Ghost.Direction == MapParamChar.find("KeyLeft")->second){
        xVerif = Ghost.CenterPos.getX() - Ghost.Size - Vitesse;
        if (ValCoNextMur >= xVerif)
            return {true, Vitesse - (ValCoNextMur - xVerif) - 1};
        else
            return {false, 0}; // Puisque pas de collision
    }
    // Droite
    else if (Ghost.Direction == MapParamChar.find("KeyRight")->second){
        xVerif = Ghost.CenterPos.getX() + Ghost.Size + Vitesse;
        if (ValCoNextMur <= xVerif)
            return {true, Vitesse - (xVerif - ValCoNextMur) - 1};
        else
            return {false, 0}; // Puisque pas de collision
    }
    else 
        return {false, 0}; // Puisque pas de collision car mauvaise direction en entrée
}
