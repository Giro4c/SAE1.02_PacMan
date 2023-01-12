/**
 * @brief Initialise les paramètres des Fantomes
 * @param[in] Parameters : 
 * @param[out] VecteurGhost :
 * @fn void InitGhost(const CMyParam & Parameters, vector<GhostSprite> & VecteurGhost);
*/
void InitGhost(const CMyParam & Parameters, vector<GhostSprite> & VecteurGhost);

void InitGhost(const CMyParam & Parameters, vector<GhostSprite> & VecteurGhost)
{
    for (GhostSprite & Ghost : VecteurGhost){
        Ghost.Vitesse = Parameters.MapParamSpeed.find("GhostSpeed")->second;
        Ghost.Size = Parameters.MapParamSize.find("GhostSize")->second;
    }
    VecteurGhost[0].Color = KColor.find("KRed")->second;
    VecteurGhost[0].ID = 1;
    VecteurGhost[1].Color = KColor.find("KGreen")->second;
    VecteurGhost[1].ID = 2;
}

/**
 * @brief Procédure de dessin des murs du plateau
 * @param[out] Window : La fenêtre sur laquelle s'afficherons les formes
 * @param[in] Parameters : 
 * @param[in] VecteurMurs : 
 * @fn void DrawMurs(MinGL & Window, const CMyParam & Parameters, const vector<nsGraphics::Vec2D> & VecteurMurs); 
*/
void DrawMurs(MinGL & Window, const CMyParam & Parameters, const vector<nsGraphics::Vec2D> & VecteurMurs); 

void DrawMurs(MinGL & Window, const CMyParam & Parameters, const vector<nsGraphics::Vec2D> & VecteurMurs)
{ 
    unsigned sizeMur = Parameters.MapParamSize.find("CaseSize")->second;
    for (size_t i (0); i < VecteurMurs.size(); ++i){
        Window << nsShape::Rectangle(VecteurMurs[i], sizeMur, sizeMur, nsGraphics::KBlue);
    }
}

/**
 * @brief Procédure de dessin de toutes les BP non-mangées par le PacMan
 * @param[out] Window : 
 * @param[in] Parameters : 
 * @param[in] MapBP : 
 * @fn 
*/
void DrawBP(MinGL & Window, const CMyParam & Parameters, const map<bool, nsGraphics::Vec2D> & MapBP);

void DrawBP(MinGL & Window, const CMyParam & Parameters, const map<bool, nsGraphics::Vec2D> & MapBP)
{
    unsigned sizeBP = Parameters.MapParamSize.find("BPSize")->second;
    for (auto & BP : MapBP){
        if (BP.first == false)
            Window << nsShape::Circle(BP.second, sizeBP, nsGraphics::KWhite);
    }
}

/**
 * @brief Procédure de dessin de tous les fantômes
 * @param[out] Window : 
 * @param[in] Parameters : 
 * @param[in] VecteurGhost : 
 * @fn 
*/
void DrawGhost(MinGL & Window, const CMyParam & Parameters, const vector<GhostSprite> & VecteurGhost);

void DrawGhost(MinGL & Window, const CMyParam & Parameters, const vector<GhostSprite> & VecteurGhost)
{
    for (auto & Ghost : VecteurGhost){
        Window << nsShape::Circle(Ghost.CenterPos, Ghost.Size, Ghost.Color);
        Window << nsShape::Rectangle(nsGraphics::Vec2D(Ghost.CenterPos.getX() - Ghost.Size, Ghost.CenterPos.getY()), Ghost.Size*2, Ghost.Color);
    }
}

