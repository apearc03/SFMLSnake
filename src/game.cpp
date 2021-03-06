#include "game.hpp"

game::game(int windowW, int windowH, int cellS, int frameRate) : b(windowW, windowH, cellS)
{
    windowWidth = windowW;
    windowHeight = windowH;
    cellSize = cellS;
    columnCount = windowHeight / cellSize;
    rowCount = windowWidth / cellSize;
    screenWidth = sf::VideoMode::getDesktopMode().width - windowWidth;
    screenHeight = sf::VideoMode::getDesktopMode().height - windowHeight;
    topRow = new int[rowCount];
    bottomRow = new int[rowCount];
    leftCol = new int[columnCount];
    rightCol = new int[columnCount];
    foodWasEaten = true;
    gameOver = false;
    drawScore = false;
    w.create(sf::VideoMode(windowW, windowH), "SFMLSnake");
    w.setPosition(sf::Vector2i(screenWidth / 2, screenHeight / 2));
    w.setFramerateLimit(frameRate);

    srand(time(0));
    initEdgeCells();
    setUpFont();
}

void game::updateSnakePosition(int newHeadIndex)
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
        w.draw(b.getCells().at(i->get()->getIndex())->getQuad());
    }
}

void game::initEdgeCells()
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

void game::setUpFont()
{
    font.loadFromFile("fonts/OpenSans-Bold.ttf");
    text.setFont(font);
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::Cyan);
    text.setOutlineColor(sf::Color::Blue);
    text.setPosition(windowWidth / 2, windowHeight / 2 - windowHeight / 4);
}

void game::reset(std::string message)
{
    text.setString(message);
    drawScore = true;
    b.resetBoard(windowWidth, windowHeight, cellSize);
    gameOver = false;
    b.updatePossibleCells();
    b.spawnFood();
    foodWasEaten = false;
}

void game::start()
{
    while (w.isOpen())
    {
        if (foodWasEaten)
        {
            b.updatePossibleCells();
            if (b.userHasWon())
            {
                reset("You\nscored\n" + std::to_string(b.getScore()) + "\npoint(s).\nThe maximum.");
            }
            else
            {
                b.spawnFood();
                foodWasEaten = false;
            }
        }

        int snakeHeadIndex = b.getBoardSnake()->getHeadIndex()->getIndex();

        //event that loops through the snakebody and checks if the head index is equal to any of them
        std::reverse_iterator<std::vector<std::shared_ptr<snakeIndex>>::iterator> i = b.getBoardSnake()->getSnakeIndices()->rbegin();
        while (i != b.getBoardSnake()->getSnakeIndices()->rend() - 1 && !gameOver)
        {
            if (snakeHeadIndex == i->get()->getIndex())
            {
                gameOver = true;
            }
            i++;
        }

        if (b.getBoardSnake()->getDirection() != STILL)
        {
            drawScore = false;
        }

        if (gameOver)
        {
            reset("You\nscored\n" + std::to_string(b.getScore()) + "\npoint(s)");
        }

        if (snakeHeadIndex == b.getCurrentFoodIndex())
        {
            b.foodEaten();
            snakeIndex *last = b.getBoardSnake()->getSnakeIndices()->rbegin()->get();
            b.getBoardSnake()->growSnake(last->getIndex());
            foodWasEaten = true;
        }

        SNAKEDIRECTION headDirection = b.getBoardSnake()->getDirection();
        sf::Event event;
        while (w.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                w.close();
            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    w.close();
                }

                if ((event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up) && headDirection != DOWN)
                {
                    b.getBoardSnake()->setDirection(UP);
                }
                if ((event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down) && headDirection != UP)
                {
                    b.getBoardSnake()->setDirection(DOWN);
                }
                if ((event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) && headDirection != RIGHT)
                {
                    b.getBoardSnake()->setDirection(LEFT);
                }
                if ((event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) && headDirection != LEFT)
                {
                    b.getBoardSnake()->setDirection(RIGHT);
                }
            }
        }
        
        w.clear();
        if (headDirection == STILL)
        {
            w.draw(b.getCells().at(snakeHeadIndex)->getQuad());
        }

        if (headDirection == UP)
        {
            bool edgeCell = false;
            for (int i = 0; i < rowCount; i++)
            {
                if (snakeHeadIndex == topRow[i])
                {
                    updateSnakePosition(bottomRow[i]);
                    edgeCell = true;
                }
            }
            if (!edgeCell)
            {
                updateSnakePosition(snakeHeadIndex - 1);
            }
        }

        if (headDirection == DOWN)
        {
            bool edgeCell = false;
            for (int i = 0; i < rowCount; i++)
            {
                if (snakeHeadIndex == bottomRow[i])
                {
                    updateSnakePosition(topRow[i]);
                    edgeCell = true;
                }
            }
            if (!edgeCell)
            {
                updateSnakePosition(snakeHeadIndex + 1);
            }
        }

        if (headDirection == LEFT)
        {
            bool edgeCell = false;
            for (int i = 0; i < columnCount; i++)
            {
                if (snakeHeadIndex == leftCol[i])
                {
                    updateSnakePosition(rightCol[i]);
                    edgeCell = true;
                }
            }
            if (!edgeCell)
            {
                updateSnakePosition(snakeHeadIndex - columnCount);
            }
        }

        if (headDirection == RIGHT)
        {
            bool edgeCell = false;
            for (int i = 0; i < columnCount; i++)
            {
                if (snakeHeadIndex == rightCol[i])
                {
                    updateSnakePosition(leftCol[i]);
                    edgeCell = true;
                }
            }
            if (!edgeCell)
            {
                updateSnakePosition(snakeHeadIndex + columnCount);
            }
        }

        w.draw(b.getCells().at(b.getCurrentFoodIndex())->getQuad());
        if (drawScore)
        {
            w.draw(text);
        }
        w.display();
    }
}