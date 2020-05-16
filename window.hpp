#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "board.hpp"
#include "snakeDirection.hpp"

const int windowWidth = 1000;
const int windowHeight = 1000; //config? Probably not, just set to reasonable values
const int cellSize = 100;
const int columnCount = windowHeight / cellSize; //used to calculate the next horizontal cell
const int rowCount = windowWidth / cellSize;
const int screenWidth = sf::VideoMode::getDesktopMode().width - windowWidth;
const int screenHeight = sf::VideoMode::getDesktopMode().height - windowHeight;
int topRow[rowCount];
int bottomRow[rowCount];
int leftCol[rowCount];
int rightCol[rowCount];

sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Snake");
board b = board(windowWidth, windowHeight, cellSize);