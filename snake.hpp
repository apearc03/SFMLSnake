#include "snakeDirection.hpp"

class snake
{
private:
    int size;
    SNAKEDIRECTION direction;
public:
    snake();
    int getSize();
    SNAKEDIRECTION getDirection();
};