#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "player.h"
#include "zombie.h"
#include "bullet.h"
#include <vector>

enum GameState { MENU, PLAY_EASY, PLAY_HARD, SHOP };

class Game {
private:
    sf::RenderWindow window;
    GameState gameState;
    Player player;
    std::vector<Zombie> zombies;
    std::vector<Bullet> bullets;

    void checkCollisions(); // Bullet-Zombie Collision
    void checkPlayerDamage(); // Zombie Attack System
    void showGameOverScreen(); // Game Over Screen

public:
    Game();
    void run();
    void handleEvents();
    void update();
    void render();
    void spawnZombies(int count);
};

#endif
