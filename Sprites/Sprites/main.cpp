#define FPS_LIMIT 60
//#include "params.h"
//#include "game.h"
#include <iostream>
#include <thread>
#include "mingl/mingl.h"
#include "mingl/shape/rectangle.h"
#include "mingl/shape/circle.h"
#include "mingl/shape/line.h"
#include "mingl/shape/triangle.h"
#include <vector>
#include <algorithm>
#include "mingl/gui/sprite.h"
#include <map>
#include <utility>
#include <random>
#include "Complements/game.h"
#include "Complements/params.h"
#include "Complements/type.h"

using namespace std;

typedef pair <unsigned, unsigned> CPosition; // On définit un pair d'entier naturel

/**
 * @brief struct pour les fantomes
 * @param CenterPos : la position centrale avec laquelle on commencera à dessiner nos formes
 */

struct GhostSprite
{
    nsGraphics::Vec2D CenterPos = nsGraphics::Vec2D(475,275);
    nsGraphics::RGBAcolor GhostColor = nsGraphics::RGBAcolor(100, 200, 50);
};
//void initGhost(vector<GhostSprite>ghostVect)
//{
//    ghostVect[0] = GhostSprite1;
//    ghostVect[1] = GhostSprite2;
//    ghostVect[2] = GhostSprite3;
//    ghostVect[3] = GhostSprite4;
//}


/**
 * @brief initMap
 * @param vectMap :  un vecteur de chaine de chaîne de caractère.
 *  Cette procédure nous permet d'obtenir un vecteur qui sera par la suite transformé en une map
 */
void initMap (vector<string> & vectMap)
{
    vectMap = {
    "xxxxxxxxxxxxxxxxxxxxxx",
    "xn...x..........x....x",
    "x.xx.x.xxxxxxxx.x.xx.x",
    "x.x................x.x",
    "x.x.xx.xxxnnxxx.xx.x.x",
    "x.x....xnnnnnnx....x.x",
    "x...xx.xxxxxxxx.xx...x",
    "x.x................x.x",
    "x.x.xx.xxxxxxxx.xx.x.x",
    "x.x................x.x",
    "x.xx.x.xxxxxxxx.x.xx.x",
    "x....x..........x....xx",
    "xxxxxxxxxxxxxxxxxxxxxx"};
}

/**
 * @brief showMap
 * @param window : la fenêtre qui a été crée dans laquelle nos procédure vont s'exécuter et s'afficher
 * @param vectMap :  un vecteur de chaine de chaîne de caractère.
 * Cette récupère les coordonnées du vecteur de initMap pour dessiner des carrés (de longueur j*50 + 50 et de largeur i*50 + 50) pour les "x" et les "n", des cercles pour les "." affinn d'avoir une map pour le PacMan
 */
void showMap(MinGL &window, vector<string> &vectMap) {
    for (size_t i(0); i < vectMap.size(); ++i) {
        for (size_t j(0); j < vectMap[0].size(); ++j) {
            switch (vectMap[i][j]) {
            case 'x':
                window << nsShape::Rectangle(nsGraphics::Vec2D(j * 50,i * 50), nsGraphics::Vec2D(j * 50 + 50, i * 50+50), nsGraphics::KBlue);
                break;
            case '.':
                window << nsShape::Circle(nsGraphics::Vec2D(j * 50 + 25, i * 50+25), 5, nsGraphics::KWhite);
                break;
            case 'n':
                window << nsShape::Rectangle(nsGraphics::Vec2D(j * 50,i * 50), nsGraphics::Vec2D(j * 50 + 50, i * 50 + 50), nsGraphics::KBlack);
            }
        }
    }
}

/**
 * @brief drawGhost
 * @param window : la fenêtre qui a été crée dans laquelle nos procédure vont s'exécuter et s'afficher
 * @return dessine 4 fantomes avec des couleurs différentes et des positions différentes (seule la valeur de X varie)
 */
void drawGhost (MinGL & window)
{
    GhostSprite G1;
    GhostSprite G2;
    GhostSprite G3;
    GhostSprite G4;

    unsigned largeur_Rayon = 12;
    unsigned longueur = 25;

    //G1
    G1.GhostColor = nsGraphics::RGBAcolor(255,69,0);
    nsShape::Circle head = {nsGraphics::Vec2D(G1.CenterPos), largeur_Rayon, G1.GhostColor};
    nsShape::Rectangle body = {nsGraphics::Vec2D(G1.CenterPos.getX() - largeur_Rayon, G1.CenterPos.getY()), nsGraphics::Vec2D(G1.CenterPos.getX() + largeur_Rayon, G1.CenterPos.getY() + longueur - largeur_Rayon), G1.GhostColor};
    window << head;
    window << body;
    //G2
    G2.CenterPos.setX(G1.CenterPos.getX() + 50);
    G2.GhostColor = nsGraphics::RGBAcolor(255,0,0);
    nsShape::Circle head2 = {nsGraphics::Vec2D(G2.CenterPos), largeur_Rayon, G2.GhostColor};
    nsShape::Rectangle body2 = {nsGraphics::Vec2D(G2.CenterPos.getX() - largeur_Rayon, G2.CenterPos.getY()), nsGraphics::Vec2D(G2.CenterPos.getX() + largeur_Rayon, G2.CenterPos.getY() + longueur - largeur_Rayon), G2.GhostColor};
    window << head2;
    window << body2;
    //G3
    G3.CenterPos.setX(G2.CenterPos.getX() + 50);
    G3.GhostColor = nsGraphics::RGBAcolor(95,158,160);
    nsShape::Circle head3 = {nsGraphics::Vec2D(G2.CenterPos), largeur_Rayon, G3.GhostColor};
    nsShape::Rectangle body3 = {nsGraphics::Vec2D(G3.CenterPos.getX() - largeur_Rayon, G3.CenterPos.getY()), nsGraphics::Vec2D(G3.CenterPos.getX() + largeur_Rayon, G3.CenterPos.getY() + longueur - largeur_Rayon), G3.GhostColor};
    window << head3;
    window << body3;
    //G4
    G4.CenterPos.setX(G3.CenterPos.getX() + 50);
    G4.GhostColor = nsGraphics::RGBAcolor(255,192,203);
    nsShape::Circle head4 = {nsGraphics::Vec2D(G3.CenterPos), largeur_Rayon, G4.GhostColor};
    nsShape::Rectangle body4 = {nsGraphics::Vec2D(G4.CenterPos.getX() - largeur_Rayon, G4.CenterPos.getY()), nsGraphics::Vec2D(G4.CenterPos.getX() + largeur_Rayon, G4.CenterPos.getY() + longueur - largeur_Rayon), G4.GhostColor};
    window << head4;
    window << body4;
}

/**
 * @brief dessiner
 * @param window : la fenêtre qui a été crée dans laquelle nos procédure vont s'exécuter et s'afficher
 * @return Permet de dessiner Pac Man avec des formmes géométriques
 */
void dessiner(MinGL & window)
{
    // PacMan Right
    window << nsShape::Circle(nsGraphics::Vec2D(75, 75), 15, nsGraphics::KYellow);
    window << nsShape::Triangle(nsGraphics::Vec2D(75, 75), nsGraphics::Vec2D(100, 50), nsGraphics::Vec2D(100, 91), nsGraphics::KBlack);
//    // PacMan Left
//    window << nsShape::Circle(nsGraphics::Vec2D(100, 50), 15, nsGraphics::KYellow);
//    window << nsShape::Triangle(nsGraphics::Vec2D(100, 50), nsGraphics::Vec2D(75, 25), nsGraphics::Vec2D(75, 60), nsGraphics::KBlack);
//    // PacMan Up
//    window << nsShape::Circle(nsGraphics::Vec2D(150, 50), 25, nsGraphics::KYellow);
//    window << nsShape::Triangle(nsGraphics::Vec2D(150, 50), nsGraphics::Vec2D(135, 25), nsGraphics::Vec2D(165, 25), nsGraphics::KBlack);
//    // PacMan Down
//    window << nsShape::Circle(nsGraphics::Vec2D(200, 50), 25, nsGraphics::KYellow);
//    window << nsShape::Triangle(nsGraphics::Vec2D(200, 50), nsGraphics::Vec2D(185, 75), nsGraphics::Vec2D(215, 75), nsGraphics::KBlack);
//    // PacMan Rond
//    window << nsShape::Circle(nsGraphics::Vec2D(450, 50), 25, nsGraphics::KYellow);
//    // Boule point petit
//    window << nsShape::Circle(nsGraphics::Vec2D(250, 50), 5, nsGraphics::KWhite);
//    // Boule point grand
//    window << nsShape::Circle(nsGraphics::Vec2D(300, 50), 10, nsGraphics::KWhite);
//    // Fantôme
//    window << nsShape::Circle(nsGraphics::Vec2D(350, 50), 25, nsGraphics::KBlue);
//    window << nsShape::Rectangle(nsGraphics::Vec2D(375, 50), nsGraphics::Vec2D(325, 90), nsGraphics::KBlue);
//    window << nsShape::Triangle(nsGraphics::Vec2D(335, 85), nsGraphics::Vec2D(330, 90), nsGraphics::Vec2D(340, 90), nsGraphics::KBlack);
//    window << nsShape::Triangle(nsGraphics::Vec2D(350, 85), nsGraphics::Vec2D(345, 90), nsGraphics::Vec2D(355, 90), nsGraphics::KBlack);
//    window << nsShape::Triangle(nsGraphics::Vec2D(365, 85), nsGraphics::Vec2D(360, 90), nsGraphics::Vec2D(370, 90), nsGraphics::KBlack);

}

int main()
{
    srand (time(nullptr));
    vector <unsigned> V;
    MinGL window("PacMan", nsGraphics::Vec2D(1100,650), nsGraphics::Vec2D(128, 128), nsGraphics::KBlack);
    window.initGlut();
    window.initGraphic();

    // Variable qui tient le temps de frame
    chrono::microseconds frameTime = chrono::microseconds::zero();

    // initMap
    vector <string> vectMap;
    initMap(vectMap);

    // On fait tourner la boucle tant que la fenêtre est ouverte
    while (window.isOpen())
    {
        // Récupère l'heure actuelle
        chrono::time_point<chrono::steady_clock> start = chrono::steady_clock::now();

        // On efface la fenêtre
        window.clearScreen();

        // Dessin de la map
        showMap(window, vectMap); //affiche la map
        // on dessine un PacMan
        dessiner(window);

        // Affichage des fantomes
        drawGhost(window);

        // On finit la frame en cours
        window.finishFrame();

        // On vide la queue d'évènements
        window.getEventManager().clearEvents();

        // On attend un peu pour limiter le framerate et soulager le CPU
        this_thread::sleep_for(chrono::milliseconds(1000 / FPS_LIMIT) - chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start));

        // On récupère le temps de frame
        frameTime = chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start);
    }
     return 0;
}

