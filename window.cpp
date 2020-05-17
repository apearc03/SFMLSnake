#include <iostream> //for testing with cout
#include "window.hpp"

void updateHeadIndex(int oldIndex, int newIndex)
{
    b.getCells().at(oldIndex)->setCellState(EMPTY);
    b.getCells().at(newIndex)->setCellState(SNAKE_HEAD);
    b.getBoardSnake()->getHeadIndex()->setIndex(newIndex);
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
    bool foodWasEaten = false;
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

        if(foodWasEaten){
            b.spawnFood();
            foodWasEaten = false;
        }
        if(b.getBoardSnake()->getHeadIndex()->getIndex() == b.getCurrentFoodIndex()){
            b.foodEaten();
            foodWasEaten = true;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }

        SNAKEDIRECTION headDirection = b.getBoardSnake()->getHeadIndex()->getDirection(); //add method to snake to get head index
        int snakeHeadIndex = b.getBoardSnake()->getHeadIndex()->getIndex();

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && headDirection != DOWN)
        {
            b.getBoardSnake()->getHeadIndex()->setDirection(UP);
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && headDirection != UP)
        {
            b.getBoardSnake()->getHeadIndex()->setDirection(DOWN);
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && headDirection != RIGHT)
        {
            b.getBoardSnake()->getHeadIndex()->setDirection(LEFT);
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && headDirection != LEFT)
        {
            b.getBoardSnake()->getHeadIndex()->setDirection(RIGHT);
        }

        if (headDirection == UP)
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

        if (headDirection == DOWN)
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

        if (headDirection == LEFT)
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

        if (headDirection == RIGHT)
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
        //window.draw(b.getCells().at(b.getBoardSnake()->getHeadVectorIndex())->getQuad());
        for(std::shared_ptr<snakeIndex> s : *b.getBoardSnake()->getSnakeIndices()){
            window.draw(b.getCells().at(s->getIndex())->getQuad());
            std::cout << b.getCurrentFoodIndex();
            std::cout << "\n";
        }
        window.draw(b.getCells().at(b.getCurrentFoodIndex())->getQuad());
        window.display();
        //if cell not empty, draw it?
        
    }

    return 0;
}