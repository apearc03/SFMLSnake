#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "board.hpp"

const int windowWidth = 1000;
const int windowHeight = 1000; //config?
const int cellSize = 50;
const int columnDifference = windowHeight / cellSize; //used to calculate the next horizontal cell
const int screenWidth = sf::VideoMode::getDesktopMode().width - windowWidth;
const int screenHeight = sf::VideoMode::getDesktopMode().height - windowHeight;

sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML! we");
board b = board(windowWidth, windowHeight, cellSize);