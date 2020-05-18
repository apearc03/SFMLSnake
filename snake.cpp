#include "snake.hpp"

snake::snake(int headStartIndex)
{
    snakeIndices->push_back(std::make_shared<snakeIndex>(headStartIndex));
    direction = STILL;
}

std::shared_ptr<std::vector<std::shared_ptr<snakeIndex>>> snake::getSnakeIndices()
{
    return snakeIndices;
}

void snake::growSnake(int index)
{
    snakeIndices->push_back(std::make_shared<snakeIndex>(index));
}

std::shared_ptr<snakeIndex> snake::getHeadIndex()
{
    return snakeIndices->at(0);
}

SNAKEDIRECTION snake::getDirection()
{
    return direction;
}
void snake::setDirection(SNAKEDIRECTION newDirection)
{
    direction = newDirection;
}