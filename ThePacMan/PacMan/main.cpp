#define FPS_LIMIT 60
#include <iostream>
#include <thread>

#include "NosFiles/param.h"
#include "NosFiles/move.h"
#include "NosFiles/type.h"
#include "mingl/mingl.h"
#include "mingl/shape/circle.h"
#include "mingl/shape/triangle.h"
#include "mingl/transition/transition.h"
#include "mingl/transition/transition_engine.h"

using namespace std;

int main()
{
    // Initialise le plateau
    vector<string> plateau;
    InitPlateau(plateau);

    // Initialise les paramètres et autres variables
    CMyParam params;
    LoadParams(params, "config.yaml");

    PacMan pac;
    pac.Vitesse = params.MapParamSpeed.find("PacDefaultSpeed")->second;
    pac.Size = params.MapParamSize.find("PacSize")->second;
    vector<nsGraphics::Vec2D> vecteurMurs;
    vector<GhostSprite> vecteurGhost (2);
    InitGhost(params, vecteurGhost); 
    map<nsGraphics::Vec2D, bool> mapBP;
    unsigned resteBP (0);
    InitMursBPGhost(plateau, params, pac, vecteurMurs, mapBP, vecteurGhost);


    bool finPartie = false;
    float score (0);
    unsigned combo (0);

    map<nsGraphics::Vec2D, bool> mapBPPossible;
    map<string, unsigned> mapNextMur;

    // Initialise le système
    MinGL window("Pac Man", nsGraphics::Vec2D(640, 640), nsGraphics::Vec2D(128, 128), nsGraphics::KBlack);
    window.initGlut();
    window.initGraphic();

    // Variable qui tient le temps de frame
    chrono::microseconds frameTime = chrono::microseconds::zero();
    nsTransition::TransitionEngine tst;

    // Initialisation de la bouche du pacman
    nsShape::Triangle bouche({0,0}, {0,0}, {0,0}, KBlack);
    tst.startContract(nsTransition::TransitionContract(bouche, bouche.TRANSITION_FILL_COLOR_ALPHA, chrono::milliseconds(100), {0}, chrono::milliseconds(0), nsTransition::Transition::TransitionMode::MODE_LOOP_SMOOTH));


    // Lance les différents chronos utilisés dans une partie
    timelapse; /* *********************** A CREER *************************** */
    timer; /* *********************** A CREER *************************** */

    // On fait tourner la boucle tant que la fenêtre est ouverte
    while (window.isOpen())
    {
        // Récupère l'heure actuelle
        chrono::time_point<chrono::steady_clock> start = chrono::steady_clock::now();

        // On efface la fenêtre
        window.clearScreen();

        // Vérification de variables suceptibles de déclencher une fin de partie
        if (timer < 3min || resteBP == 0)
                finPartie = true;

        // Affichage des murs
        DrawMurs(window, params, vecteurMurs);

        if (finPartie == false)
        {
            // Annulation du combo si dernier contact avec une BP date de plus d'une (1) seconde
            if (timelapse > 1 sec)
                combo = 0;

            // Mouvement du PacMan
            clavier(window, pac);

            // Mouvement des Fantomes
            Aaaa;

            // Affichage des Entités (sauf murs)
            DrawBP(window, params, mapBP);
            dessiner(window, pac, bouche);
            DrawGhost(window, params, vecteurGhost);

        }
        // Fin de partie == true
        else
        {
            // Affiche le rectangle du score
            window << nsShape::Rectangle(nsGraphics::Vec2D(100, 100), 100, 75, nsGraphics::KWhite);
            // Affiche le score
            window << ; /* *********************** A CREER *************************** */
        }

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