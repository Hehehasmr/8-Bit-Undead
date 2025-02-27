#include "bullet.h"

Bullet::Bullet(float x, float y, sf::Vector2f velocity) {
    shape.setSize(sf::Vector2f(10, 5));
    shape.setFillColor(sf::Color::Yellow);
    shape.setPosition(x, y);
    this->velocity = velocity;
}

void Bullet::update() {
    shape.move(velocity);
}
