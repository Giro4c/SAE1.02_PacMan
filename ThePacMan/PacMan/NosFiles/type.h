#ifndef TYPE_H
#define TYPE_H

/*!
 * \file type.h
 * \brief Liste des types et struct utilisés
 * \author Camille Girodengo
 * \version 1.0
 * \date 12 janvier 2023
 */

#include <string>
#include <vector>
#include <map>

#include "mingl/mingl.h"
#include "mingl/gui/sprite.h"
#include "mingl/graphics/vec2d.h"
#include "mingl/shape/triangle.h"

/**
 * @brief Struct contenant l'ensemble des paramètres modifiables d'une partie
 */
struct CMyParam {
    std::map <std::string, char> MapParamChar;
    std::map <std::string, unsigned> MapParamSize;
    std::map <std::string, nsGraphics::RGBAcolor> MapParamRGBAColor;
    std::map <std::string, unsigned> MapParamSpeed;

};


/**
 * @brief Struct contenant toutes les clés autorisées pour la struct CMyParam
 */
struct AuthorizedKey {
    /** List of authorized key for the type char in a struct CMyParam*/
    const std::vector <std::string> VParamChar {"KeyUp", "KeyDown", "KeyLeft", "KeyRight"};
    /** List of authorized key for the type RGBAColor in a struct CMyParam*/
    const std::vector <std::string> VParamRGBAColor {"ColorWall", "ColorPac", "ColorGhost1", "ColorGhost2", "ColorGhost3", "ColorGhost4"};
    /** List of authorized key for the type unsigned, mapSize in a struct CMyParam*/
    const std::vector <std::string> VParamSize {"CaseSize", "PacSize", "BPSize", "GhostSize", "WindowWidth", "WindowHeight"};
    /** List of authorized key for the type unsigned, mapSpeed in a struct CMyParam*/
    const std::vector <std::string> VParamSpeed {"PacDefaultSpeed", "PacMaxSpeed", "GhostSpeed"};

};

/**
 * @brief KAuthorizedKey
 */
const AuthorizedKey KAuthorizedKey;

/**
  * @brief KColor : Map contenant des couleurs prédéfinies pour les couleurs RGBAColor
  */

const std::map <std::string, nsGraphics::RGBAcolor> KColor
{
    {"KReset", {200, 50, 0}},
    {"KBlack", {0, 0, 0}},
    {"KRed", {0, 0, 0}},
    {"KGreen", {0, 0, 0}},
    {"KYellow", {0, 0, 0}},
    {"KBlue", {0, 0, 0}},
    {"KMAgenta", {0, 0, 0}},
    {"KCyan", {0, 0, 0}},

};



/**
 * @brief PacMan : Struct contenant les informations sur le pacman
 */
struct PacMan
{
    nsGraphics::Vec2D Position;
    char DirectionActuelle = 'p';
    char DirectionPrecedent = 'm';
    unsigned Vitesse;
    unsigned Size;
    nsGraphics::Vec2D BouchePosA;
    nsGraphics::Vec2D BouchePosB;
};

/**
 * @brief struct pour les fantomes
 * @param CenterPos : la position centrale avec laquelle on commencera à dessiner nos formes
 */

struct GhostSprite
{
    nsGraphics::Vec2D CenterPos = nsGraphics::Vec2D(475,275);
    nsGraphics::RGBAcolor GhostColor = nsGraphics::RGBAcolor(255, 255, 255);
};


#endif // TYPE_H
