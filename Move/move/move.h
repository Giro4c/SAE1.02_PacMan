#ifndef MOVE_H
#define MOVE_H

#include <vector>

#include "MinGL2/include/mingl/mingl.h"
#include "MinGL2/include/mingl/gui/sprite.h"
#include "MinGL2/include/mingl/graphics/vec2d.h"
#include "MinGL2/include/mingl/shape/rectangle.h"

#include "yaml.h"

void moveSprite(nsGui::Sprite &, const int &, const int &);
void keyboard(MinGL &, nsGui::Sprite &, std::vector<unsigned>);

#endif // MOVE_H



#include "Pacman.h"

class Pacman : public Personnage
{
private:
    bool Miroir_;

public:
    Pacman(int X, int Y);
    bool Bouger(int Evenement, bool Miroir);
};
