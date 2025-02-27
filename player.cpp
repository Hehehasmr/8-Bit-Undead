#include "player.h"

Player::Player() {
    shape.setSize(sf::Vector2f(40, 40));
    shape.setFillColor(sf::Color::Blue);
    shape.setPosition(400, 300);
}

void Player::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) move({0, -2});
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) move({0, 2});
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) move({-2, 0});
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) move({2, 0});
}

void Player::move(sf::Vector2f direction) {
    shape.move(direction);
}
