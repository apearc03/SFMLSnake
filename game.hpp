#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "board.hpp"
#include "snakeDirection.hpp"
#include <vector>
#include <string>

class game
{
private:
    int windowWidth;
    int windowHeight;
    int cellSize; 
    int columnCount; 
    int rowCount;
    int screenWidth;
    int screenHeight;
    int *topRow;
    int *bottomRow;
    int *leftCol;
    int *rightCol;
    bool foodWasEaten = true;
    bool gameOver = false;
    bool drawScore = false;
    sf::Font font;
    sf::Text text;
    sf::RenderWindow w;
    board b;
    void updateSnakePosition(int newHeadIndex);
    void initEdgeCells();
    void setUpFont();
    void reset(std::string message);

public:
    game(int windowW, int windowH, int cellS, int frameRate);
    void start();
};
