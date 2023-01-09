
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
