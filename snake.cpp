#include "snake.hpp"

snake::snake(){
    size = 1;
}

int snake::getSize(){
    return size;
}

SNAKEDIRECTION snake::getDirection(){
    return direction;
}
