#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "board.hpp"
#include "snakeDirection.hpp"
#include <vector>
#include <string>

const int windowWidth = 900;
const int windowHeight = 900; //command line arguments to set width, height, cellsize and framerate.
const int cellSize = 90;
const int columnCount = windowHeight / cellSize; //used to calculate the next horizontal cell
const int rowCount = windowWidth / cellSize;
const int screenWidth = sf::VideoMode::getDesktopMode().width - windowWidth;
const int screenHeight = sf::VideoMode::getDesktopMode().height - windowHeight;
int topRow[rowCount];
int bottomRow[rowCount];
int leftCol[columnCount];
int rightCol[columnCount];
bool foodWasEaten = true;
bool gameOver = false;
bool drawScore = false;
sf::Font font;
sf::Text text;
sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Snake");
board b = board(windowWidth, windowHeight, cellSize);