#include "snakeDirection.hpp"
#include "cell.hpp"
#include <memory>
#include <vector>

class snake
{
private:
    std::shared_ptr<std::vector<int>> snakeIndices = std::make_shared<std::vector<int>>();
    SNAKEDIRECTION direction;
public:
    snake(int headStartIndex);
    snake();
    std::shared_ptr<std::vector<int>> getSnakeIndices();
    SNAKEDIRECTION getDirection();
    void setDirection(SNAKEDIRECTION newDirection);
};