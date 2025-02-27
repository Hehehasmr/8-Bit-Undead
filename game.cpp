#include "game.h"

Game::Game() : window(sf::VideoMode(800, 600), "8-Bit Undead"), gameState(MENU) {}

void Game::run() {
    while (window.isOpen()) {
        handleEvents();
        update();
        render();
    }
}

void Game::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        if (gameState == MENU) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) gameState = PLAY_EASY;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) gameState = PLAY_HARD;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) gameState = SHOP;
        }

        // Shooting Mechanic
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            bullets.emplace_back(player.shape.getPosition().x + 20, player.shape.getPosition().y + 10, {5, 0});
        }
    }
}

void Game::update() {
    if (gameState == PLAY_EASY || gameState == PLAY_HARD) {
        player.update();

        // Spawn zombies if needed
        if (zombies.size() < 5) {
            spawnZombies(1);
        }

        // Move zombies toward the player
        for (auto& zombie : zombies) {
            zombie.moveTowards(player);
        }

        // Move bullets
        for (auto& bullet : bullets) {
            bullet.update();
        }

        checkCollisions();
        checkPlayerDamage();
    }
}

void Game::render() {
    window.clear();
    
    if (gameState == MENU) {
        // Render menu (text not implemented here)
    } else {
        window.draw(player.shape);
        window.draw(player.getHealthBar()); // Draw health bar

        for (auto& zombie : zombies) window.draw(zombie.shape);
        for (auto& bullet : bullets) window.draw(bullet.shape);
    }

    window.display();
}

void Game::spawnZombies(int count) {
    for (int i = 0; i < count; i++) {
        zombies.emplace_back(Zombie(rand() % 800, rand() % 600));
    }
}

void Game::checkCollisions() {
    // Check each bullet
    for (size_t i = 0; i < bullets.size(); i++) {
        for (size_t j = 0; j < zombies.size(); j++) {
            if (bullets[i].shape.getGlobalBounds().intersects(zombies[j].shape.getGlobalBounds())) {
                bullets.erase(bullets.begin() + i);
                zombies.erase(zombies.begin() + j);
                return; // Exit after one collision to prevent issues
            }
        }
    }
}

void Game::checkPlayerDamage() {
    for (auto& zombie : zombies) {
        if (player.shape.getGlobalBounds().intersects(zombie.shape.getGlobalBounds())) {
            player.takeDamage(10); // Zombies deal 10 damage on contact
        }
    }

    // Show Game Over screen if health reaches 0
    if (player.getHealth() <= 0) {
        showGameOverScreen();
    }
}

void Game::showGameOverScreen() {
    sf::Font font;
    if (!font.loadFromFile("assets/arcade.ttf")) { // Ensure font exists
        return;
    }

    sf::Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setString("Game Over!\nPress ENTER to return to menu.");
    gameOverText.setCharacterSize(30);
    gameOverText.setFillColor(sf::Color::White);
    gameOverText.setPosition(200, 250);

    while (window.isOpen()) {
        window.clear(sf::Color::Black);
        window.draw(gameOverText);
        window.display();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                gameState = MENU;
                player = Player(); // Reset player stats
                zombies.clear();
                bullets.clear();
                return;
            }
        }
    }
}
