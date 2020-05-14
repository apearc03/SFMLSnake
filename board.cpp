#include "board.hpp"

board::board(int windowWidth, int windowHeight, int cellSize)
{

    const int halfWidth = (windowWidth / cellSize) / 2;
    const int halfHeight = (windowHeight / cellSize) / 2;

    //cell cellArray[windowWidth / cellSize][windowHeight / cellSize];

    for (int i = 0, w = 0; i < windowWidth; i += cellSize, w++)
    {
        for (int j = 0, h = 0; j < windowHeight; j += cellSize, h++)
        {
            std::shared_ptr<cell> c(new cell(sf::Vector2f(i, j), sf::Vector2f(i + cellSize, j), sf::Vector2f(i + cellSize, j + cellSize), sf::Vector2f(i, j + cellSize)));
            //
            c->setCellState(EMPTY); //remove after, used for testing

            ///
            //condition to set the cell to the snakehead? all other cells empty, set in cell constructor
            //need to find a central cell that works for multiple resolutions
            if (w == halfWidth && h == halfHeight)
            {
                c->setCellState(SNAKE_HEAD); //setting state isnt changing the colour
                boardSnake.reset(new snake(cells.size()));
            }
            cells.push_back(c);
            // added for multi arrays.
            //cellArray[w][h] = cell(sf::Vector2f(i, j), sf::Vector2f(i + cellSize, j), sf::Vector2f(i + cellSize, j + cellSize), sf::Vector2f(i, j + cellSize));
        }
    }
}

std::vector<std::shared_ptr<cell>> board::getCells()
{
    return cells;
}

void board::spawnFood()
{
}

void board::moveSnake()
{
}

std::shared_ptr<snake> board::getBoardSnake()
{
    return boardSnake;
}