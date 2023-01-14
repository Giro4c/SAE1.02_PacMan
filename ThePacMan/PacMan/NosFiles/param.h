#ifndef PARAM_H
#define PARAM_H

/*!
 * \file collision.h
 * \brief Liste de fonctions et procédures pour l'initialisation et modification des paramètres
 * \version 1.0
 * \date 12 janvier 2023
 */

#include <fstream>
#include "type.h"

/**
 * @brief Initialise le vecteur de string représentant le plateau de jeu
 * @param[out] Plateau : Le vecteur de string représentant le plateau de jeu
 * @fn void InitPlateau (std::vector<std::string> & Plateau);
*/
void InitPlateau (std::vector<std::string> & Plateau);

/**
 * @brief Charge les paramètres modifiables d'une partie
 * @param[out] Param : La struct contenant tous les paramètres nécessaires à une partie
 * @param[in] ConfigFileName : Le nom du fichier de configuration des paramètres
 * @fn void LoadParams (CMyParam & Param, const std::string & ConfigFileName);
*/
void LoadParams (CMyParam & Param, const std::string & ConfigFileName);

/**
 * @brief Initialise les valeurs des maps, vecteurs et autres variables représentées sur le Plateau
 * @param[in] Plateau : Le vecteur de string représentant le plateau de jeu
 * @param[out] Parameters : La struct contenant tous les paramètres nécessaires à une partie
 * @param[out] Pac : La struct contenant toutes les caractéristiques physiques du PacMan
 * @param[out] VecteurMurs : Le vecteur contennant toutes les variables GhostSprite associées à chacun des Ghost d'une partie
 * @param[out] MapBP : Map contenant les coordonnées et statut de toutes les BP du plateau
 * @param[out] ResteBP : Le nombre total de BP qui n'ont pas encore été mangées
 * @param[out] VecteurGhost : Le vecteur contennant toutes les variables GhostSprite associées à chacun des Ghost d'une partie
 * @fn void initMursBPGhost (const vector<string> & Plateau, CMyParam & Parameters, PacMan & Pac, vector<Cposition> & VecteurMurs, map<CPosition, bool> & MapBP, vector<GhostSprite> & VecteurGhost);
*/
void InitMursBPGhost (const std::vector<std::string> & Plateau, CMyParam & Parameters, PacMan & Pac, std::vector<nsGraphics::Vec2D> & VecteurMurs, std::map<nsGraphics::Vec2D, bool> & MapBP, unsigned & ResteBP, std::vector<GhostSprite> & VecteurGhost);


#endif // PARAM_H
