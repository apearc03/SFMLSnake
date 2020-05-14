#include <vector>
#include <SFML/Graphics.hpp>
#include "cell.hpp"
#include "snake.hpp"
#include <memory>
#include <iostream>

class board
{
    private:
        std::vector<std::shared_ptr<cell>> cells;
        std::shared_ptr<snake> boardSnake;
    public:
        board(int windowWidth, int windowHeight, int cellSize); //initialize cells inside board constructor
        std::vector<std::shared_ptr<cell>> getCells();
        void spawnFood();
        std::shared_ptr<snake> getBoardSnake();
};