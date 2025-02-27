#include "zombie.h"
#include <cmath>

Zombie::Zombie(float x, float y) {
    shape.setSize(sf::Vector2f(30, 30));
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(x, y);
}

void Zombie::moveTowards(Player& player) {
    sf::Vector2f playerPos = player.shape.getPosition();
    sf::Vector2f dir = playerPos - shape.getPosition();
    float length = std::sqrt(dir.x * dir.x + dir.y * dir.y);
    
    if (length != 0) {
        dir /= length;  // Normalize direction
    }
    
    shape.move(dir * 0.5f);  // Move towards the player
}
