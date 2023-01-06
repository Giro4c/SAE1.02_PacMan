#include <iostream>
#include <fstream>
#include <thread>
#include <vector>

#include "MinGL2/include/mingl/mingl.h"
#include "MinGL2/include/mingl/gui/sprite.h"
#include "MinGL2/include/mingl/graphics/vec2d.h"
#include "MinGL2/include/mingl/shape/rectangle.h"

#include "move.h"
#include "yaml.h"

using namespace std;
using namespace nsGraphics;
using namespace nsGui;
using namespace chrono;

/*
void addScore(string & life, string &nameStr){
    fstream ofs;
    ofs.open("score.txt");
    if(ofs.is_open()){
        ofs << nameStr << " " << life << endl;
    }
}
*/

void keyboard(MinGL &window, Sprite & pacman, vector<unsigned> vecKey)
{
    if (window.isPressed({char(vecKey[6]), false}) && pacman.getPosition().getX() > 50 ) {
        Vec2D position = pacman.getPosition();
        int pacX = position.getX();
        int pacY = position.getY();
        Vec2D positionF (pacX-5, pacY);
        pacman.setPosition(positionF);
    }
    if (window.isPressed({char(vecKey[7]), false}) && pacman.getPosition().getX() < (600-64+50)) {
        Vec2D position = pacman.getPosition();
        int pacX = position.getX();
        int pacY = position.getY();
        Vec2D positionF (pacX+5, pacY);
        pacman.setPosition(positionF);
    }
}

void movePac(Sprite &position, const int &x, const int &y) {
    position.setPosition(Vec2D(position.getPosition().getX() + x, position.getPosition().getY() + y));
}



Pacman::Pacman(int X, int Y) : Personnage(X, Y)
{
    X_ = X;
    Y_ = Y;
    Miroir_ = false;
}

bool Pacman::Bouger(int Evenement, bool Miroir)
{
    Xold_ = X_;
    Yold_ = Y_;

    if (Evenement == EVHaut && Y_ > 0 && Tableau[(Y_-1)][X_] != M)
    {
        Y_ -= 1;
    }
    else if (Evenement == EVBas && Y_ < (Hauteur-1) && Tableau[(Y_+1)][X_] != M)
    {
        if (X_ != 9 || Y_ != 7)
        {
            Y_ += 1;
        }
    }
    else if (Evenement == EVGauche && X_ > 0)
    {
        if (Tableau[Y_][(X_-1)] != M)
        {
            X_ -= 1;
        }
        Miroir = true;
    }
    else if (Evenement == EVDroite && X_ < Largeur-1)
    {
        if (Tableau[Y_][X_+1] != M)
        {
            X_ += 1;
        }
        Miroir = false;
    }

    //Teleporteur
    if (Y_ == 9 && X_ == 0)
    {
        X_ = 17;
    }
    else if (Y_ == 9 && X_ == 18)
    {
        X_ = 1;
    }

    return Miroir;
}


