#ifndef DRAW_H
#define DRAW_H

/*!
 * \file draw.h
 * \brief Liste des types et struct utilisés
 * \version 1.0
 * \date 12 janvier 2023
 */

#include "type.h"

#include "mingl/mingl.h"
#include "mingl/gui/sprite.h"
#include "mingl/graphics/vec2d.h"
#include "mingl/shape/triangle.h"
#include "mingl/shape/circle.h"
#include "mingl/shape/rectangle.h"


/**
 * @brief Procédure de dessin de tous les fantômes
 * @param[out] Window : La fenêtre d'affichage
 * @param[in] Parameters : La struct contenant tous les paramètres nécessaires à une partie
 * @param[in] VecteurGhost : Le vecteur contennant toutes les variables GhostSprite associées à chacun des Ghost d'une partie
 * @fn 
*/
void DrawGhost(MinGL & Window, const CMyParam & Parameters, const std::vector<GhostSprite> & VecteurGhost);

/**
 * @brief Procédure de dessin de toutes les BP non-mangées par le PacMan
 * @param[out] Window : 
 * @param[in] Parameters : 
 * @param[in] MapBP : 
 * @fn 
*/
void DrawBP(MinGL & Window, const CMyParam & Parameters, const std::map<bool, nsGraphics::Vec2D> & MapBP);

/**
 * @brief Procédure de dessin des murs du plateau
 * @param[out] Window : La fenêtre sur laquelle s'afficherons les formes
 * @param[in] Parameters : 
 * @param[in] VecteurMurs : 
 * @fn void DrawMurs(MinGL & Window, const CMyParam & Parameters, const vector<nsGraphics::Vec2D> & VecteurMurs); 
*/
void DrawMurs(MinGL & Window, const CMyParam & Parameters, const std::vector<nsGraphics::Vec2D> & VecteurMurs); 

/**
 * @brief Permet de dessiner et animer pacman
 * @param[out] Window: utilisation des fonctions contenues dans le fichier MinGL, la fenêtre
 * @param[out] Pac : La struct contenant toutes les caractéristiques physiques du PacMan
 * @param[out] Bouche: Animation de la bouche de Pacman
 * @fn void Dessiner(MinGL & Window, PacMan & Pac, nsShape::Triangle & Bouche);
*/
void DrawPac(MinGL & Window, PacMan & Pac, nsShape::Triangle & Bouche);


#endif // DRAW_H