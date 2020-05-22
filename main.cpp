#include "game.hpp"
#include <iostream>
#include <string>
#include <regex>

int main(int argc, char *argv[])
{
    const char *programInfo = 
    "SFML Snake by Alex Pearce\n"
    "Program must be run with all arguments or none at all and defaults are applied.\n"

    "Usage: ./sfmlSnake [windowWidth] [windowHeight] [cellSize] [frameRate]\n"
    "windowWidth: Any integer\n"
    "windowHeight: Any integer\n"
    "cellSize: An integer that must be a factor of both windowWidth and windowHeight\n"
    "frameRate: An integer that must be between 10 and 60, inclusive of both.\n"

    "Default values are 1000, 800, 50, 15 which are applied when no arguments are specified.\n"
    "Your score is shown after each round ends.\n";
    if (argc == 1)
    {
        game g(1000, 800, 50, 15);
        g.start();
        return 0;
    }
    std::string argOne = std::string(argv[1]);
    if (argOne.find("help") != std::string::npos || argOne == "-h")
    {
        std::cout << programInfo;
        return 0;
    }
    if (argc != 5)
    {
        std::cout << "Incorrect number of arguments, use the -help flag for more information\n";
        return 0;
    }
    std::regex e("^-?\\d+");
    std::string argTwo = std::string(argv[2]);
    std::string argThree = std::string(argv[3]);
    std::string argFour = std::string(argv[4]);
    if (std::regex_match(argOne, e) && std::regex_match(argTwo, e) && std::regex_match(argThree, e) && std::regex_match(argFour, e))
    {
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
            std::cout << "width and height must be multiples of cellSize and framerate must be between 10 and 60, inclusive, use the -help flag for more information\n";
            return 0;
        }
    }
    else
    {
        std::cout << "All arguments must be valid integers, use the -help flag for more information\n";
        return 0;
    }
}