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
    window.setFramerateLimit(10);

    srand(time(0));
    initEdgeCells();
    b.spawnFood();

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

        if(b.getBoardSnake()->getHeadVectorIndex() == b.getCurrentFoodIndex()){
            b.foodEaten();
            b.spawnFood();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }

        SNAKEDIRECTION direction = b.getBoardSnake()->getDirection();
        int snakeIndex = b.getBoardSnake()->getHeadVectorIndex();

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && direction != DOWN)
        {
            b.getBoardSnake()->setDirection(UP);
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && direction != UP)
        {
            b.getBoardSnake()->setDirection(DOWN);
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && direction != RIGHT)
        {
            b.getBoardSnake()->setDirection(LEFT);
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && direction != LEFT)
        {
            b.getBoardSnake()->setDirection(RIGHT);
        }

        if (direction == UP)
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
            if (!edgeCell)
            {
                updateHeadIndex(snakeIndex, snakeIndex - 1);
            }
        }

        if (direction == DOWN)
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
            if (!edgeCell)
            {
                updateHeadIndex(snakeIndex, snakeIndex + 1);
            }
        }

        if (direction == LEFT)
        {
            bool edgeCell = false;
            for (int i = 0; i < columnCount; i++)
            {
                if (snakeIndex == leftCol[i])
                {
                    updateHeadIndex(snakeIndex, rightCol[i]);
                    edgeCell = true;
                }
            }
            if (!edgeCell)
            {
                updateHeadIndex(snakeIndex, snakeIndex - columnCount);
            }
        }

        if (direction == RIGHT)
        {
            bool edgeCell = false;
            for (int i = 0; i < columnCount; i++)
            {
                if (snakeIndex == rightCol[i])
                {
                    updateHeadIndex(snakeIndex, leftCol[i]);
                    edgeCell = true;
                }
            }
            if (!edgeCell)
            {
                updateHeadIndex(snakeIndex, snakeIndex + columnCount);
            }
        }

        //handl
        window.clear();
        //render single food
        //render snake
        window.draw(b.getCells().at(b.getCurrentFoodIndex())->getQuad());
        window.draw(b.getCells().at(b.getBoardSnake()->getHeadVectorIndex())->getQuad());
        window.display();
        //if cell not empty, draw it?
        
    }

    return 0;
}