#include "player.h"

Player::Player() {
    shape.setSize(sf::Vector2f(40, 40));
    shape.setFillColor(sf::Color::Blue);
    shape.setPosition(400, 300);
    health = 100; // Player starts with 100 HP

    // Initialize health bar
    healthBar.setSize(sf::Vector2f(100, 10)); 
    healthBar.setFillColor(sf::Color::Green);
    healthBar.setPosition(shape.getPosition().x, shape.getPosition().y - 15);
}

void Player::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) move({0, -2});
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) move({0, 2});
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) move({-2, 0});
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) move({2, 0});

    updateHealthBar(); // Update health bar position
}

void Player::move(sf::Vector2f direction) {
    shape.move(direction);
    healthBar.setPosition(shape.getPosition().x, shape.getPosition().y - 15);
}

int Player::getHealth() {
    return health;
}

void Player::takeDamage(int amount) {
    if (damageCooldown.getElapsedTime().asSeconds() > 1.0f) { // Take damage once per second
        health -= amount;
        damageCooldown.restart();
    }
}

void Player::updateHealthBar() {
    float healthPercentage = static_cast<float>(health) / 100.0f;
    healthBar.setSize(sf::Vector2f(100 * healthPercentage, 10));

    if (healthPercentage > 0.5f) {
        healthBar.setFillColor(sf::Color::Green);
    } else if (healthPercentage > 0.2f) {
        healthBar.setFillColor(sf::Color::Yellow);
    } else {
        healthBar.setFillColor(sf::Color::Red);
    }
}

sf::RectangleShape Player::getHealthBar() {
    return healthBar;
}
