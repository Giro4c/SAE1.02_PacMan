#ifndef TYPE_H
#define TYPE_H

/*!
 * \file type.h
 * \brief Liste des types et struct utilisés
 * \version 1.0
 * \date 12 janvier 2023
 */

#include <string>
#include <vector>
#include <map>
#include <thread>


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
    const std::vector <std::string> VParamChar {"PacKeyUp", "PacKeyDown", "PacKeyLeft", "PacKeyRight", "G1KeyUp", "G1KeyDown", "G1KeyLeft", "G1KeyRight", "G2KeyUp", "G2KeyDown", "G2KeyLeft", "G2KeyRight"};
    /** List of authorized key for the type RGBAColor in a struct CMyParam*/
    const std::vector <std::string> VParamRGBAColor {"ColorWall", "ColorGhost1", "ColorGhost2"};
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
    {"KBlack", {0, 0, 0}},
    {"KRed", {255, 0, 0}},
    {"KGreen", {0, 255, 0}},
    {"KWhite", {255, 255, 255}},
    {"KBlue", {0, 0, 255}},
};



/**
 * @brief PacMan : Struct contenant les informations sur le pacman
 */
struct PacMan
{
    nsGraphics::Vec2D CenterPos = nsGraphics::Vec2D(0, 0);
    char DirectionActuelle = 'c';
    char DirectionPred = 'b';
    unsigned Vitesse;
    unsigned Size;
    nsGraphics::Vec2D BouchePosA;
    nsGraphics::Vec2D BouchePosB;
};

/**
 * @brief Struct pour les fantomes
 */
struct GhostSprite
{
    unsigned ID;
    nsGraphics::Vec2D CenterPos = nsGraphics::Vec2D(0, 0);
    char DirectionActuelle = 'c';
    char DirectionPred = 'b';
    unsigned Size;
    unsigned Vitesse;
    nsGraphics::RGBAcolor Color = nsGraphics::RGBAcolor(255, 255, 255);
};

#endif // TYPE_H
