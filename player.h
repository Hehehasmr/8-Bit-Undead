#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
private:
    int health;
    sf::Clock damageCooldown; // To prevent instant damage spam

public:
    sf::RectangleShape shape;

    Player();
    void update();
    void move(sf::Vector2f direction);
    
    int getHealth();
    void takeDamage(int amount);
};

#endif
