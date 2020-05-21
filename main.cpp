#include "game.hpp"

int main(){
    //command line arguments to set width, height, cellsize and framerate.
    //has to be less than both width and height and be a factor of both. Frame rate should be any number between 10 - 60.
    game g(1000, 1000, 100);
    g.start();    
}