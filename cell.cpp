#include "cell.hpp"
#include "iostream"

cell::cell(sf::Vector2f topLeft, sf::Vector2f topRight, sf::Vector2f bottomRight, sf::Vector2f bottomLeft)
{
    quad = sf::VertexArray(sf::Quads, 4);
    quad[0].position = topLeft;
    quad[1].position = topRight;
    quad[2].position = bottomRight;
    quad[3].position = bottomLeft;
    setCellState(EMPTY);
}

//only call this if the cell state actually needs to change
void cell::setCellState(CELLTYPE cellType)
{
    state = cellType;
    switch (cellType)
    {
    case EMPTY:
        setCellColour(sf::Color::Blue);
        break;
    case SNAKE_HEAD:
        setCellColour(sf::Color::Red);
        break;
    case SNAKE_BODY:
        setCellColour(sf::Color::Green);
        break;
    case FOOD:
        setCellColour(sf::Color::Black);
        break;
    }
}

void cell::setCellColour(sf::Color colour)
{
    for (int i = 0; i < 4; i++)
    {
        quad[i].color = colour;
    }
}

CELLTYPE cell::getCellState(){
    return state;
}

sf::VertexArray cell::getQuad()
{
    return quad;
};

sf::Vector2f cell::getTopL()
{
    return topL;
}
sf::Vector2f cell::getTopR()
{
    return topR;
}
sf::Vector2f cell::getBotR()
{
    return botR;
}
sf::Vector2f cell::getBotL()
{
    return botL;
}