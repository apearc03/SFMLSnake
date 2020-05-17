#include "snakeDirection.hpp"
#include "cell.hpp"
#include "snakeIndex.hpp"
#include <memory>
#include <vector>

class snake
{
private:
    std::shared_ptr<std::vector<std::shared_ptr<snakeIndex>>> snakeIndices = std::make_shared<std::vector<std::shared_ptr<snakeIndex>>>();
public:
    snake(int headStartIndex);
    snake();
    std::shared_ptr<std::vector<std::shared_ptr<snakeIndex>>> getSnakeIndices();
    std::shared_ptr<snakeIndex> getHeadIndex();
    void growSnake(int index, SNAKEDIRECTION direction);
};