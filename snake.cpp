#include "snake.hpp"

snake::snake(int headStartIndex){
    snakeIndices->push_back(std::make_shared<snakeIndex>(headStartIndex, STILL));
}

std::shared_ptr<std::vector<std::shared_ptr<snakeIndex>>> snake::getSnakeIndices(){
    return snakeIndices;
}

void snake::growSnake(int index, SNAKEDIRECTION direction){
    snakeIndices->push_back(std::make_shared<snakeIndex>(index, direction));
    //direction passed in will the same as the previous last index. can determine index from that.
}

std::shared_ptr<snakeIndex> snake::getHeadIndex(){
    return snakeIndices->at(0);
}