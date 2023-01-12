#include "game.h"

using namespace std;

int main()
{
    // Initialise le plateau
    vector<string> plateau = {};
    
    // Initialise les paramètres et autres variables
    CMyParam params;
    LoadParams(params, "config.yaml");

    PacMan pac;
    vector<nsGraphics::Vec2D> vecteurMurs;
    vector<GhostSprite> vecteurGhost (4);
    InitColorGhost(params, vecteurGhost); /* *********************** A CREER *************************** */
    map<nsGraphics::Vec2D, bool> mapBP;
    unsigned resteBP (0);
    initMursBPGhost(plateau, params, pac, vecteurMurs, mapBP, vecteurGhost);

    bool finPartie = false;
    float Score (0);
    unsigned Combo (0);
    unsigned Vitesse (3);
    
    map<nsGraphics::Vec2D, bool> mapBPPossible;
    unsigned valCoNextMur;

    // Initialise le système
    MinGL window("Pac Man", nsGraphics::Vec2D(640, 640), nsGraphics::Vec2D(128, 128), nsGraphics::KBlack);
    window.initGlut();
    window.initGraphic();

    // Variable qui tient le temps de frame
    chrono::microseconds frameTime = chrono::microseconds::zero();

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
        if (timer < 3min || ResteBP == 0)
                FinPartie = true;
        
        // Affichage des murs
        drawMurs(window, params, vecteurMurs); /* *********************** A CREER *************************** */

        if (finPartie == false)
        {
            // Annulation du combo si dernier contact avec une BP date de plus d'une (1) seconde
            if (timelapse > 1 sec)
                combo = 0;
                
            // Mouvement
            Aaaa;

            // Affichage des Entités (sauf murs)
            drawBP(window, params, mapBP); /* *********************** A CREER *************************** */
            drawPac(window, params, pac); /* *********************** A CREER *************************** */
            drawGhost(window, params, vecteurGhost); /* *********************** A CREER *************************** */

        }
        // Fin de partie == true
        else 
        {
            // Affiche le rectangle du score
            window << ; /* *********************** A CREER *************************** */
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
