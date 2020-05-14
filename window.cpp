#include <iostream> //for testing with cout
#include "window.hpp"

int main()
{
    window.setPosition(sf::Vector2i(screenWidth / 2, screenHeight / 2));
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(30);

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

        int snakeIndex = b.getBoardSnake()->getHeadVectorIndex();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            b.getCells().at(snakeIndex)->setCellState(EMPTY);
            b.getCells().at(snakeIndex - 1)->setCellState(SNAKE_HEAD);
            b.getBoardSnake()->setHeadVectorIndex(snakeIndex - 1);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            b.getCells().at(snakeIndex)->setCellState(EMPTY);
            b.getCells().at(snakeIndex - columnDifference)->setCellState(SNAKE_HEAD);
            b.getBoardSnake()->setHeadVectorIndex(snakeIndex - columnDifference);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            b.getCells().at(snakeIndex)->setCellState(EMPTY);
            b.getCells().at(snakeIndex + 1)->setCellState(SNAKE_HEAD);
            b.getBoardSnake()->setHeadVectorIndex(snakeIndex + 1);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            b.getCells().at(snakeIndex)->setCellState(EMPTY);
            b.getCells().at(snakeIndex + columnDifference)->setCellState(SNAKE_HEAD);
            b.getBoardSnake()->setHeadVectorIndex(snakeIndex + columnDifference);
        }

        //handl
        window.clear();
        //render single food
        //render snake
        window.draw(b.getCells().at(b.getBoardSnake()->getHeadVectorIndex())->getQuad());
        // for (int i = 0; i < b.getCells().size(); i++)
        // {
        //     //window.draw(b.getCells().at(i)->getQuad());
        //     if (b.getCells().at(i)->getCellState() == SNAKE_HEAD)
        //     {
        //         window.draw(b.getCells().at(i)->getQuad());

        //         b.getCells().at(i + 1)->setCellState(SNAKE_BODY);
        //         window.draw(b.getCells().at(i + 1)->getQuad());

        //         b.getCells().at(i - 1)->setCellState(SNAKE_BODY);
        //         window.draw(b.getCells().at(i - 1)->getQuad());

        //         b.getCells().at(i - columnDifference)->setCellState(SNAKE_BODY);
        //         window.draw(b.getCells().at(i - columnDifference)->getQuad());

        //         b.getCells().at(i + columnDifference)->setCellState(SNAKE_BODY);
        //         window.draw(b.getCells().at(i + columnDifference)->getQuad());
        //     }
        // }
        window.display();
        //if cell not empty, draw it?
    }

    return 0;
}

void headVectorIndex(int oldIndex, int newIndex)
{
}