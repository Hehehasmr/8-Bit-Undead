#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <SFML/Graphics.hpp>
#include "player.h"

class Zombie {
public:
    sf::RectangleShape shape;
    Zombie(float x, float y);
    void moveTowards(Player& player);
};

#endif
