#include "snake.hpp"

snake::snake(int headStartIndex){
    size = 1;
    headVectorIndex = headStartIndex;
    direction = STILL;
}

snake::snake(){
    size = 1;
}

int snake::getSize(){
    return size;
}

SNAKEDIRECTION snake::getDirection(){
    return direction;
}

void snake::setDirection(SNAKEDIRECTION newDirection){
    direction = newDirection;
}

void snake::setHeadVectorIndex(int newHeadIndex){
    headVectorIndex = newHeadIndex;
}

int snake::getHeadVectorIndex(){
    return headVectorIndex;
}