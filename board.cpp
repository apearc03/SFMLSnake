#include "board.hpp"
#include <SFML/Graphics.hpp> //remove after, used for colours

board::board(int windowWidth, int windowHeight, int cellSize)
{
    bool black = true; //remove after

    const int halfWidth = (windowWidth / cellSize) / 2;
    const int halfHeight = (windowHeight / cellSize) / 2;

    for (int i = 0, w = 0; i < windowWidth; i += cellSize, w++)
    {
        for (int j = 0, h = 0; j < windowHeight; j += cellSize, h++)
        {
            cell c = cell(sf::Vector2f(i, j), sf::Vector2f(i + cellSize, j), sf::Vector2f(i + cellSize, j + cellSize), sf::Vector2f(i, j + cellSize));
            //
            if (black)
            {
                c.setCellColour(sf::Color::Black); //remove after, used for testing
                black = false;
            }
            else
            {
                c.setCellColour(sf::Color::Blue);
                black = true;
            }
            ///
            //condition to set the cell to the snakehead? all other cells empty, set in cell constructor
            //need to find a central cell that works for multiple resolutions
            if(w == halfWidth && h == halfHeight){
                c.setCellState(SNAKE_HEAD);
                c.setCellColour(sf::Color::Red);
            }
            cells.push_back(c);
        }
        black = !black; //remove after
    }

    boardSnake = snake();
}

std::vector<cell> board::getCells()
{
    return cells;
}

void board::spawnFood()
{
}

void board::moveSnake()
{
}

snake board::getBoardSnake(){
    return boardSnake;
}