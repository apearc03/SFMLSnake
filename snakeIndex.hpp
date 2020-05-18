#include "snakeDirection.hpp"

class snakeIndex{
    private:
        int index;
    public:
        snakeIndex(int startIndex);
        int getIndex();
        void setIndex(int newIndex);
};