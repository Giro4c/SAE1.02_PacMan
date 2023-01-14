#ifndef MOVE_H
#define MOVE_H

#include <string>
#include <vector>

#include "type.h"
#include "mingl/mingl.h"
#include "mingl/graphics/vec2d.h"
#include "mingl/shape/triangle.h"
#include "collision.h"

using namespace std;

/**
 * @brief Suite d'instructions à effectuer près un appuis de touche de mouvement dont le passage à la nouvelle DirectionActuelle et des modifications de variables
 * @param[out] Pac : La struct contenant toutes les caractéristiques physiques du PacMan
 * @param[in] Parameters : La struct contenant tous les paramètres nécessaires à une partie
 * @param[in] VecteurMurs : Le vecteur contennant toutes les variables GhostSprite associées à chacun des Ghost d'une partie
 * @param[inout] MapNextMur : La map contenant la coordonnée x ou y du prochain Mur pour chaque entité capable de se déplacer
 * @param[in] Combo : Le combo de BP "mangées" d'affilée (intervalle entre 2 BP mangées < 1 sec)
 * @param[in] Touche : Le caractère associé à la touche appuyée
*/
void ChangeDirectionVars (PacMan & Pac, const CMyParam & Parameters, vector<nsGraphics::Vec2D> & VecteurMurs, map<string, unsigned> & MapNextMur,const unsigned & Combo, const char & Touche);

/**
 * @brief Permet de diriger le pacman
 * @param[in] Window: utilisation des fonctions contenues dans le fichier MinGL
 * @param[out] Pac : La struct contenant toutes les caractéristiques physiques du PacMan
 * @param[in] Parameters : La struct contenant tous les paramètres nécessaires à une partie
 * @param[in] VecteurMurs : Le vecteur contennant toutes les variables GhostSprite associées à chacun des Ghost d'une partie
 * @param[inout] MapNextMur : La map contenant la coordonnée x ou y du prochain Mur pour chaque entité capable de se déplacer
 * @param[in] Combo : Le combo de BP "mangées" d'affilée (intervalle entre 2 BP mangées < 1 sec)
 * @fn void MovePac(MinGL & Window, const CMyParam & Parameters, PacMan & Pac, const vector<nsGraphics::Vec2D> & VecteurMurs, map<string, unsigned> & MapNextMur,const unsigned & Combo);
*/
void MovePac(MinGL & Window, const CMyParam & Parameters, PacMan & Pac, vector<nsGraphics::Vec2D> & VecteurMurs, map<string, unsigned> & MapNextMur,const unsigned & Combo);

/**
 * @brief Permet de dessiner et animer pacman
 * @param[in] Window: utilisation des fonctions contenues dans le fichier MinGL, la fenêtre
 * @param[out] Pac : La struct contenant toutes les caractéristiques physiques du PacMan
 * @param[in] Bouche: Animation de la bouche de Pacman
 * @fn void Dessiner(MinGL & Window, PacMan & Pac, nsShape::Triangle & Bouche);
*/
void Dessiner(MinGL & Window, PacMan & Pac, nsShape::Triangle & Bouche);

#endif // MOVE_H
