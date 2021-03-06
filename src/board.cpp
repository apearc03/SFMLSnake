#include "board.hpp"

board::board(int windowWidth, int windowHeight, int cellSize)
{
    resetBoard(windowWidth, windowHeight, cellSize);
}

std::vector<std::shared_ptr<cell>> board::getCells()
{
    return cells;
}

int board::getCurrentFoodIndex()
{
    return currentFoodIndex;
}

bool board::userHasWon()
{
    return possibleCells.size() == 0;
}

void board::updatePossibleCells()
{
    possibleCells.clear();
    for (int i = 0; i < (int)cells.size(); i++)
    {
        if (cells.at(i)->getCellState() != SNAKE_HEAD && cells.at(i)->getCellState() != SNAKE_BODY)
        {
            possibleCells.push_back(i);
        }
    }
}

void board::spawnFood()
{
    int randomPossibleIndex = rand() % possibleCells.size();
    int newFoodIndex = possibleCells.at(randomPossibleIndex);
    cells.at(newFoodIndex)->setCellState(FOOD);
    currentFoodIndex = newFoodIndex;
}

void board::foodEaten()
{
    score++;
    cells.at(currentFoodIndex)->setCellState(EMPTY);
}

std::shared_ptr<snake> board::getBoardSnake()
{
    return boardSnake;
}

int board::getScore()
{
    return score;
};

void board::resetBoard(int windowWidth, int windowHeight, int cellSize)
{
    cells.clear();
    score = 0;
    const int halfWidth = (windowWidth / cellSize) / 2;
    const int halfHeight = (windowHeight / cellSize) / 2;

    for (int i = 0, w = 0; i < windowWidth; i += cellSize, w++)
    {
        for (int j = 0, h = 0; j < windowHeight; j += cellSize, h++)
        {
            std::shared_ptr<cell> c(new cell(sf::Vector2f(i, j), sf::Vector2f(i + cellSize, j), sf::Vector2f(i + cellSize, j + cellSize), sf::Vector2f(i, j + cellSize)));

            if (w == halfWidth && h == halfHeight)
            {
                c->setCellState(SNAKE_HEAD);
                boardSnake.reset(new snake(cells.size()));
            }
            cells.push_back(c);
        }
    }
}