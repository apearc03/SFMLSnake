#include "snakeDirection.hpp"
#include "cell.hpp"

class snake
{
private:
    int size;
    SNAKEDIRECTION direction;
public:
    snake();
    int getSize();
    SNAKEDIRECTION getDirection();
    cell getHeadPosition();
};