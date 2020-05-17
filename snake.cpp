#include "snake.hpp"

snake::snake(int headStartIndex){
    snakeIndices->push_back(headStartIndex);
    direction = STILL;
}

SNAKEDIRECTION snake::getDirection(){
    return direction;
}

void snake::setDirection(SNAKEDIRECTION newDirection){
    direction = newDirection;
}

std::shared_ptr<std::vector<int>> snake::getSnakeIndices(){
    return snakeIndices;
}