#ifndef COLLISION_H
#define COLLISION_H

/*!
 * \file collision.h
 * \brief Liste de fonctions et procédures pour la vérification de collisions
 * \version 1.0
 * \date 11 janvier 2023
 */

#include <utility>
#include <map>
#include <vector>
#include "type.h"
#include <algorithm>
#include <utility>

/* ************************  PacMan / Mur  ************************** */

/**
 * @brief Renvoie la coordonnée x ou y de l'extrémité du mur en risque de collision qui se trouve sur la trajectoire du pacman
 * @param[in] Pac : La struct contenant les caractéristiques nécessaires aux évaluations de collision Pac/Mur
 * @param[in] CaseSize : La largeur et longueur d'une case du plateau
 * @param[in] VecteurMurs : Le vecteur contenant la localisation de l'extrémité en haut à gauche d'une case "Mur"
 * @param[in] Parameters : La struct contenant tous les paramètres nécessaires à une partie
 * @fn unsigned CoNextMur (const PacMan & Pac, const unsigned & CaseSize, const std::vector<nsGraphics::Vec2D> & VecteurMurs, const CMyParam & Parameters);
*/
unsigned CoNextMur (const PacMan & Pac, const unsigned & CaseSize, std::vector<nsGraphics::Vec2D> & VecteurMurs, const CMyParam & Parameters);


/**
 * @brief Détermine si le prochain déplacement est une collision avec un mur et renvoie la nouvelle vitesse pour l'éviter si c'est le cas
 * @param[in] Pac : La struct contenant les caractéristiques nécessaires aux évaluations de collision Pac/Mur
 * @param[in] Vitesse : La vitesse de déplacement de PacMan (en pixels)
 * @param[in] Parameters : La struct contenant tous les paramètres nécessaires à une partie
 * @param[in] ValCoNextMur : La coordonnée x ou y de l'extémité du prochain mur
 * @return Vrai et la distance entre extémité_mur et extémité_pacman + vitesse -1 qui sera la nouvelle vitesse temporaire en attendant un changement de direction.
 * @fn pair <bool, unsigned> CollisionPacMur (const PacMan & Pac, const unsigned & Vitesse, const CMyParam & Parameters, const unsigned & ValCoNextMur);
*/
std::pair <bool, unsigned> CollisionPacMur (const PacMan & Pac, const unsigned & Vitesse, const CMyParam & Parameters, const unsigned & ValCoNextMur);


/* ************************  Fantome / Mur  ************************** */

/**
 * @brief Renvoie la coordonnée x ou y de l'extrémité du mur en risque de collision qui se trouve sur la trajectoire du fantome
 * @param[in] Ghost : La struct contenant les caractéristiques nécessaires aux évaluations de collision Ghost/Mur
 * @param[in] CaseSize : La largeur et longueur d'une case du plateau
 * @param[in] VecteurMurs : Le vecteur contenant la localisation de l'extrémité en haut à gauche d'une case "Mur"
 * @param[in] Parameters : La struct contenant tous les paramètres nécessaires à une partie
 * @fn unsigned CoNextMur (const GhostSprite & Ghost, const unsigned & CaseSize, std::vector<nsGraphics::Vec2D> & VecteurMurs, const CMyParam & Parameters);
*/
unsigned CoNextMur (const GhostSprite & Ghost, const unsigned & CaseSize, std::vector<nsGraphics::Vec2D> & VecteurMurs, const CMyParam & Parameters);


/**
 * @brief Détermine si le prochain déplacement est une collision avec un mur et renvoie la nouvelle vitesse pour l'éviter si c'est le cas
 * @param[in] Ghost : La struct contenant les caractéristiques nécessaires aux évaluations de collision Ghost/Mur
 * @param[in] Vitesse : La vitesse de déplacement du Fantome (en pixels)
 * @param[in] Parameters : La struct contenant tous les paramètres nécessaires à une partie
 * @param[in] ValCoNextMur : La coordonnée x ou y de l'extémité du prochain mur
 * @return Vrai et la distance entre extémité_mur et extémité_fantome + vitesse -1 qui sera la nouvelle vitesse temporaire en attendant un changement de direction.
 * @fn std::pair <bool, unsigned> CollisionGhostMur (const GhostSprite & Ghost, const unsigned & Vitesse, const CMyParam & Parameters, const unsigned & ValCoNextMur);
*/
std::pair <bool, unsigned> CollisionGhostMur (const GhostSprite & Ghost, const unsigned & Vitesse, const CMyParam & Parameters, const unsigned & ValCoNextMur);


/* ************************  PacMan / Fantome (Ghost) ************************** */

/**
 * @brief Détermine si la coordonnée XPointFantome du possible point de collision se trouve dans de l'intervalle d'abscisse de la "HitBox" du PacMan. CAD, entre les coordonnées x des extrémités droites et gauches.
 * @param[in] XCenterPac : La coordonnée x du centre du PacMan et par extension sa HitBox
 * @param[in] XPointFantome : La coordonnée x d'un point d'extémité du Fantome et par extension le carré contenant sa HitBox
 * @param[in] SizePac : Le rayon du cercle qui compose le PacMan
 * @fn bool xFInsideHitBoxPacX (const unsigned & XCenterPac, const unsigned XPointFantome, const unsigned SizePac);
*/
bool xFInsideHitBoxPacX (const unsigned & XCenterPac, const unsigned XPointFantome, const unsigned SizePac);

/**
 * @brief Détermine si la coordonnée YPointFantome du possible point de collision se trouve dans de l'intervalle d'ordonnée de la "HitBox" du PacMan en fonction de la coordonnée x du point en question. CAD, entre les coordonnées y des extrémités droites et gauches.
 * @param[in] YCenterPac : La coordonnée x du centre du PacMan et par extension sa HitBox
 * @param[in] YPointFantome : La coordonnée x d'un point d'extémité du Fantome et par extension le carré contenant sa HitBox
 * @param[in] SizePac : Le rayon du cercle qui compose les PacMan
 * @param[in] XCenterPac : La coordonnée x du centre du PacMan et par extension sa HitBox
 * @param[in] XPointFantome : La coordonnée x d'un point d'extémité du Fantome et par extension le carré contenant sa HitBox
 * @fn bool yFInsideHitBoxPacY (const unsigned & YCenterPac, const unsigned YPointFantome, const unsigned SizePac,const unsigned & XCenterPac, const unsigned XPointFantome);
*/
bool yFInsideHitBoxPacY (const unsigned & YCenterPac, const unsigned YPointFantome, const unsigned SizePac,const unsigned & XCenterPac, const unsigned XPointFantome);

/**
 * @brief Détermine s'il y a réel contact entre la hitbox PacMan et celle (complexe) du Fantome pour sa partie supérieure
 * @param[in] Pac : La struct contenant toutes les caractéristiques physiques du PacMan
 * @param[in] xGFirstContact : La coordonnée x du point de collision détecté de la HitBox simple (carrée) du Ghost
 * @param[in] XGFirstContact : La coordonnée y du point de collision détecté de la HitBox simple (carrée) du Ghost
 * @param[in] Ghost : La struct contenant toutes les caractéristiques du Ghost
 * @fn bool RealHitGhost (const PacMan & Pac, const unsigned & xGFirstContact, const unsigned & yGFirstContact, const unsigned & SizeGhost);
*/
bool RealHitGhost (const PacMan & Pac, const unsigned & xGFirstContact, const unsigned & yGFirstContact, const unsigned & SizeGhost);

/**
 * @brief Détermine s'il y a collision entre PacMan et un des Ghost
 * @param[in] Pac : La struct contenant toutes les caractéristiques physiques du PacMan
 * @param[in] VecteurGhost : Le vecteur contennant toutes les variables GhostSprite associées à chacun des Ghost d'une partie
 * @fn bool CollisionPacGhost (const PacMan & Pac, const std::vector<GhostSprite> & VecteurGhost);
*/
bool CollisionPacGhost (const PacMan & Pac, std::vector<GhostSprite> & VecteurGhost);


/* ************************  PacMan / Boule-Point (BP)  ************************** */

/**
 * @brief Procédure qui construit la map des BP sur la trajectoire du pacman en fonction de la direction
 * @param[in] Pac : La struct contenant toutes les caractéristiques physiques du PacMan
 * @param[in] Parameters : La struct contenant tous les paramètres nécessaires à une partie
 * @param[in] MapBP : Map contenant les coordonnées et statut de toutes les BP du plateau
 * @param[inout] MapBPPossible : Map contenant les coordonnées et statut de toutes les BP sur la trajectoire du pacman
 * @fn void CollisionBPPossible (const PacMan & Pac, std::map<nsGraphics::Vec2D, bool> & MapBP, const CMyParam & Parameters, std::map<nsGraphics::Vec2D, bool> & MapBPPossible);
*/
void CollisionBPPossible (const PacMan & Pac, std::map<nsGraphics::Vec2D, bool> & MapBP, const CMyParam & Parameters, std::map<nsGraphics::Vec2D, bool> & MapBPPossible);

/**
 * @brief Renvoie Vrai et les coordonnées du centre de la Boule Point s'il y a collision entre pacman et une BP
 * @param[in] Pac : La struct contenant toutes les caractéristiques physiques du PacMan
 * @param[in] Parameters : La struct contenant tous les paramètres nécessaires à une partie
 * @param[in] MapBPPossible : Map contenant les coordonnées et statut de toutes les BP sur la trajectoire du pacman
 * @fn std::pair <bool, nsGraphics::Vec2D> CollisionPacBP (const PacMan & Pac, const CMyParam & Parameters, const std::map<nsGraphics::Vec2D, bool> & MapBPPossible);
*/
std::pair <bool, nsGraphics::Vec2D> CollisionPacBP (const PacMan & Pac, const CMyParam & Parameters, const std::map<nsGraphics::Vec2D, bool> & MapBPPossible);


#endif // COLLISION_H
