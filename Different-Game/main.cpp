#include "include/Declarations.h"
#include "include/Grid.h"
#include <iostream>

sf::RenderWindow Game(sf::VideoMode(640, 480, 32), "France");

int main()
{
    Grid<int> france;
    Game.Clear();
    while (true)
        Game.Display();
}
