#include <iostream> //for testing with cout
#include "window.hpp"

void updateHeadIndex(int oldIndex, int newIndex)
{
    b.getCells().at(oldIndex)->setCellState(EMPTY);
    b.getCells().at(newIndex)->setCellState(SNAKE_HEAD);
    b.getBoardSnake()->setHeadVectorIndex(newIndex);
}

int main()
{
    window.setPosition(sf::Vector2i(screenWidth / 2, screenHeight / 2));
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(45);

    int topRow[rowCount];

    for (int i = 0; i < rowCount; i++)
    {
        topRow[i] = columnCount * i;
    }

    int bottomRow[rowCount];

    for (int j = 1; j < rowCount + 1; j++)
    {
        bottomRow[j - 1] = columnCount * j - 1;
    }

    int leftCol[rowCount];

    for (int k = 0; k < columnCount; k++)
    {
        leftCol[k] = k;
    }

    int rightCol[rowCount];

    for (int l = 0; l < columnCount; l++)
    {
        rightCol[l] = columnCount * (rowCount - 1) + l;
    }

    //top row, columnCount * 0    up to      columnCount * (rowCount - 1)
    //bottom row, columnCount*1 - 1     up to    columnCount*rowCount -1
    //left column, 0      up to      columnCount-1
    //right column, columnCount * (rowCount - 1) + 0  up to  columnCount * (rowCount - 1)+columnCount-1

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
            //if it's a top row cell. Go to appropriate bottom row cell.
            updateHeadIndex(snakeIndex, snakeIndex - 1);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            //if it's a left column cell. Go to appropriate right column cell.
            updateHeadIndex(snakeIndex, snakeIndex - columnCount);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            //if it's a bottom row cell. Go to appropriate top row cell.
            updateHeadIndex(snakeIndex, snakeIndex + 1);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            //if it's a right column cell. Go to appropriate left column cell.
            updateHeadIndex(snakeIndex, snakeIndex + columnCount);
        }

        //handl
        window.clear();
        //render single food
        //render snake

        for (int i = 0; i < rowCount; i++)
        {
            window.draw(b.getCells().at(topRow[i])->getQuad());
        }

        for (int j = 0; j < rowCount; j++)
        {
            window.draw(b.getCells().at(bottomRow[j])->getQuad());
        }

        for (int k = 0; k < columnCount; k++)
        {
            window.draw(b.getCells().at(leftCol[k])->getQuad());
        }

        for (int l = 0; l < columnCount; l++)
        {
            window.draw(b.getCells().at(rightCol[l])->getQuad());
        }

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