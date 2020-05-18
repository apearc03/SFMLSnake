#include <iostream> //for testing with cout
#include "window.hpp"

void updateHeadIndex(int newHeadIndex)
{
    for (std::reverse_iterator<std::vector<std::shared_ptr<snakeIndex>>::iterator> i = b.getBoardSnake()->getSnakeIndices()->rbegin();
         i != b.getBoardSnake()->getSnakeIndices()->rend(); i++)
    {
        if (i == b.getBoardSnake()->getSnakeIndices()->rbegin() && b.getBoardSnake()->getSnakeIndices()->size() == 1)
        {
            //snake size 1
            b.getCells().at(newHeadIndex)->setCellState(SNAKE_HEAD);
            b.getCells().at(i->get()->getIndex())->setCellState(EMPTY);
            b.getBoardSnake()->getHeadIndex()->setIndex(newHeadIndex);
        }
        else if (i == b.getBoardSnake()->getSnakeIndices()->rbegin())
        {
            //end of snake
            int nextIndex = (i + 1)->get()->getIndex();
            b.getCells().at(i->get()->getIndex())->setCellState(EMPTY);
            i->get()->setIndex(nextIndex);
            b.getCells().at(i->get()->getIndex())->setCellState(SNAKE_BODY);
        }
        else if (i == b.getBoardSnake()->getSnakeIndices()->rend() - 1)
        {
            //start of snake.
            b.getCells().at(newHeadIndex)->setCellState(SNAKE_HEAD);
            b.getBoardSnake()->getHeadIndex()->setIndex(newHeadIndex);
        }
        else
        {
            //middle segment
            int nextIndex = (i + 1)->get()->getIndex();
            i->get()->setIndex(nextIndex);
            b.getCells().at(i->get()->getIndex())->setCellState(SNAKE_BODY);
        }
    }
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
    bool foodWasEaten = true;
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

        if (foodWasEaten)
        {
            b.spawnFood();
            foodWasEaten = false;
        }

        int snakeHeadIndex = b.getBoardSnake()->getHeadIndex()->getIndex();

        //event that loops through the snakebody and checks if the head index is equal to any of them?
        for (std::reverse_iterator<std::vector<std::shared_ptr<snakeIndex>>::iterator> i = b.getBoardSnake()->getSnakeIndices()->rbegin();
             i != b.getBoardSnake()->getSnakeIndices()->rend() - 1; i++)
        {
            //reset board
            //show the previous score until the player moves again and direction is not still.
            if(snakeHeadIndex == i->get()->getIndex()){
                std::cout << "game over";
                std::cout << "\n";
            }
        }
        
        if (snakeHeadIndex == b.getCurrentFoodIndex())
        {
            b.foodEaten();
            snakeIndex *last = b.getBoardSnake()->getSnakeIndices()->rbegin()->get();
            b.getBoardSnake()->growSnake(last->getIndex());
            foodWasEaten = true;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }

        SNAKEDIRECTION headDirection = b.getBoardSnake()->getDirection();

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && headDirection != DOWN)
        {
            b.getBoardSnake()->setDirection(UP);
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && headDirection != UP)
        {
            b.getBoardSnake()->setDirection(DOWN);
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && headDirection != RIGHT)
        {
            b.getBoardSnake()->setDirection(LEFT);
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && headDirection != LEFT)
        {
            b.getBoardSnake()->setDirection(RIGHT);
        }

        if (headDirection == UP)
        {
            bool edgeCell = false;
            for (int i = 0; i < rowCount; i++)
            {
                if (snakeHeadIndex == topRow[i])
                {
                    updateHeadIndex(bottomRow[i]);
                    edgeCell = true;
                }
            }
            if (!edgeCell)
            {
                updateHeadIndex(snakeHeadIndex - 1);
            }
        }

        if (headDirection == DOWN)
        {
            bool edgeCell = false;
            for (int i = 0; i < rowCount; i++)
            {
                if (snakeHeadIndex == bottomRow[i])
                {
                    updateHeadIndex(topRow[i]);
                    edgeCell = true;
                }
            }
            if (!edgeCell)
            {
                updateHeadIndex(snakeHeadIndex + 1);
            }
        }

        if (headDirection == LEFT)
        {
            bool edgeCell = false;
            for (int i = 0; i < columnCount; i++)
            {
                if (snakeHeadIndex == leftCol[i])
                {
                    updateHeadIndex(rightCol[i]);
                    edgeCell = true;
                }
            }
            if (!edgeCell)
            {
                updateHeadIndex(snakeHeadIndex - columnCount);
            }
        }

        if (headDirection == RIGHT)
        {
            bool edgeCell = false;
            for (int i = 0; i < columnCount; i++)
            {
                if (snakeHeadIndex == rightCol[i])
                {
                    updateHeadIndex(leftCol[i]);
                    edgeCell = true;
                }
            }
            if (!edgeCell)
            {
                updateHeadIndex(snakeHeadIndex + columnCount);
            }
        }

        window.clear();
        //add game state and render different things on screen? Way to reset board, show score after game end.
        for (std::shared_ptr<snakeIndex> s : *b.getBoardSnake()->getSnakeIndices())
        {
            window.draw(b.getCells().at(s->getIndex())->getQuad());
        }
        window.draw(b.getCells().at(b.getCurrentFoodIndex())->getQuad());
        window.display();
    }

    return 0;
}