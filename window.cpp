#include <iostream> //for testing with cout
#include "window.hpp"

void updateHeadIndex(int oldIndex, int newIndex)
{
    b.getCells().at(oldIndex)->setCellState(EMPTY);
    b.getCells().at(newIndex)->setCellState(SNAKE_HEAD);
    b.getBoardSnake()->getSnakeIndices()->at(0) = newIndex;
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

        if(b.getBoardSnake()->getSnakeIndices()->at(0) == b.getCurrentFoodIndex()){
            b.foodEaten();
            b.spawnFood();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }

        SNAKEDIRECTION direction = b.getBoardSnake()->getDirection();
        int snakeHeadIndex = b.getBoardSnake()->getSnakeIndices()->at(0);

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
                if (snakeHeadIndex == topRow[i])
                {
                    updateHeadIndex(snakeHeadIndex, bottomRow[i]);
                    edgeCell = true;
                }
            }
            if (!edgeCell)
            {
                updateHeadIndex(snakeHeadIndex, snakeHeadIndex - 1);
            }
        }

        if (direction == DOWN)
        {
            bool edgeCell = false;
            for (int i = 0; i < rowCount; i++)
            {
                if (snakeHeadIndex == bottomRow[i])
                {
                    updateHeadIndex(snakeHeadIndex, topRow[i]);
                    edgeCell = true;
                }
            }
            if (!edgeCell)
            {
                updateHeadIndex(snakeHeadIndex, snakeHeadIndex + 1);
            }
        }

        if (direction == LEFT)
        {
            bool edgeCell = false;
            for (int i = 0; i < columnCount; i++)
            {
                if (snakeHeadIndex == leftCol[i])
                {
                    updateHeadIndex(snakeHeadIndex, rightCol[i]);
                    edgeCell = true;
                }
            }
            if (!edgeCell)
            {
                updateHeadIndex(snakeHeadIndex, snakeHeadIndex - columnCount);
            }
        }

        if (direction == RIGHT)
        {
            bool edgeCell = false;
            for (int i = 0; i < columnCount; i++)
            {
                if (snakeHeadIndex == rightCol[i])
                {
                    updateHeadIndex(snakeHeadIndex, leftCol[i]);
                    edgeCell = true;
                }
            }
            if (!edgeCell)
            {
                updateHeadIndex(snakeHeadIndex, snakeHeadIndex + columnCount);
            }
        }

        //handl
        window.clear();
        //render single food
        //render snake
        window.draw(b.getCells().at(b.getCurrentFoodIndex())->getQuad());
        //window.draw(b.getCells().at(b.getBoardSnake()->getHeadVectorIndex())->getQuad());
        for(int s : *b.getBoardSnake()->getSnakeIndices()){
            window.draw(b.getCells().at(s)->getQuad());
            std::cout << s;
            std::cout << "\n";
        }
        window.display();
        //if cell not empty, draw it?
        
    }

    return 0;
}