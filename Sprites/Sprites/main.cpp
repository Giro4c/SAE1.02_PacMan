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

//using namespace std;
//using namespace nsShape;
//using namespace nsGraphics;

using namespace std;

typedef pair <unsigned, unsigned> CPosition;

unsigned largeur_Rayon = 12;
unsigned longueur = 25;
struct GhostSprite
{
    unsigned XCenter = 550;
    unsigned YCenter = 275;
    nsGraphics::Vec2D CenterPos = nsGraphics::Vec2D(XCenter,YCenter);
    // Forme du fantôme
    nsShape::Circle head = {nsGraphics::Vec2D(CenterPos), largeur_Rayon, nsGraphics::KMagenta};
    nsShape::Rectangle body = {nsGraphics::Vec2D(XCenter - largeur_Rayon, YCenter), nsGraphics::Vec2D(XCenter + largeur_Rayon, YCenter + longueur - largeur_Rayon), nsGraphics::KMagenta};
//    nsShape::Triangle bottom1 = {nsGraphics::Vec2D(XCenter - longueur,YCenter - largeur_Rayon - longueur), nsGraphics::Vec2D(330, largeur_Rayon + longueur), nsGraphics::Vec2D(longueur - largeur_Rayon, largeur_Rayon + longueur), nsGraphics::KBlack};
//    nsShape::Triangle bottom2 = {nsGraphics::Vec2D(350, YCenter - largeur_Rayon - longueur), nsGraphics::Vec2D(345, largeur_Rayon + longueur), nsGraphics::Vec2D(355,largeur_Rayon + longueur), nsGraphics::KBlack};
//    nsShape::Triangle bottom3 = {nsGraphics::Vec2D(365, YCenter - largeur_Rayon - longueur), nsGraphics::Vec2D(360, largeur_Rayon + longueur), nsGraphics::Vec2D(370, largeur_Rayon + longueur), nsGraphics::KBlack};
};

//struct GhostSprite
//{
//    unsigned XCenter;
//    unsigned YCenter;
//    nsGraphics::RGBAcolor couleur;// variable couleur
//    // Forme du fantôme
//    nsShape::Circle head;
//    nsShape::Rectangle body;
////    vector<nsShape::Triangle>bottom;
//};
//GhostSprite ghost1 = {
//    550,
//    250,
//    nsGraphics::KCyan,
//    {nsGraphics::Vec2D(XCenter, YCenter), largeur_Rayon, nsGraphics::couleur},
//    {nsGraphics::Vec2D(XCenter - largeur_Rayon, YCenter), nsGraphics::Vec2D(XCenter + largeur_Rayon, YCenter + longueur - largeur_Rayon), nsGraphics::couleur},

//};

//GhostSprite ghost2 = {
//    600,
//    250,
//    nsGraphics::KMagenta,
//    {nsGraphics::Vec2D(XCenter, YCenter), largeur_Rayon, nsGraphics::couleur},
//    {nsGraphics::Vec2D(XCenter - largeur_Rayon, YCenter), nsGraphics::Vec2D(XCenter + largeur_Rayon, YCenter + longueur - largeur_Rayon), nsGraphics::couleur},

//};

//GhostSprite ghost3 = {
//    650,
//    250,
//    nsGraphics::KGreen,
//    {nsGraphics::Vec2D(XCenter, YCenter), largeur_Rayon, nsGraphics::couleur},
//    {nsGraphics::Vec2D(XCenter - largeur_Rayon, YCenter), nsGraphics::Vec2D(XCenter + largeur_Rayon, YCenter + longueur - largeur_Rayon), nsGraphics::couleur},

//};

//GhostSprite ghost4 = {
//    700,
//    250,
//    nsGraphics::KSilver,
//    {nsGraphics::Vec2D(XCenter, YCenter), largeur_Rayon, nsGraphics::couleur},
//    {nsGraphics::Vec2D(XCenter - largeur_Rayon, YCenter), nsGraphics::Vec2D(XCenter + largeur_Rayon, YCenter + longueur - largeur_Rayon), nsGraphics::couleur},

//};

//unsigned diametre = 50;
//unsigned rayon = 25;
//struct PacMan {
//    nsShape::Circle cercle = {nsGraphics::Vec2D(diametre, diametre), rayon, nsGraphics::KYellow};
//    nsShape::Triangle triangle = {nsGraphics::Vec2D(diametre, diametre), nsGraphics::Vec2D(diametre + rayon, rayon), nsGraphics::Vec2D(diametre + rayon, diametre + rayon - 10), nsGraphics::KBlack};
//};


//void InitMap (map <pair <unsigned, unsigned>, bool> & bpMap)
//{
//    // Création de paires

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
//    pair <unsigned, unsigned> bp26 (75,175);
//    pair <unsigned, unsigned> bp27 (175,175);
//    pair <unsigned, unsigned> bp28 (225,175);
//    pair <unsigned, unsigned> bp29 (275,175);
//    pair <unsigned, unsigned> bp30 (325,175);
//    pair <unsigned, unsigned> bp31 (375,175);
//    pair <unsigned, unsigned> bp32 (425,175);
//    pair <unsigned, unsigned> bp33 (475,175);
//    pair <unsigned, unsigned> bp34 (525,175);
//    pair <unsigned, unsigned> bp35 (575,175);
//    pair <unsigned, unsigned> bp36 (625,175);
//    pair <unsigned, unsigned> bp37 (675,175);
//    pair <unsigned, unsigned> bp38 (725,175);
//    pair <unsigned, unsigned> bp39 (775,175);
//    pair <unsigned, unsigned> bp40 (825,175);
//    pair <unsigned, unsigned> bp41 (875,175);
//    pair <unsigned, unsigned> bp42 (925,175);
//    pair <unsigned, unsigned> bp43 (1025,175);
////  bp ligne 4
//    pair <unsigned, unsigned> bp44 (75,225);
//    pair <unsigned, unsigned> bp45 (175,225);
//    pair <unsigned, unsigned> bp46 (325,225);
//    pair <unsigned, unsigned> bp47 (775,225);
//    pair <unsigned, unsigned> bp48 (925,225);
//    pair <unsigned, unsigned> bp49 (1025,225);
////  bp ligne 5
//    pair <unsigned, unsigned> bp50 (25,275);
//    pair <unsigned, unsigned> bp51 (75,275);
//    pair <unsigned, unsigned> bp52 (175,275);
//    pair <unsigned, unsigned> bp53 (225,275);
//    pair <unsigned, unsigned> bp54 (275,275);
//    pair <unsigned, unsigned> bp55 (325,275);
//    pair <unsigned, unsigned> bp56 (775,275);
//    pair <unsigned, unsigned> bp57 (825,275);
//    pair <unsigned, unsigned> bp58 (875,275);
//    pair <unsigned, unsigned> bp59 (925,275);
//    pair <unsigned, unsigned> bp60 (1025,275);
//    pair <unsigned, unsigned> bp61 (1075,275);
////  bp ligne 6
//    pair <unsigned, unsigned> bp62 (75,325);
//    pair <unsigned, unsigned> bp63 (125,325);
//    pair <unsigned, unsigned> bp64 (175,325);
//    pair <unsigned, unsigned> bp65 (325,325);
//    pair <unsigned, unsigned> bp66 (775,325);
//    pair <unsigned, unsigned> bp67 (925,325);
//    pair <unsigned, unsigned> bp68 (975,325);
//    pair <unsigned, unsigned> bp69 (1025,325);
////  bp ligne 7
//    pair <unsigned, unsigned> bp70 (75,375);
//    pair <unsigned, unsigned> bp71 (175,375);
//    pair <unsigned, unsigned> bp72 (225,375);
//    pair <unsigned, unsigned> bp73 (275,375);
//    pair <unsigned, unsigned> bp74 (325,375);
//    pair <unsigned, unsigned> bp75 (375,375);
//    pair <unsigned, unsigned> bp76 (425,375);
//    pair <unsigned, unsigned> bp77 (475,375);
//    pair <unsigned, unsigned> bp78 (525,375);
//    pair <unsigned, unsigned> bp79 (575,375);
//    pair <unsigned, unsigned> bp80 (625,375);
//    pair <unsigned, unsigned> bp81 (675,375);
//    pair <unsigned, unsigned> bp82 (725,375);
//    pair <unsigned, unsigned> bp83 (775,375);
//    pair <unsigned, unsigned> bp84 (825,375);
//    pair <unsigned, unsigned> bp85 (875,375);
//    pair <unsigned, unsigned> bp86 (925,375);
//    pair <unsigned, unsigned> bp87 (1025,375);
////  bp ligne 8
//    pair <unsigned, unsigned> b88 (75,425);
//    pair <unsigned, unsigned> bp89 (175,425);
//    pair <unsigned, unsigned> bp90 (325,425);
//    pair <unsigned, unsigned> bp91 (775,425);
//    pair <unsigned, unsigned> bp92 (925,425);
//    pair <unsigned, unsigned> bp93 (1025,425);
////  bp ligne 9
//    pair <unsigned, unsigned> bp94 (75,475);
//    pair <unsigned, unsigned> bp95 (175,475);
//    pair <unsigned, unsigned> bp96 (225,475);
//    pair <unsigned, unsigned> bp97 (275,475);
//    pair <unsigned, unsigned> bp98 (325,475);
//    pair <unsigned, unsigned> bp99 (375,475);
//    pair <unsigned, unsigned> bp100 (425,475);
//    pair <unsigned, unsigned> bp101 (475,475);
//    pair <unsigned, unsigned> bp102 (525,475);
//    pair <unsigned, unsigned> bp103 (575,475);
//    pair <unsigned, unsigned> bp104 (625,475);
//    pair <unsigned, unsigned> bp105 (675,475);
//    pair <unsigned, unsigned> bp106 (725,475);
//    pair <unsigned, unsigned> bp107 (775,475);
//    pair <unsigned, unsigned> bp108 (825,475);
//    pair <unsigned, unsigned> bp109 (875,475);
//    pair <unsigned, unsigned> bp110 (925,475);
//    pair <unsigned, unsigned> bp111 (1025,475);
////  bp ligne 10
//    pair <unsigned, unsigned> bp112 (75,525);
//    pair <unsigned, unsigned> bp113 (225,525);
//    pair <unsigned, unsigned> bp114 (325,525);
//    pair <unsigned, unsigned> bp115 (775,525);
//    pair <unsigned, unsigned> bp116 (875,525);
//    pair <unsigned, unsigned> bp117 (1025,525);
////  bp ligne 11
//    pair <unsigned, unsigned> bp118 (75,575);
//    pair <unsigned, unsigned> bp119 (125,575);
//    pair <unsigned, unsigned> bp120 (175,575);
//    pair <unsigned, unsigned> bp121 (225,575);
//    pair <unsigned, unsigned> bp122 (325,575);
//    pair <unsigned, unsigned> bp123 (375,575);
//    pair <unsigned, unsigned> bp124 (425,575);
//    pair <unsigned, unsigned> bp125 (425,575);
//    pair <unsigned, unsigned> bp126 (475,575);
//    pair <unsigned, unsigned> bp127 (525,575);
//    pair <unsigned, unsigned> bp128 (575,575);
//    pair <unsigned, unsigned> bp129 (625,575);
//    pair <unsigned, unsigned> bp130 (675,575);
//    pair <unsigned, unsigned> bp131 (775,575);
//    pair <unsigned, unsigned> bp132 (825,575);
//    pair <unsigned, unsigned> bp133 (875,575);
//    pair <unsigned, unsigned> bp134 (925,575);
//    pair <unsigned, unsigned> bp135 (975,575);
//    pair <unsigned, unsigned> bp136 (1025,575);

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
//    bpMap[bp16] = false;
//    bpMap[bp17] = false;
//    bpMap[bp18] = false;
//    bpMap[bp19] = false;
//    bpMap[bp20] = false;
//    bpMap[bp21] = false;
//    bpMap[bp22] = false;
//    bpMap[bp23] = false;
//    bpMap[bp24] = false;
//    bpMap[bp25] = false;
//    bpMap[bp26] = false;
//    bpMap[bp27] = false;
//    bpMap[bp28] = false;
//    bpMap[bp29] = false;
//    bpMap[bp30] = false;
//    bpMap[bp31] = false;
//    bpMap[bp32] = false;
//    bpMap[bp33] = false;
//    bpMap[bp34] = false;
//    bpMap[bp35] = false;
//    bpMap[bp36] = false;
//    bpMap[bp37] = false;
//    bpMap[bp38] = false;
//    bpMap[bp39] = false;
//    bpMap[bp40] = false;
//    bpMap[bp41] = false;
//    bpMap[bp42] = false;
//    bpMap[bp43] = false;
//    bpMap[bp44] = false;
//    bpMap[bp45] = false;
//    bpMap[bp46] = false;
//    bpMap[bp47] = false;
//    bpMap[bp48] = false;
//    bpMap[bp49] = false;
//    bpMap[bp50] = false;
//    bpMap[bp51] = false;
//    bpMap[bp52] = false;
//    bpMap[bp53] = false;
//    bpMap[bp54] = false;
//    bpMap[bp54] = false;
//    bpMap[bp55] = false;
//    bpMap[bp56] = false;
//    bpMap[bp57] = false;
//    bpMap[bp58] = false;
//    bpMap[bp59] = false;
//    bpMap[bp60] = false;
//    bpMap[bp61] = false;
//    bpMap[bp62] = false;
//    bpMap[bp63] = false;
//    bpMap[bp64] = false;
//    bpMap[bp65] = false;
//    bpMap[bp66] = false;
//    bpMap[bp67] = false;
//    bpMap[bp68] = false;
//    bpMap[bp68] = false;
//    bpMap[bp70] = false;
//    bpMap[bp71] = false;
//    bpMap[bp72] = false;
//    bpMap[bp73] = false;
//    bpMap[bp74] = false;
//    bpMap[bp75] = false;
//    bpMap[bp76] = false;
//    bpMap[bp77] = false;
//    bpMap[bp78] = false;
//    bpMap[bp79] = false;
//    bpMap[bp80] = false;
//    bpMap[bp11] = false;
//    bpMap[bp82] = false;
//    bpMap[bp83] = false;
//    bpMap[bp84] = false;
//    bpMap[bp85] = false;
//    bpMap[bp86] = false;
//    bpMap[bp87] = false;
//    bpMap[bp88] = false;
//    bpMap[bp89] = false;
//    bpMap[bp90] = false;
//    bpMap[bp91] = false;
//    bpMap[bp92] = false;
//    bpMap[bp93] = false;
//    bpMap[bp94] = false;
//    bpMap[bp95] = false;
//    bpMap[bp96] = false;
//    bpMap[bp97] = false;
//    bpMap[bp98] = false;
//    bpMap[bp99] = false;
//    bpMap[bp100] = false;
//    bpMap[bp101] = false;
//    bpMap[bp102] = false;
//    bpMap[bp103] = false;
//    bpMap[bp104] = false;
//    bpMap[bp105] = false;
//    bpMap[bp106] = false;
//    bpMap[bp107] = false;
//    bpMap[bp108] = false;
//    bpMap[bp109] = false;
//    bpMap[bp110] = false;
//    bpMap[bp111] = false;
//    bpMap[bp112] = false;
//    bpMap[bp113] = false;
//    bpMap[bp114] = false;
//    bpMap[bp115] = false;
//    bpMap[bp116] = false;
//    bpMap[bp117] = false;
//    bpMap[bp118] = false;
//    bpMap[bp119] = false;
//    bpMap[bp120] = false;
//    bpMap[bp121] = false;
//    bpMap[bp122] = false;
//    bpMap[bp123] = false;
//    bpMap[bp124] = false;
//    bpMap[bp125] = false;
//    bpMap[bp126] = false;
//    bpMap[bp127] = false;
//    bpMap[bp128] = false;
//    bpMap[bp129] = false;
//    bpMap[bp130] = false;
//    bpMap[bp131] = false;
//    bpMap[bp132] = false;
//    bpMap[bp133] = false;
//    bpMap[bp134] = false;
//    bpMap[bp135] = false;
//    bpMap[bp136] = false;
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
//    // Fantôme
//    window << nsShape::Circle(nsGraphics::Vec2D(350, 50), 25, nsGraphics::KBlue);
//    window << nsShape::Rectangle(nsGraphics::Vec2D(375, 50), nsGraphics::Vec2D(325, 90), nsGraphics::KBlue);
//    window << nsShape::Triangle(nsGraphics::Vec2D(335, 85), nsGraphics::Vec2D(330, 90), nsGraphics::Vec2D(340, 90), nsGraphics::KBlack);
//    window << nsShape::Triangle(nsGraphics::Vec2D(350, 85), nsGraphics::Vec2D(345, 90), nsGraphics::Vec2D(355, 90), nsGraphics::KBlack);
//    window << nsShape::Triangle(nsGraphics::Vec2D(365, 85), nsGraphics::Vec2D(360, 90), nsGraphics::Vec2D(370, 90), nsGraphics::KBlack);

}

int main()
{
//  PacMan pacLeft
    GhostSprite Fantome;
    GhostSprite Fantome2;
    GhostSprite Fantome3;
    GhostSprite Fantome4;

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

        Fantome.XCenter = 550;
        Fantome.YCenter = 275;

        Fantome2.XCenter = Fantome.XCenter + 50;
        Fantome2.YCenter = Fantome.YCenter;

        Fantome3.XCenter = Fantome2.XCenter + 50;
        Fantome3.YCenter = Fantome2.YCenter;

        Fantome4.XCenter = Fantome3.XCenter + 50;
        Fantome4.YCenter = Fantome3.YCenter;

//        Fantome2.body = Fantome2.body;

//      window << pacLeft.cercle;
//      window << pacLeft.triangle;
        // dessin de la fenêtre
        dessiner(window); // on dessine un PacMan
        afficheMap(window, vectMap); //affiche la map
//        window << ghost1;
//        window << ghost2;
//        window << ghost3;
//        window << ghost4;
        window << Fantome.head;
        window << Fantome.body;

        window << Fantome2.head;
        window << Fantome2.body;

        window << Fantome3.head;
        window << Fantome3.body;

        window << Fantome4.head;
        window << Fantome4.body;

//        dessinerBp(window, bpMap, 5);

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
