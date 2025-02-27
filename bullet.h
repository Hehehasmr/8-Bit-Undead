#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

class Bullet {
public:
    sf::RectangleShape shape;
    sf::Vector2f velocity;

    Bullet(float x, float y, sf::Vector2f velocity);
    void update();
};

#endif
