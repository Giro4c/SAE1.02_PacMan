#define FPS_LIMIT 60
#include <iostream>
#include <thread>

#include "move.h"
#include "mingl/mingl.h"
#include "mingl/shape/circle.h"
#include "mingl/shape/triangle.h"
#include "mingl/transition/transition.h"
#include "mingl/transition/transition_engine.h"

using namespace nsTransition;
using namespace std;
using namespace nsGraphics;
using namespace nsShape;

int main()
{
    // Initialise le système
    MinGL window("ghost", nsGraphics::Vec2D(640, 640), nsGraphics::Vec2D(128, 128), nsGraphics::KBlack);
    window.initGlut();
    window.initGraphic();

    // Variable qui tient le temps de frame
    chrono::microseconds frameTime = chrono::microseconds::zero();
    nsTransition::TransitionEngine tst;

    // initialisation de l'objet ghost
    Ghost ghost = {
        {0,0}, // position
        "right", //posActu
        "right", // posPrev
        2, // vitesse
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
        clavier(window, ghost);
        dessiner(window, ghost);

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
