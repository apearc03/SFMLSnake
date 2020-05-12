#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream> //for testing with cout

int main()
{
    //constants
    const int windowWidth = 1366;
    const int windowHeight = 768; //config?
    const int screenWidth = sf::VideoMode::getDesktopMode().width - windowWidth;
    const int screenHeight = sf::VideoMode::getDesktopMode().height - windowHeight;

    //setup window
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML! we");
    window.setPosition(sf::Vector2i(screenWidth / 2, screenHeight / 2));
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    sf::CircleShape shape(200.f);
    shape.setFillColor(sf::Color::Green);

    sf::Vertex vertex(sf::Vector2f(10.f, 50.f), sf::Color::Red, sf::Vector2f(100.f, 100.f));

    sf::VertexArray line(sf::Lines, 2);
    line[0].position = sf::Vector2f(10.f, 100.f);
    line[1].position = sf::Vector2f(10.f, 200.f);

    line[0].color = sf::Color::Yellow;
    line[1].color = sf::Color::Yellow;
    //vertex.position = sf::Vector2f(10, 50);
    //vertex.color = sf::Color::Red;
    //vertex.texCoords = sf::Vector2f(100, 100);
    sf::VertexArray quad(sf::Quads, 4);

    // define it as a rectangle, located at (10, 10) and with size 100x100
    quad[0].position = sf::Vector2f(500.f, 10.f);
    quad[1].position = sf::Vector2f(600.f, 10.f);
    quad[2].position = sf::Vector2f(600.f, 100.f);
    quad[3].position = sf::Vector2f(500.f, 100.f);

    // define its texture area to be a 25x50 rectangle starting at (0, 0)
    quad[0].texCoords = sf::Vector2f(0.f, 0.f);
    quad[1].texCoords = sf::Vector2f(25.f, 0.f);
    quad[2].texCoords = sf::Vector2f(25.f, 50.f);
    quad[3].texCoords = sf::Vector2f(0.f, 50.f);

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
        window.draw(&vertex, 1, sf::Points);
        window.draw(line);
        window.draw(quad);
        window.display();
    }

    return 0;
}