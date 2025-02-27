#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
public:
    sf::RectangleShape shape;
    Player();
    void update();
    void move(sf::Vector2f direction);
};

#endif
