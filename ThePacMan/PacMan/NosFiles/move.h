#ifndef MOVE_H
#define MOVE_H

#include <string>
#include <vector>

#include "type.h"
#include "mingl/mingl.h"
#include "mingl/gui/sprite.h"
#include "mingl/graphics/vec2d.h"
#include "mingl/shape/triangle.h"

using namespace std;

/**
 * @brief Suite d'instructions à effectuer près un appuis de touche de mouvement dont le passage à la nouvelle DirectionActuelle et des modifications de variables
 * @param[out] Pac : 
 * @param[in] Parameters : 
 * @param[in] VecteurMurs :
 * @param[inout] MapNextMur : La map contenant la coordonnée x ou y du prochain Mur pour chaque entité capable de se déplacer
 * @param[in] Combo : Le combo de BP "mangées" d'affilée (intervalle entre 2 BP mangées < 1 sec)
 * @param[in] Touche : Le caractère associé à la touche appuyée
*/
void ChangeDirectionVars (PacMan & Pac, const CMyParam & Parameters, const vector<nsGraphics::Vec2D> & VecteurMurs, map<string, unsigned> & MapNextMur,const unsigned & Combo, const char & Touche);


void clavier(MinGL & Window, const CMyParam & Parameters, PacMan & Pac, const vector<nsGraphics::Vec2D> & VecteurMurs, map<string, unsigned> & MapNextMur,const unsigned & Combo);
void dessiner(MinGL &window, PacMan &pacman, nsShape::Triangle &bouche);

#endif // MOVE_H
