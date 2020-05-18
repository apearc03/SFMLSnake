#include "snakeIndex.hpp"

snakeIndex::snakeIndex(int startIndex)
{
    index = startIndex;
}
int snakeIndex::getIndex()
{
    return index;
}
void snakeIndex::setIndex(int newIndex)
{
    index = newIndex;
}