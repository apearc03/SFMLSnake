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
        int currentFoodIndex; //probably have to be a pointer?
    public:
        board(int windowWidth, int windowHeight, int cellSize); //initialize cells inside board constructor
        std::vector<std::shared_ptr<cell>> getCells();
        int getCurrentFoodIndex();
        void spawnFood();
        void foodEaten();
        std::shared_ptr<snake> getBoardSnake();
};