#include "snakeIndex.hpp"

snakeIndex::snakeIndex(int startIndex, SNAKEDIRECTION startDirection)
{
    index = startIndex;
    direction = startDirection;
}
int snakeIndex::getIndex()
{
    return index;
}
void snakeIndex::setIndex(int newIndex)
{
    index = newIndex;
}
SNAKEDIRECTION snakeIndex::getDirection()
{
    return direction;
}
void snakeIndex::setDirection(SNAKEDIRECTION newDirection)
{
    direction = newDirection;
}