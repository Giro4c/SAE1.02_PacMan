#ifndef PARAM_H
#define PARAM_H

/*!
 * \file collision.h
 * \brief Liste de fonctions et procédures pour l'initialisation et modification des paramètres
 * \author Camille Girodengo
 * \version 1.0
 * \date 12 janvier 2023
 */

#include <fstream>
#include ""



/**
 * @brief Initialise les valeurs des maps, vecteurs et autres variables représentées sur le Plateau
 * @param[in] Plateau : Le vecteur de string représentant le plateau de jeu
 * @param[out] Parameters : 
 * @param[out] Pac :
 * @param[out] VecteurMurs :
 * @param[out] MapBP :
 * @param[out] ResteBP : Le nombre total de BP qui n'ont pas encore été mangées
 * @param[out] VecteurGhost :
 * @fn void initMursBPGhost (const vector<string> & Plateau, CMyParam & Parameters, PacMan & Pac, vector<Cposition> & VecteurMurs, map<CPosition, bool> & MapBP, vector<GhostSprite> & VecteurGhost);
*/
void initMursBPGhost (const vector<string> & Plateau, CMyParam & Parameters, PacMan & Pac, vector<Cposition> & VecteurMurs, map<CPosition, bool> & MapBP, unsigned & ResteBP, vector<GhostSprite> & VecteurGhost);


#endif // PARAM_H