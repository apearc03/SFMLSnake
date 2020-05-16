#include "snakeDirection.hpp"
#include "cell.hpp"
#include <memory>
#include <vector>

class snake
{
private:
    int size;
    int headVectorIndex; //possible change this to a vector that contains all snake indexes? 1st index is always the head.
    std::shared_ptr<std::vector<int>> snakeIndices = std::make_shared<std::vector<int>>();
    SNAKEDIRECTION direction;
public:
    snake(int headStartIndex);
    snake();
    int getSize();
    void setHeadVectorIndex(int newHeadIndex);
    int getHeadVectorIndex();
    std::shared_ptr<std::vector<int>> getSnakeIndices();
    SNAKEDIRECTION getDirection();
    void setDirection(SNAKEDIRECTION newDirection);
};