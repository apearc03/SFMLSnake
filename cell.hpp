#include <SFML/Graphics.hpp>
#include "celltype.hpp"

class cell
{
private:
    sf::VertexArray quad;
    CELLTYPE state;
public:
    cell(sf::Vector2f topLeft, sf::Vector2f topRight, sf::Vector2f bottomRight, sf::Vector2f bottomLeft);
    void setCellState(CELLTYPE);
    CELLTYPE getCellState();
};