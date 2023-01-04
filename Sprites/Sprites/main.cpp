#define FPS_LIMIT 60
#include <iostream>
#include <thread>
#include "mingl/mingl.h"
#include "mingl/shape/rectangle.h"
#include "mingl/shape/circle.h"
#include "mingl/shape/line.h"
#include "mingl/shape/triangle.h"
#include <vector>
#include <algorithm>

using namespace std;
using namespace nsShape;
using namespace nsGraphics;

using namespace std;

void dessiner(MinGL & window)
{
    /*
    //window << nsShape::Rectangle(nsGraphics::Vec2D(30, 30), nsGraphics::Vec2D(160, 160), nsGraphics::KPurple);
    // Pour dessiner quelque chose avec minGL 2, vous pouvez soit instancier l'objet dans une variable et l'injecter dans la fenêtre...
    nsShape::Rectangle rect1(nsGraphics::Vec2D(20, 20), nsGraphics::Vec2D(120, 120), nsGraphics::KBlue);
    window << rect1;

    // ...ou l'injecter directement dans la fenêtre!
    //Exo 1 Rectangles
    window << nsShape::Rectangle(nsGraphics::Vec2D(30, 30), nsGraphics::Vec2D(160, 160), nsGraphics::KPurple);
    window << nsShape::Rectangle(nsGraphics::Vec2D(50, 50), nsGraphics::Vec2D(180, 180), nsGraphics::KGreen);
    window << nsShape::Rectangle(nsGraphics::Vec2D(80, 80), nsGraphics::Vec2D(200, 200), nsGraphics::KBlue);
    // 2 triangles
    window << nsShape::Triangle(nsGraphics::Vec2D(200, 620), nsGraphics::Vec2D(400, 620), nsGraphics::Vec2D(300, 420), nsGraphics::KYellow);
    window << nsShape::Triangle(nsGraphics::Vec2D(400, 620), nsGraphics::Vec2D(600, 620), nsGraphics::Vec2D(500, 420), nsGraphics::KYellow);

    // (Vous voyez par ailleurs que l'ordre d'affichage est important, le rectangle violet masque maintenant une partie du rectangle bleu.)
    // Vous pouvez combiner les différentes formes disponibles pour faire des choses plus complexes.

    // Voilà un bouton de fermeture.
    // 3 cercles
    window << nsShape::Circle(nsGraphics::Vec2D(100, 320), 50, nsGraphics::KRed);
    window << nsShape::Circle(nsGraphics::Vec2D(200, 320), 50, nsGraphics::KRed);
    window << nsShape::Circle(nsGraphics::Vec2D(300, 320), 50, nsGraphics::KRed);

    //1 carré
    window << nsShape::Rectangle(nsGraphics::Vec2D(500, 500), nsGraphics::Vec2D(120, 120), nsGraphics::KBlue);

    window << nsShape::Line(nsGraphics::Vec2D(70, 290), nsGraphics::Vec2D(130, 350), nsGraphics::KWhite, 3.f);
    window << nsShape::Line(nsGraphics::Vec2D(130, 290), nsGraphics::Vec2D(70, 350), nsGraphics::KWhite, 3.f);

    // Et voilà la triforce.

    window << nsShape::Triangle(nsGraphics::Vec2D(200, 620), nsGraphics::Vec2D(400, 620), nsGraphics::Vec2D(300, 420), nsGraphics::KYellow);
    window << nsShape::Triangle(nsGraphics::Vec2D(400, 620), nsGraphics::Vec2D(600, 620), nsGraphics::Vec2D(500, 420), nsGraphics::KYellow);
    window << nsShape::Triangle(nsGraphics::Vec2D(300, 420), nsGraphics::Vec2D(500, 420), nsGraphics::Vec2D(400, 220), nsGraphics::KYellow);


    // N'hésitez pas a lire la doc pour plus de détails.
    */

    // PacMan Right
    window << nsShape::Circle(nsGraphics::Vec2D(50, 50), 25, nsGraphics::KYellow);
    window << nsShape::Triangle(nsGraphics::Vec2D(50, 50), nsGraphics::Vec2D(75, 30), nsGraphics::Vec2D(75, 60), nsGraphics::KBlack);
    // PacMan Left
    window << nsShape::Circle(nsGraphics::Vec2D(100, 50), 25, nsGraphics::KYellow);
    window << nsShape::Triangle(nsGraphics::Vec2D(100, 50), nsGraphics::Vec2D(75, 30), nsGraphics::Vec2D(75, 60), nsGraphics::KBlack);
    // PacMan Up
    window << nsShape::Circle(nsGraphics::Vec2D(150, 50), 25, nsGraphics::KYellow);
    window << nsShape::Triangle(nsGraphics::Vec2D(150, 50), nsGraphics::Vec2D(135, 25), nsGraphics::Vec2D(165, 25), nsGraphics::KBlack);
    // PacMan Down
    window << nsShape::Circle(nsGraphics::Vec2D(200, 50), 25, nsGraphics::KYellow);
    window << nsShape::Triangle(nsGraphics::Vec2D(200, 50), nsGraphics::Vec2D(185, 75), nsGraphics::Vec2D(215, 75), nsGraphics::KBlack);
    // Boule point petit
    window << nsShape::Circle(nsGraphics::Vec2D(250, 50), 5, nsGraphics::KWhite);
    // Boule point grand
    window << nsShape::Circle(nsGraphics::Vec2D(300, 50), 10, nsGraphics::KWhite);
    // Fantôme Bleu
    window << nsShape::Circle(nsGraphics::Vec2D(350, 50), 25, nsGraphics::KBlue);
    window << nsShape::Rectangle(nsGraphics::Vec2D(350, 75), nsGraphics::Vec2D(350,200), nsGraphics::KBlue);
    window << nsShape::Rectangle(nsGraphics::Vec2D(375, 50), nsGraphics::Vec2D(325, 90), nsGraphics::KBlue);
    window << nsShape::Triangle(nsGraphics::Vec2D(335, 85), nsGraphics::Vec2D(330, 90), nsGraphics::Vec2D(340, 90), nsGraphics::KBlack);
    window << nsShape::Triangle(nsGraphics::Vec2D(350, 85), nsGraphics::Vec2D(345, 90), nsGraphics::Vec2D(355, 90), nsGraphics::KBlack);
    window << nsShape::Triangle(nsGraphics::Vec2D(365, 85), nsGraphics::Vec2D(360, 90), nsGraphics::Vec2D(370, 90), nsGraphics::KBlack);
    /*
    // Fantôme Rouge
    window << nsShape::Circle(nsGraphics::Vec2D(350, 50), 25, nsGraphics::KBlue);
    window << nsShape::Rectangle(nsGraphics::Vec2D(350, 75), nsGraphics::Vec2D(350,200), nsGraphics::KRed);
    window << nsShape::Rectangle(nsGraphics::Vec2D(375, 50), nsGraphics::Vec2D(325, 90), nsGraphics::KRed);
    window << nsShape::Triangle(nsGraphics::Vec2D(335, 85), nsGraphics::Vec2D(330, 90), nsGraphics::Vec2D(340, 90), nsGraphics::KBlack);
    window << nsShape::Triangle(nsGraphics::Vec2D(350, 85), nsGraphics::Vec2D(345, 90), nsGraphics::Vec2D(355, 90), nsGraphics::KBlack);
    window << nsShape::Triangle(nsGraphics::Vec2D(365, 85), nsGraphics::Vec2D(360, 90), nsGraphics::Vec2D(370, 90), nsGraphics::KBlack);
    // Fantôme Vert
    window << nsShape::Circle(nsGraphics::Vec2D(350, 50), 25, nsGraphics::KBlue);
    window << nsShape::Rectangle(nsGraphics::Vec2D(350, 75), nsGraphics::Vec2D(350,200), nsGraphics::KGreen);
    window << nsShape::Rectangle(nsGraphics::Vec2D(375, 50), nsGraphics::Vec2D(325, 90), nsGraphics::KGreen);
    window << nsShape::Triangle(nsGraphics::Vec2D(335, 85), nsGraphics::Vec2D(330, 90), nsGraphics::Vec2D(340, 90), nsGraphics::KBlack);
    window << nsShape::Triangle(nsGraphics::Vec2D(350, 85), nsGraphics::Vec2D(345, 90), nsGraphics::Vec2D(355, 90), nsGraphics::KBlack);
    window << nsShape::Triangle(nsGraphics::Vec2D(365, 85), nsGraphics::Vec2D(360, 90), nsGraphics::Vec2D(370, 90), nsGraphics::KBlack);
    */
/*
vector<unsigned> plateau({0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                          0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                           0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                           0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,2,2,2,2,2,2,0
                           0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,2,0,0,0,0,2,0
                           0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,2,0,0,0,0,2,0
                           0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,2,0,0,0,0,2,0
                           0,1,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,2,2,2,2,2,2,2,2,2,0
                           0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0
                           0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0
                           0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,2,2,2,2,0,0,2,0,0,0,0,0,0
                           0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,2,0,0,0,0,0,2,0,0,0,0,0,0
                           0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,2,0,0,0,0,0,2,0,0,0,0,0,0
                           0,0,0,0,0,0,1,0,0,0,0,0,1,1,2,2,0,0,0,0,0,2,0,0,0,0,0,0
                           0,0,0,0,0,0,1,0,0,0,0,0,0,0,2,0,0,0,0,0,0,2,0,0,0,0,0,0
                           0,0,0,0,0,0,1,0,0,0,0,2,2,2,2,1,1,0,0,0,0,2,0,0,0,0,0,0
                           0,0,0,0,0,8,1,8,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0
                           0,0,0,0,0,8,1,8,0,0,0,3,3,3,0,0,4,0,0,0,0,2,0,0,0,0,0,0
                           0,0,0,0,0,8,1,8,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                           0,0,0,0,0,8,1,8,0,0,0,0,0,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0
                           0,0,0,0,0,8,1,8,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0
                           0,0,0,0,0,8,1,8,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0
                           0,0,0,0,0,0 1,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,3,3,3,0
                           0,0,0,0,0,8,1,8,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,3,0
                           0,0,0,0,0,8,1,8,0,0,0,0,0,8,8,0,8,8,8,8,8,3,0,0,0,0,3,0
                           0,0,0,0,0,8,1,0,0,0,0,0,0,1,2,3,4,5,6,7,8,3,8,0,3,3,3,0
                           0,0,0,0,0,8,1,8,0,0,0,0,0,8,8,8,8,8,0,8,8,3,8,0,3,0,0,0
                           0,8,8,0,8,8,1,8,0,0,0,0,0,0,0,0,0,0,0,0,8,3,8,8,3,8,8,0
                           8,1,1,1,1,1,1,8,0,0,0,0,0,0,0,0,0,0,0,0,8,3,3,3,3,16,17,8
                           8,1,8,8,8,8,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,8,8,18,8
                           8,1,8,8,8,8,8,8,8,8,8,8,0,8,8,0,8,8,8,8,8,8,8,8,8,8,19,8
                           8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8
                           0,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,0
                           0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                           0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0});
*/

}
int main()
{
        srand (time(nullptr));

        vector <unsigned> V;
        // Initialise le système
        MinGL window("PacMan", nsGraphics::Vec2D(1400, 800), nsGraphics::Vec2D(128, 128), nsGraphics::KBlack);
        window.initGlut();
        window.initGraphic();

        // Variable qui tient le temps de frame
        chrono::microseconds frameTime = chrono::microseconds::zero();

        // On fait tourner la boucle tant que la fenêtre est ouverte
        while (window.isOpen())
        {
            // Récupère l'heure actuelle
            chrono::time_point<chrono::steady_clock> start = chrono::steady_clock::now();

            // On efface la fenêtre
            window.clearScreen();

            // On dessine les formes géométriques
            dessiner(window);

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
