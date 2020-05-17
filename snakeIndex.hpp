#include "snakeDirection.hpp"

class snakeIndex{
    private:
        int index;
        SNAKEDIRECTION direction;
    public:
        snakeIndex(int startIndex, SNAKEDIRECTION startDirection);
        int getIndex();
        void setIndex(int newIndex);
        SNAKEDIRECTION getDirection();
        void setDirection(SNAKEDIRECTION newDirection);
};