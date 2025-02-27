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

    void checkCollisions(); // New function for collision detection

public:
    Game();
    void run();
    void handleEvents();
    void update();
    void render();
    void spawnZombies(int count);
};

#endif
