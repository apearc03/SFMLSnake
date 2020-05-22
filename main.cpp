#include "game.hpp"
#include <iostream>
#include <string>
#include <regex>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        game g(1000, 1000, 100, 10);
        g.start();
        return 0;
    }
    std::string argOne = std::string(argv[1]);
    if (argOne.find("help") != std::string::npos || argOne == "-h")
    {
        std::cout << "help found";
        //echo argument info and controls. Score printed after game over or the player wins. Defaults with no arguments.
        return 0;
    }
    if (argc != 5)
    {
        //incorrect number of arguments.
        return 0;
    }
    std::regex e("^-?\\d+");
    std::string argTwo = std::string(argv[2]);
    std::string argThree = std::string(argv[3]);
    std::string argFour = std::string(argv[4]);
    if (std::regex_match(argOne, e) && std::regex_match(argTwo, e) && std::regex_match(argThree, e) && std::regex_match(argFour, e))
    {
        std::cout << "all numbers";
        //check width and height are multiples and frame rate is between 10 and 60. Inclusive.
        int width = std::stoi(argOne);
        int height = std::stoi(argTwo);
        int cellSize = std::stoi(argThree);
        int frameRate = std::stoi(argFour);
        if (width % cellSize == 0 && height % cellSize == 0 && frameRate >= 10 && frameRate <= 60)
        {
            game g(width, height, cellSize, frameRate);
            g.start();
            return 0;
        }
        else
        {
            //print that width and height must be multiples of cellSize and framerate must be between 10 and 60.
            return 0;
        }
    }
    else
    {
        //print that all arguments must be numbers.
        return 0;
    }
}