#define FPS_LIMIT 60
#include <iostream>
#include <thread>

#include "mingl/mingl.h"

#include "mingl/shape/circle.h"
#include "mingl/shape/shape.h"
#include "mingl/shape/rectangle.h"
#include "mingl/shape/triangle.h"
#include "mingl/transition/transition.h"
#include "mingl/transition/transition_engine.h"

using namespace nsTransition;
using namespace std;
using namespace nsGraphics;
using namespace nsShape;


struct Pacman
{
    nsGraphics::Vec2D Position;
    string DirectionActuelle;
    string DirectionPrecédent;
    unsigned vitesse;
    const unsigned rayon;
    nsGraphics::Vec2D BouchePosA;
    nsGraphics::Vec2D BouchePosB;
};

void clavier(MinGL &window, Pacman &pacman)
{
    // On vérifie si ZQSD est pressé, et met a jour la position
    pacman.DirectionPrecédent= pacman.DirectionActuelle;
    if (window.isPressed({'z', false})){
        pacman.Position.setY(pacman.Position.getY() - pacman.vitesse);
            pacman.DirectionActuelle= "haut";
        }
    else if (window.isPressed({'s', false})){
        pacman.Position.setY(pacman.Position.getY() + pacman.vitesse);
        pacman.DirectionActuelle = "bas";
    }
    else if (window.isPressed({'q', false})){
        pacman.Position.setX(pacman.Position.getX() - pacman.vitesse);
        pacman.DirectionActuelle = "gauche";
    }
    else if (window.isPressed({'d', false})){
        pacman.Position.setX(pacman.Position.getX() + pacman.vitesse);
        pacman.DirectionActuelle = "droite";
    }
}

void dessiner(MinGL &window, Pacman &pacman)
{
    // On dessine le rectangle
    window<<nsShape::Circle (pacman.Position, 25, nsGraphics::KYellow);
    if (pacman.DirectionActuelle== "haut"){
        pacman.BouchePosA = {pacman.Position.getX()-20,pacman.Position.getY()-25};
        pacman.BouchePosB = {pacman.Position.getX()+20,pacman.Position.getY()-25};}
    else if (pacman.DirectionActuelle== "bas"){
        pacman.BouchePosA = {pacman.Position.getX()-20,pacman.Position.getY()+25};
        pacman.BouchePosB = {pacman.Position.getX()+20,pacman.Position.getY()+25};}
    else if (pacman.DirectionActuelle == "gauche"){
        pacman.BouchePosA = {pacman.Position.getX()-25,pacman.Position.getY()-20};
        pacman.BouchePosB = {pacman.Position.getX()-25,pacman.Position.getY()+20};}
    else if (pacman.DirectionActuelle == "droite"){
        pacman.BouchePosA = {pacman.Position.getX()+25,pacman.Position.getY()-20};
        pacman.BouchePosB = {pacman.Position.getX()+25,pacman.Position.getY()+20};}
    window << nsShape::Triangle(pacman.Position,pacman.BouchePosA,pacman.BouchePosB,KBlack);
}

int main()
{
    // Initialise le système
    MinGL window("pacman", nsGraphics::Vec2D(640, 640), nsGraphics::Vec2D(128, 128), nsGraphics::KBlack);
    window.initGlut();
    window.initGraphic();

    // Variable qui tient le temps de frame
    chrono::microseconds frameTime = chrono::microseconds::zero();

    nsTransition::TransitionEngine tst;

    Pacman pacman = {
        {0,0}, // position
        "right", //posActu
        "right", // posPrev
        2, // vitesse
        25, // rayon
        {0,0}, //posBoucheA
        {0,0} // posBoucheB
    };

    // On fait tourner la boucle tant que la fenêtre est ouverte
    while (window.isOpen())
    {
        // Récupère l'heure actuelle
        chrono::time_point<chrono::steady_clock> start = chrono::steady_clock::now();

        // On efface la fenêtre
        window.clearScreen();
            tst.update(frameTime);

        // On fait tourner les procédures
        clavier(window, pacman);
        dessiner(window, pacman);

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
