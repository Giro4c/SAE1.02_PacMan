#ifndef DRAW_H
#define DRAW_H

/*!
 * \file draw.h
 * \brief Liste des procédures d'affichage des entités
 * \version 1.0
 * \date 14 janvier 2023
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
 * @param[in] VecteurGhost : Le vecteur contennant toutes les variables GhostSprite associées à chacun des Ghost d'une partie
 * @fn void DrawGhost(MinGL & Window, std::vector<GhostSprite> & VecteurGhost);
*/
void DrawGhost(MinGL & Window, std::vector<GhostSprite> & VecteurGhost);

/**
 * @brief Procédure de dessin de toutes les BP non-mangées par le PacMan
 * @param[out] Window : La fenêtre d'affichage
 * @param[in] Parameters : La struct contenant tous les paramètres nécessaires à une partie
 * @param[in] MapBP : Map contenant les coordonnées et statut de toutes les BP du plateau
 * @fn void DrawBP(MinGL & Window, const CMyParam & Parameters, std::map<bool, nsGraphics::Vec2D> & MapBP);
*/
void DrawBP(MinGL & Window, const CMyParam & Parameters, std::map<nsGraphics::Vec2D,bool> & MapBP);

/**
 * @brief Procédure de dessin des murs du plateau
 * @param[out] Window : La fenêtre sur laquelle s'afficherons les formes
 * @param[in] Parameters : La struct contenant tous les paramètres nécessaires à une partie
 * @param[in] VecteurMurs : Le vecteur contennant toutes les variables GhostSprite associées à chacun des Ghost d'une partie
 * @fn void DrawMurs(MinGL & Window, const CMyParam & Parameters, const vector<nsGraphics::Vec2D> & VecteurMurs); 
*/
void DrawMurs(MinGL & Window, const CMyParam & Parameters, const std::vector<nsGraphics::Vec2D> & VecteurMurs); 

/**
 * @brief Permet de dessiner et animer pacman
 * @param[out] Window: utilisation des fonctions contenues dans le fichier MinGL, la fenêtre
 * @param[in] Parameters : La struct contenant tous les paramètres nécessaires à une partie
 * @param[out] Pac : La struct contenant toutes les caractéristiques physiques du PacMan
 * @param[out] Bouche: Animation de la bouche de Pacman
 * @fn void DrawPac(MinGL & Window, const CMyParam & Parameters, PacMan & Pac, nsShape::Triangle & Bouche);
*/
void DrawPac(MinGL & Window, const CMyParam & Parameters, PacMan & Pac, nsShape::Triangle & Bouche);

#endif // DRAW_H
