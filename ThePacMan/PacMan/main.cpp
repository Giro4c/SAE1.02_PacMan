#define FPS_LIMIT 60
#include <iostream>
#include <algorithm>
// Pour les chronos
#include <chrono>
#include <unistd.h>

#include "NosFiles/type.h"
#include "NosFiles/param.h"
#include "NosFiles/move.h"
#include "NosFiles/draw.h"

#include "NosFiles/collision.h"
#include "mingl/mingl.h"
#include "mingl/shape/rectangle.h"
#include "mingl/shape/triangle.h"
#include "mingl/transition/transition.h"
#include "mingl/transition/transition_engine.h"
#include "mingl/gui/text.h"

using namespace std;

/*
// Procédure pour vérifier les co des murs
void vectmurs(vector<nsGraphics::Vec2D> & vecteurMur) {
    for(auto & mur : vecteurMur){
        cout << mur.getX();
        cout << " ";
        cout << mur.getY();
        cout << endl;
    }
}
*/

int main()
{
    // Initialise le plateau
    vector<string> plateau;
    InitPlateau(plateau);

    // Initialise les paramètres et autres variables
    CMyParam params;
    LoadParams(params, "../PacMan/config.yaml");

    PacMan pac;
    pac.Vitesse = params.MapParamSpeed.find("PacDefaultSpeed")->second;
    pac.Size = params.MapParamSize.find("PacSize")->second;
    vector<nsGraphics::Vec2D> vecteurMurs;
    vector<GhostSprite> vecteurGhost (2);
    InitGhost(params, vecteurGhost);
    map<nsGraphics::Vec2D, bool> mapBP;
    unsigned resteBP (0);
    InitMursBPGhost(plateau, params, pac, vecteurMurs, mapBP,resteBP, vecteurGhost);
//    vectmurs(vecteurMurs);

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
    nsShape::Triangle bouche({0,0}, {0,0}, {0,0}, nsGraphics::KBlack);
    tst.startContract(nsTransition::TransitionContract(bouche, bouche.TRANSITION_FILL_COLOR_ALPHA, chrono::milliseconds(100), {0}, chrono::milliseconds(0), nsTransition::Transition::TransitionMode::MODE_LOOP_SMOOTH));


    // Lance les différents chronos utilisés dans une partie
        /* La balise temporelle qui marque le contact entre PacMan et une BP*/
    auto tpBPContactStart = chrono::steady_clock::now();
        /* La balise temporelle qui marque la fin de la timelapse entre 2 contacts Pac / BP */
    auto tpBPContactEnd = chrono::steady_clock::now();
        /* La balise temporelle de début de partie*/
    auto timerStart = chrono::steady_clock::now();
        /* Le chrono de la partie */
    auto timerEnd = chrono::steady_clock::now();

    // On fait tourner la boucle tant que la fenêtre est ouverte
    while (window.isOpen())
    {
        // Récupère l'heure actuelle
        chrono::time_point<chrono::steady_clock> start = chrono::steady_clock::now();
        // Récupère le temps écoulé depuixs le début de la partie
        timerEnd = chrono::steady_clock::now();

        // On efface la fenêtre
        window.clearScreen();

        // Vérification de variables suceptibles de déclencher une fin de partie
        if (chrono::duration_cast<chrono::seconds>(timerEnd - timerStart).count() > chrono::seconds(180).count() || resteBP == 0)
            finPartie = true;

        // Affichage des murs
        DrawMurs(window, params, vecteurMurs);

        if (finPartie == false)
        {
            // Récupère le temps entre 2 contacts Pac / BP
            tpBPContactEnd = chrono::steady_clock::now();
            // Annulation du combo si dernier contact avec une BP date de plus d'une (1) seconde
            if (chrono::duration_cast<chrono::milliseconds>(tpBPContactEnd - tpBPContactStart).count() > chrono::milliseconds(1500).count())
                combo = 0;

            // Mouvement du PacMan
            MovePac(window, params, pac, vecteurMurs, mapNextMur, combo);

            // Mouvement des Fantomes
            for (GhostSprite & ghost : vecteurGhost){
                MoveGhost(window, params, ghost, vecteurMurs, mapNextMur);
            }

            // Vérification des collisions (sauf murs)
            if (CollisionPacGhost(pac, vecteurGhost) == true){
                finPartie = true;
                continue;
            }
            CollisionBPPossible (pac, mapBP, params, mapBPPossible);
            if (CollisionPacBP (pac, params, mapBPPossible).first == true){
                // Modif des Map BP
                mapBP.find((CollisionPacBP (pac, params, mapBPPossible).second)) = true;
                mapBPPossible.find((CollisionPacBP (pac, params, mapBPPossible).second)) = true;
                // Actions et modifs des autres variables
                ++combo;
                --resteBP;
                score = score + 100*(1 + ((combo - 1)* 0.01));
                tpBPContactStart = chrono::steady_clock::now();
            }
            // Affichage des Entités (sauf murs)
            DrawBP(window, params, mapBP);
            DrawPac(window, pac, bouche);
            DrawGhost(window, params, vecteurGhost);

        }
        // Fin de partie == true
        else
        {
            // Affiche le rectangle du score
            window << nsShape::Rectangle(nsGraphics::Vec2D(100, 100), 100, 75, nsGraphics::KWhite);
            // Affiche le score
            unsigned UIntScore = unsigned(score);
            window << nsGui::Text(nsGraphics::Vec2D(150, 135), to_string(UIntScore), nsGraphics::KBlack, nsGui::GlutFont::BITMAP_9_BY_15,
                          nsGui::Text::HorizontalAlignment::ALIGNH_CENTER);
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
