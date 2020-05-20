#include <vector>
#include <SFML/Graphics.hpp>
#include "cell.hpp"
#include "snake.hpp"
#include <memory>

class board
{
private:
    std::vector<std::shared_ptr<cell>> cells;
    std::shared_ptr<snake> boardSnake;
    int currentFoodIndex;
    int score;
    std::vector<uint16_t> possibleCells;

public:
    board(int windowWidth, int windowHeight, int cellSize); //initialize cells inside board constructor
    std::vector<std::shared_ptr<cell>> getCells();
    int getCurrentFoodIndex();
    bool userHasWon();
    void spawnFood();
    void foodEaten();
    void updatePossibleCells();
    std::shared_ptr<snake> getBoardSnake();
    int getScore();
    void resetBoard(int windowWidth, int windowHeight, int cellSize);
};