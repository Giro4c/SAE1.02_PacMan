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

//using namespace std;
//using namespace nsShape;
//using namespace nsGraphics;

using namespace std;

struct GhostSprite
{
    unsigned XCenter = 100;
    unsigned YCenter = 100;
    nsGraphics::Vec2D CenterPos = nsGraphics::Vec2D(XCenter,YCenter);
    unsigned largeur_Rayon = 25;
    unsigned longueur = 65;
    // Penser à mettre variable couleur
    nsShape::Circle head = {nsGraphics::Vec2D(CenterPos), largeur_Rayon, nsGraphics::KBlue};
    nsShape::Rectangle body = {nsGraphics::Vec2D(XCenter - largeur_Rayon, YCenter), nsGraphics::Vec2D(XCenter + largeur_Rayon, YCenter + longueur - largeur_Rayon), nsGraphics::KBlue};
    nsShape::Triangle bottom1 = {nsGraphics::Vec2D(XCenter - longueur,YCenter - largeur_Rayon - longueur), nsGraphics::Vec2D(330, largeur_Rayon + longueur), nsGraphics::Vec2D(longueur - largeur_Rayon, largeur_Rayon + longueur), nsGraphics::KBlack};
    nsShape::Triangle bottom2 = {nsGraphics::Vec2D(350, YCenter - largeur_Rayon - longueur), nsGraphics::Vec2D(345, largeur_Rayon + longueur), nsGraphics::Vec2D(355,largeur_Rayon + longueur), nsGraphics::KBlack};
    nsShape::Triangle bottom3 = {nsGraphics::Vec2D(365, YCenter - largeur_Rayon - longueur), nsGraphics::Vec2D(360, largeur_Rayon + longueur), nsGraphics::Vec2D(370, largeur_Rayon + longueur), nsGraphics::KBlack};
};

//struct PacMan {
//    unsigned diametre = 50;
//    unsigned rayon = 25;
//    nsShape::Circle cercle = {nsGraphics::Vec2D(diametre, diametre), rayon, nsGraphics::KYellow};
//    nsShape::Triangle triangle = {nsGraphics::Vec2D(diametre, diametre), nsGraphics::Vec2D(diametre + rayon, rayon), nsGraphics::Vec2D(diametre + rayon, diametre + rayon - 10), nsGraphics::KBlack};
//};

//struct forMap {
//    unsigned posX --> Cposition.first;
//    unsigned posY --> Cposition.second;

//};
//pour l'appeler : //bpMap[(posX, posY)] = false;

//void LoadParams (CMyParam & Param)
//{
//    ifstream ifs("config.yaml");
//    pair <unsigned, unsigned> line;
//    while(true)
//    {
//        //cin >> str;
//        if (ifs.eof()) break;
//        getline(ifs,line);

//        // cout << str << '\n';

//        // extraire param et val
//        string param ;
//        string val;
//        size_t pos = line.find(":");
//        param = line.substr(0,pos - 1);
//        val = line.substr(pos + 1);
//        cout << param << " : " << val << endl;
//        // enregistrer dans la struct
//    }
//}

/**
 * @brief CPosition : a pair gathering the coordinates in the grid
 */
//pair <unsigned, unsigned> bp1 (50,50);
//pair <unsigned, unsigned> bp2 (100,50);
//pair <unsigned, unsigned> bp3 (150,50);
//pair <unsigned, unsigned> bp4 (200,50);
//pair <unsigned, unsigned> bp5 (250,50);
//pair <unsigned, unsigned> bp6 (300,50);
//pair <unsigned, unsigned> bp7 (350,50);
//pair <unsigned, unsigned> bp8 (400,50);
//pair <unsigned, unsigned> bp9 (450,50);
//pair <unsigned, unsigned> bp10 (500,50);
////typedef std::pair <unsigned, unsigned> CPosition;
////CPosition stockage = {50, 50};
//map<pair<unsigned, unsigned>, bool> bpMap;
//bpMap[bp1] = false;
//bpMap[bp2] = false;
//bpMap[bp3] = false;
//bpMap[bp4] = false;
//bpMap[bp5] = false;
//bpMap[bp6] = false;
//bpMap[bp7] = false;
//bpMap[bp8] = false;
//bpMap[bp9] = false;
//bpMap[bp10] = false;

 void dessiner(MinGL & window)
{
    // PacMan Right
    window << nsShape::Circle(nsGraphics::Vec2D(50, 50), 25, nsGraphics::KYellow);
    window << nsShape::Triangle(nsGraphics::Vec2D(50, 50), nsGraphics::Vec2D(75, 25), nsGraphics::Vec2D(75, 60), nsGraphics::KBlack);
    // PacMan Left
    window << nsShape::Circle(nsGraphics::Vec2D(100, 50), 25, nsGraphics::KYellow);
    window << nsShape::Triangle(nsGraphics::Vec2D(100, 50), nsGraphics::Vec2D(75, 25), nsGraphics::Vec2D(75, 60), nsGraphics::KBlack);
    // PacMan Up
    window << nsShape::Circle(nsGraphics::Vec2D(150, 50), 25, nsGraphics::KYellow);
    window << nsShape::Triangle(nsGraphics::Vec2D(150, 50), nsGraphics::Vec2D(135, 25), nsGraphics::Vec2D(165, 25), nsGraphics::KBlack);
    // PacMan Down
    window << nsShape::Circle(nsGraphics::Vec2D(200, 50), 25, nsGraphics::KYellow);
    window << nsShape::Triangle(nsGraphics::Vec2D(200, 50), nsGraphics::Vec2D(185, 75), nsGraphics::Vec2D(215, 75), nsGraphics::KBlack);
    // PacMan Rond
    window << nsShape::Circle(nsGraphics::Vec2D(450, 50), 25, nsGraphics::KYellow);
    // Boule point petit
    window << nsShape::Circle(nsGraphics::Vec2D(250, 50), 5, nsGraphics::KWhite);
    // Boule point grand
    window << nsShape::Circle(nsGraphics::Vec2D(300, 50), 10, nsGraphics::KWhite);
    // Fantôme Bleu
    window << nsShape::Circle(nsGraphics::Vec2D(350, 50), 25, nsGraphics::KBlue);
    window << nsShape::Rectangle(nsGraphics::Vec2D(375, 50), nsGraphics::Vec2D(325, 90), nsGraphics::KBlue);
    window << nsShape::Triangle(nsGraphics::Vec2D(335, 85), nsGraphics::Vec2D(330, 90), nsGraphics::Vec2D(340, 90), nsGraphics::KBlack);
    window << nsShape::Triangle(nsGraphics::Vec2D(350, 85), nsGraphics::Vec2D(345, 90), nsGraphics::Vec2D(355, 90), nsGraphics::KBlack);
    window << nsShape::Triangle(nsGraphics::Vec2D(365, 85), nsGraphics::Vec2D(360, 90), nsGraphics::Vec2D(370, 90), nsGraphics::KBlack);

//    // Fantôme Rouge
//    window << nsShape::Circle(nsGraphics::Vec2D(350, 50), 25, nsGraphics::KBlue);
//    window << nsShape::Rectangle(nsGraphics::Vec2D(375, 50), nsGraphics::Vec2D(325, 90), nsGraphics::KRed);
//    window << nsShape::Triangle(nsGraphics::Vec2D(335, 85), nsGraphics::Vec2D(330, 90), nsGraphics::Vec2D(340, 90), nsGraphics::KBlack);
//    window << nsShape::Triangle(nsGraphics::Vec2D(350, 85), nsGraphics::Vec2D(345, 90), nsGraphics::Vec2D(355, 90), nsGraphics::KBlack);
//    window << nsShape::Triangle(nsGraphics::Vec2D(365, 85), nsGraphics::Vec2D(360, 90), nsGraphics::Vec2D(370, 90), nsGraphics::KBlack);
//    // Fantôme Vert
//    window << nsShape::Circle(nsGraphics::Vec2D(350, 50), 25, nsGraphics::KBlue);
//    window << nsShape::Rectangle(nsGraphics::Vec2D(375, 50), nsGraphics::Vec2D(325, 90), nsGraphics::KGreen);
//    window << nsShape::Triangle(nsGraphics::Vec2D(335, 85), nsGraphics::Vec2D(330, 90), nsGraphics::Vec2D(340, 90), nsGraphics::KBlack);
//    window << nsShape::Triangle(nsGraphics::Vec2D(350, 85), nsGraphics::Vec2D(345, 90), nsGraphics::Vec2D(355, 90), nsGraphics::KBlack);
//    window << nsShape::Triangle(nsGraphics::Vec2D(365, 85), nsGraphics::Vec2D(360, 90), nsGraphics::Vec2D(370, 90), nsGraphics::KBlack);


}

int main()
{
//    PacMan pacLeft;
    GhostSprite Fantome;
    GhostSprite Fantome2;

    srand (time(nullptr));
        vector <unsigned> V;
        // Initialise le système
        MinGL window("PacMan", nsGraphics::Vec2D(800, 1010), nsGraphics::Vec2D(128, 128), nsGraphics::KBlack);
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
            // Instancie le sprite
            nsGui::Sprite doggo("../Sprites/map.si2", nsGraphics::Vec2D(0, 0));
            window << doggo;
//            window << Fantome.head;
//            window << Fantome.body;

            Fantome2.YCenter = Fantome.YCenter + 1;
            Fantome2.XCenter = Fantome.XCenter + 1;

            Fantome2.body = Fantome2.body;


            cout << Fantome.YCenter;
            window << Fantome2.head;
            window << Fantome2.body;
//            window << pacLeft.cercle;
//            window << pacLeft.triangle;

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

/*
python3 img2si.py map.png map.si2
Source image: .png
Output image: .si2
Image size is 224x282
*/
