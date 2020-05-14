#include "snakeDirection.hpp"
#include "cell.hpp"
#include <memory>

class snake
{
private:
    int size;
    int headVectorIndex;
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