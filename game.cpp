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

        // Shooting Mechanic: Press Space to shoot
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
    }
}

void Game::render() {
    window.clear();
    
    if (gameState == MENU) {
        // Render menu (text not implemented here)
    } else {
        window.draw(player.shape);
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
