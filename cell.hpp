#pragma once
#include <SFML/Graphics.hpp>
#include "celltype.hpp"

class cell
{
private:
    sf::VertexArray quad;
    CELLTYPE state;
    void setCellColour(sf::Color colour);

public:
    cell(sf::Vector2f topLeft, sf::Vector2f topRight, sf::Vector2f bottomRight, sf::Vector2f bottomLeft);
    void setCellState(CELLTYPE cellType);
    CELLTYPE getCellState();
    sf::VertexArray getQuad();
};