#include "snakeDirection.hpp"
#include "cell.hpp"
#include <memory>

class snake
{
private:
    int size;
    int headVectorIndex; //possible change this to a vector that contains all snake indexes? 1st index is always the head.
    SNAKEDIRECTION direction;
public:
    snake(int headStartIndex);
    snake();
    int getSize();
    void setHeadVectorIndex(int newHeadIndex);
    int getHeadVectorIndex();
    SNAKEDIRECTION getDirection();
    void setDirection(SNAKEDIRECTION newDirection);
};