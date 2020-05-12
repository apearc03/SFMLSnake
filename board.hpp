#include <vector>
#include "cell.hpp"
#include "snake.hpp"

class board
{
    private:
        std::vector<cell> cells;
        snake boardSnake;
    public:
        board(int windowWidth, int windowHeight); //initialize cells inside board constructor
        std::vector<cell> getCells();
        void spawnFood();
        void moveSnake();
};