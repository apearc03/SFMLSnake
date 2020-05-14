#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "board.hpp"

const int windowWidth = 1500;
const int windowHeight = 1000; //config? Probably not, just set to reasonable values
const int cellSize = 50;
const int columnCount = windowHeight / cellSize; //used to calculate the next horizontal cell
const int rowCount = windowWidth / cellSize;
const int screenWidth = sf::VideoMode::getDesktopMode().width - windowWidth;
const int screenHeight = sf::VideoMode::getDesktopMode().height - windowHeight;

sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML! we");
board b = board(windowWidth, windowHeight, cellSize);