#include "snake.hpp"

snake::snake(int headStartIndex){
    snakeIndices->push_back(std::make_shared<snakeIndex>(headStartIndex, STILL));
}

std::shared_ptr<std::vector<std::shared_ptr<snakeIndex>>> snake::getSnakeIndices(){
    return snakeIndices;
}

void snake::growSnake(){
    //find the last index in the snake.
    //direction wont be the same as the head either.
    //each index needs a direction?
}

std::shared_ptr<snakeIndex> snake::getHeadIndex(){
    return snakeIndices->at(0);
}