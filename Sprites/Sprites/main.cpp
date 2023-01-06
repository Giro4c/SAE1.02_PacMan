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

typedef pair <unsigned, unsigned> CPosition;

struct GhostSprite
{
    unsigned XCenter = 550;
    unsigned YCenter = 250;
    nsGraphics::Vec2D CenterPos = nsGraphics::Vec2D(XCenter,YCenter);
    unsigned largeur_Rayon = 12;
    unsigned longueur = 25;
    // Penser à mettre variable couleur
    nsShape::Circle head = {nsGraphics::Vec2D(CenterPos), largeur_Rayon, nsGraphics::KRed};
    nsShape::Rectangle body = {nsGraphics::Vec2D(XCenter - largeur_Rayon, YCenter), nsGraphics::Vec2D(XCenter + largeur_Rayon, YCenter + longueur - largeur_Rayon), nsGraphics::KRed};
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

// struct BP {
//     CPosition CenterPos;
//     unsigned rayon = 5;
// };

//void LoadParams (CMyParam & Param)
//{
//    ifstream ifs("config.yaml");
//    pair350 <unsigned, unsigned> line;
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


//void InitMap (map <pair <unsigned, unsigned>, bool> & bpMap)
//{
//    // Création de paires
//    /**
////     * @brief CPosition : a pair gathering the coordinates in the grid
////     */
////    CPosition bp1 {50,50};
////    CPosition bp2 {100,50};
////    CPosition bp3 {150,50};
////    CPosition bp4 {200,50};
////    CPosition bp5 {250,50};
////    CPosition bp6 {300,50};
////    CPosition bp7 {350,50};
////    CPosition bp8 {400,50};
////    CPosition bp9{450,50};
////    CPosition bp10 {500,50};
////  bp ligne 1
//    pair <unsigned, unsigned> bp1 (75,75);
//    pair <unsigned, unsigned> bp2 (125,75);
//    pair <unsigned, unsigned> bp3 (175,75);
//    pair <unsigned, unsigned> bp4 (225,75);
//    pair <unsigned, unsigned> bp5 (325,75);
//    pair <unsigned, unsigned> bp6 (375,75);
//    pair <unsigned, unsigned> bp7 (425,75);
//    pair <unsigned, unsigned> bp8 (425,75);
//    pair <unsigned, unsigned> bp9 (475,75);
//    pair <unsigned, unsigned> bp10 (525,75);
//    pair <unsigned, unsigned> bp11 (575,75);
//    pair <unsigned, unsigned> bp12 (625,75);
//    pair <unsigned, unsigned> bp13 (675,75);
//    pair <unsigned, unsigned> bp14 (775,75);
//    pair <unsigned, unsigned> bp15 (825,75);
//    pair <unsigned, unsigned> bp16 (875,75);
//    pair <unsigned, unsigned> bp17 (925,75);
//    pair <unsigned, unsigned> bp18 (975,75);
//    pair <unsigned, unsigned> bp19 (1025,75);
////  bp ligne 2
//    pair <unsigned, unsigned> bp20 (75,125);
//    pair <unsigned, unsigned> bp21 (225,125);
//    pair <unsigned, unsigned> bp22 (325,125);
//    pair <unsigned, unsigned> bp23 (775,125);
//    pair <unsigned, unsigned> bp24 (875,125);
//    pair <unsigned, unsigned> bp25 (1025,125);
////  bp ligne 3
//    pair <unsigned, unsigned> bp7 (425,175);
//    pair <unsigned, unsigned> bp8 (425,175);
//    pair <unsigned, unsigned> bp9 (4125,175);
//    pair <unsigned, unsigned> bp10 (525,175);
//    pair <unsigned, unsigned> bp11 (5125,175);
//    pair <unsigned, unsigned> bp12 (625,175);
//    pair <unsigned, unsigned> bp13 (6125,175);
//    pair <unsigned, unsigned> bp14 (725,175);
//    pair <unsigned, unsigned> bp15 (825,175);
//    pair <unsigned, unsigned> bp16 (8125,175);
//    pair <unsigned, unsigned> bp17 (925,175);
//    pair <unsigned, unsigned> bp18 (9125,175);
//    pair <unsigned, unsigned> bp19 (1025,175);

//    // Initialisation de la map
//    bpMap[bp1] = false;
//    bpMap[bp2] = false;
//    bpMap[bp3] = false;
//    bpMap[bp4] = false;
//    bpMap[bp5] = false;
//    bpMap[bp6] = false;
//    bpMap[bp7] = false;
//    bpMap[bp8] = false;
//    bpMap[bp9] = false;
//    bpMap[bp10] = false;
//    bpMap[bp11] = false;
//    bpMap[bp12] = false;
//    bpMap[bp13] = false;
//    bpMap[bp14] = false;
//    bpMap[bp15] = false;

//}

//template <class T, class U>
//void ShowMap (map <pair <unsigned, unsigned>, bool>bpMap)
//{
//    InitMap(bpMap);
//    for (const pair <T,U> & val : bpMap)
//    {
//        cout << "Clé : " << val.first << " "
//            << "Valeur : " << val.second << endl;
//    }
//    cout << endl;
//}

////void dessinerBp (MinGL & window, const map<CPosition, bool> & MapBp, const unsigned & sizeBp)
////{
////    unsigned nbLine(26);
////    for (const pair <CPosition,bool> & Bp : MapBp)
////    {
////        unsigned posY = Bp.first.second;
////        if (Bp.second == false)
////        {
////            window << nsShape::Circle(nsGraphics::Vec2D(Bp.first.first, posY), sizeBp, nsGraphics::KWhite);
////            for (unsigned i (0); i < nbLine; ++i)
////            {
////                posY = posY + 36;
////                window << nsShape::Circle(nsGraphics::Vec2D(Bp.first.first, posY), sizeBp, nsGraphics::KWhite);
////            }
////        }
////    }
////}

//void dessinerBp (MinGL & window, const map<CPosition, bool> & MapBp, const unsigned & sizeBp)
//{
//    for (const pair <CPosition,bool> & Bp : MapBp)
//    {
//        unsigned posX = Bp.first.first;
//        unsigned posY = Bp.first.second;
//        if (Bp.second == false)
//        {
//            window << nsShape::Circle(nsGraphics::Vec2D(posX, posY), sizeBp, nsGraphics::KWhite);
//            window << nsShape::Circle(nsGraphics::Vec2D(posX, posY + 50), sizeBp, nsGraphics::KWhite);
//            window << nsShape::Circle(nsGraphics::Vec2D(posX, posY + 110), sizeBp, nsGraphics::KWhite);
//            window << nsShape::Circle(nsGraphics::Vec2D(posX, posY + 160), sizeBp, nsGraphics::KWhite);
//            window << nsShape::Circle(nsGraphics::Vec2D(posX, posY + 200), sizeBp, nsGraphics::KWhite);
//            window << nsShape::Circle(nsGraphics::Vec2D(posX, posY + 250), sizeBp, nsGraphics::KWhite);
//            window << nsShape::Circle(nsGraphics::Vec2D(posX, posY + 290), sizeBp, nsGraphics::KWhite);
//            window << nsShape::Circle(nsGraphics::Vec2D(posX, posY + 330), sizeBp, nsGraphics::KWhite);
//            window << nsShape::Circle(nsGraphics::Vec2D(posX, posY + 370), sizeBp, nsGraphics::KWhite);
//            window << nsShape::Circle(nsGraphics::Vec2D(posX, posY + 410), sizeBp, nsGraphics::KWhite);
//            window << nsShape::Circle(nsGraphics::Vec2D(posX, posY + 450), sizeBp, nsGraphics::KWhite);
//            window << nsShape::Circle(nsGraphics::Vec2D(posX, posY + 490), sizeBp, nsGraphics::KWhite);
//            window << nsShape::Circle(nsGraphics::Vec2D(posX, posY + 535), sizeBp, nsGraphics::KWhite);
//            window << nsShape::Circle(nsGraphics::Vec2D(posX, posY + 575), sizeBp, nsGraphics::KWhite);
//            window << nsShape::Circle(nsGraphics::Vec2D(posX, posY + 620), sizeBp, nsGraphics::KWhite);
//            window << nsShape::Circle(nsGraphics::Vec2D(posX, posY + 660), sizeBp, nsGraphics::KWhite);
//            window << nsShape::Circle(nsGraphics::Vec2D(posX, posY + 705), sizeBp, nsGraphics::KWhite);
//            window << nsShape::Circle(nsGraphics::Vec2D(posX, posY + 750), sizeBp, nsGraphics::KWhite);
//            window << nsShape::Circle(nsGraphics::Vec2D(posX, posY + 800), sizeBp, nsGraphics::KWhite);
//        }
//    }
//}

void initMap (vector<string> & vectMap)
{
    vectMap = {
    "xxxxxxxxxxxxxxxxxxxxxx",
    "xo...x.........ox....x",
    "x.xx.x.xxxxxxxx.x.xx.x",
    "x.x................x.x",
    "x.x.xx.xxxnnxxx.xx.x.x",
    "..x....xnnnnnnx....x.o",
    "x...xx.xxxxxxxx.xx...x",
    "x.x................x.x",
    "x.x.xx.xxxxxxxx.xx.x.x",
    "x.x................x.x",
    "x.xx.x.xxxxxxxx.x.xx.x",
    "x...ox..........x...oxx",
    "xxxxxxxxxxxxxxxxxxxxxx"};
}

void afficheMap(MinGL &window, vector<string> &vectMap) {
    for (size_t i(0); i < vectMap.size(); ++i) {
        for (size_t j(0); j < vectMap[0].size(); ++j) {
            switch (vectMap[i][j]) {
            case 'x':
                window << nsShape::Rectangle(nsGraphics::Vec2D(j * 50,i * 50), nsGraphics::Vec2D(j * 50 + 50, i * 50+50), nsGraphics::KBlue);
                break;
            case '.':
                window << nsShape::Circle(nsGraphics::Vec2D(j * 50 + 25, i * 50+25), 3, nsGraphics::KWhite);
                break;
            case 'o':
                window << nsShape::Circle(nsGraphics::Vec2D(j * 50 + 25, i * 50 + 25), 8, nsGraphics::KWhite);
                break;
            case 'n':
                window << nsShape::Rectangle(nsGraphics::Vec2D(j * 50,i * 50), nsGraphics::Vec2D(j * 50 + 50, i * 50 + 50), nsGraphics::KBlack);
            }
        }
    }
}

void dessiner(MinGL & window)
{
    // PacMan Right
    window << nsShape::Circle(nsGraphics::Vec2D(75, 75), 15, nsGraphics::KYellow);
    window << nsShape::Triangle(nsGraphics::Vec2D(75, 75), nsGraphics::Vec2D(100, 50), nsGraphics::Vec2D(100, 91), nsGraphics::KBlack);
//    // PacMan Left
//    window << nsShape::Circle(nsGraphics::Vec2D(100, 50), 25, nsGraphics::KYellow);
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
//    // Fantôme Bleu>
//    window << nsShape::Circle(nsGraphics::Vec2D(350, 50), 25, nsGraphics::KBlue);
//    window << nsShape::Rectangle(nsGraphics::Vec2D(375, 50), nsGraphics::Vec2D(325, 90), nsGraphics::KBlue);
//    window << nsShape::Triangle(nsGraphics::Vec2D(335, 85), nsGraphics::Vec2D(330, 90), nsGraphics::Vec2D(340, 90), nsGraphics::KBlack);
//    window << nsShape::Triangle(nsGraphics::Vec2D(350, 85), nsGraphics::Vec2D(345, 90), nsGraphics::Vec2D(355, 90), nsGraphics::KBlack);
//    window << nsShape::Triangle(nsGraphics::Vec2D(365, 85), nsGraphics::Vec2D(360, 90), nsGraphics::Vec2D(370, 90), nsGraphics::KBlack);

//    // Fantôme Rouge
//    window << nsShape>::Circle(nsGraphics::Vec2D(350, 50), 25, nsGraphics::KBlue);
//    window << nsShape::Rectangle(nsGraphics::Vec2D(375, 50), nsGraphics::Vec2D(325, 90), nsGraphics::KRed);
//    window << nsShape::Triangle(nsGraphics::Vec2D(335, 85), nsGraphi//pair <unsigned, unsigned> bp2 (100,50);
//    window << nsShape::Triangle(nsGraphics::Vec2D(350, 85), nsGraphics::Vec2D(345, 90), nsGraphics::Vec2D(355, 90), nsGraphics::KBlack);
//    window << nsShape::Triangle(nsGraphics::Vec2D(365, 85), nsGraphics::Vec2D(360, 90), nsGraphics::Vec2D(370, 90), nsGraphics::KBlack);
//    // Fantôme Vert
//    window << nsShape::Circle(nsGraphics::Vec2D(350, 50), 25, nsGraphics::KBlue);
//    window << nsShape::Rectangle(nsGraphics::Vec2D(375, 50), nsGraphics::Vec2D(325, 90), nsGraphics::KGreen);
//    window << nsShape::Triangle(nsGraphics::Vec2D(335, 85), nsGraph//pair <unsigned, unsigned> bp2 (100,50);
//    window << nsShape::Triangle(nsGraphics::Vec2D(350, 85), nsGraphics::Vec2D(345, 90), nsGraphics::Vec2D(355, 90), nsGraphics::KBlack);
//    window << nsShape::Triangle(nsGraphics::Vec2D(365, 85), nsGraphics::Vec2D(360, 90), nsGraphics::Vec2D(370, 90), nsGraphics::KBlack);

}

int main()
{
//  PacMan pacLeft
    GhostSprite Fantome;
    GhostSprite Fantome2;

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

        // On dessine les formes géométriques
        // Instancie le sprite
        // Importation de la map
//        nsGui::Sprite doggo("../Sprites/map.si2", nsGraphics::Vec2D(0, 0));
//        // Dessin de la map
//        window << doggo;
//      window << Fantome.head;
//      window << Fantome.body;

        Fantome2.YCenter = Fantome.YCenter + 1;
        Fantome2.XCenter = Fantome.XCenter + 1;

        Fantome2.body = Fantome2.body;

//      window << pacLeft.cercle;
//      window << pacLeft.triangle;
        // dessin de la fenêtre
        dessiner(window);
        afficheMap(window, vectMap);
        cout << Fantome.YCenter;
        window << Fantome2.head;
        window << Fantome2.body;
//      dessinerBp(window, bpMap, 5);

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
