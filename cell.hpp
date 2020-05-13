#pragma once
#include <SFML/Graphics.hpp>
#include "celltype.hpp"

class cell
{
private:
    sf::VertexArray quad;
    CELLTYPE state;
    sf::Vector2f topL; //possibly remove these if unused
    sf::Vector2f topR;
    sf::Vector2f botR;
    sf::Vector2f botL;
    void setCellColour(sf::Color colour);

public:
    cell(sf::Vector2f topLeft, sf::Vector2f topRight, sf::Vector2f bottomRight, sf::Vector2f bottomLeft);
    void setCellState(CELLTYPE cellType);
    CELLTYPE getCellState();
    sf::VertexArray getQuad();
    sf::Vector2f getTopL();
    sf::Vector2f getTopR();
    sf::Vector2f getBotR();
    sf::Vector2f getBotL();
};