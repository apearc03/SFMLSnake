#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream> //for testing with cout
#include "board.hpp"

int main()
{
    //constants
    const int windowWidth = 1000;
    const int windowHeight = 1000; //config?
    const int cellSize = 50;
    const int screenWidth = sf::VideoMode::getDesktopMode().width - windowWidth;
    const int screenHeight = sf::VideoMode::getDesktopMode().height - windowHeight;

    //setup window
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML! we");
    window.setPosition(sf::Vector2i(screenWidth / 2, screenHeight / 2));
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    board b = board(windowWidth, windowHeight, cellSize);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        //window.draw(shape);
        //window.draw(quad);
        //need a way to keep track of head of snake
        for(int i = 0; i < b.getCells().size(); i++){
           window.draw(b.getCells().at(i).getQuad());
        }
        window.display();
        //if cell not empty, draw it?
    }

    return 0;
}