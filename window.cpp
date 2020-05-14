#include <iostream> //for testing with cout
#include "window.hpp"

void updateHeadIndex(int oldIndex, int newIndex)
{
    b.getCells().at(oldIndex)->setCellState(EMPTY);
    b.getCells().at(newIndex)->setCellState(SNAKE_HEAD);
    b.getBoardSnake()->setHeadVectorIndex(newIndex);
}

void initEdgeCells()
{
    for (int i = 0; i < rowCount; i++)
    {
        topRow[i] = columnCount * i;
    }

    for (int j = 1; j < rowCount + 1; j++)
    {
        bottomRow[j - 1] = columnCount * j - 1;
    }

    for (int k = 0; k < columnCount; k++)
    {
        leftCol[k] = k;
    }

    for (int l = 0; l < columnCount; l++)
    {
        rightCol[l] = columnCount * (rowCount - 1) + l;
    }
}

int main()
{
    window.setPosition(sf::Vector2i(screenWidth / 2, screenHeight / 2));
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(45);

    initEdgeCells();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }

        int snakeIndex = b.getBoardSnake()->getHeadVectorIndex();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            bool edgeCell = false;
            for (int i = 0; i < rowCount; i++)
            {
                if (snakeIndex == topRow[i])
                {
                    updateHeadIndex(snakeIndex, bottomRow[i]);
                    edgeCell = true;
                }
            }
            //if it's a top row cell. Go to appropriate bottom row cell.
            //if current index is in top row. Go to equivalent bottom row.
            if (!edgeCell)
            {
                updateHeadIndex(snakeIndex, snakeIndex - 1);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            bool edgeCell = false;
            for (int i = 0; i < rowCount; i++)
            {
                if (snakeIndex == bottomRow[i])
                {
                    updateHeadIndex(snakeIndex, topRow[i]);
                    edgeCell = true;
                }
            }
            //if it's a bottom row cell. Go to appropriate top row cell.
            if (!edgeCell)
            {
                updateHeadIndex(snakeIndex, snakeIndex + 1);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            bool edgeCell = false;
            for (int i = 0; i < rowCount; i++)
            {
                if (snakeIndex == leftCol[i])
                {
                    updateHeadIndex(snakeIndex, rightCol[i]);
                    edgeCell = true;
                }
            }
            //if it's a left column cell. Go to appropriate right column cell.
            if (!edgeCell)
            {
                updateHeadIndex(snakeIndex, snakeIndex - columnCount);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            bool edgeCell = false;
            for (int i = 0; i < rowCount; i++)
            {
                if (snakeIndex == rightCol[i])
                {
                    updateHeadIndex(snakeIndex, leftCol[i]);
                    edgeCell = true;
                }
            }
            //if it's a right column cell. Go to appropriate left column cell.
            if (!edgeCell)
            {
                updateHeadIndex(snakeIndex, snakeIndex + columnCount);
            }
        }

        //handl
        window.clear();
        //render single food
        //render snake

        window.draw(b.getCells().at(b.getBoardSnake()->getHeadVectorIndex())->getQuad());
        window.display();
        //if cell not empty, draw it?
    }

    return 0;
}