#include "include/Declarations.h"
#include "include/GameWindow.h"
#include "include/Block.h"
#include "include/Grid.h"
#include <iostream>

GameWindow Game;

const int GRID_DIMS = 32;  //Grid's dimensions
const int BLOCK_DIMS = Block::computeBlockDims(GRID_DIMS);  //Block's dimensions

int main()
{
    Block::loadImage("./gfx/block.png");
    Block::initMap();
    Event event;
    Game.Clear(Color(50, 50, 100));
    Grid<Block> france(VectorInt(GRID_DIMS, GRID_DIMS),
                       Block::getImageDims(),
                       PointFloat(224, 48));

    france.setCellSize(VectorFloat(BLOCK_DIMS, BLOCK_DIMS));

    Block::initContainer(&france);


    for (int i = 0; i < france.getDimensions().x; ++i) {
        for (int j = 0; j < france.getDimensions().y; ++j) {
            PointInt temp(i, j);
            france.set(Block(Block::getRandomColor(7), temp), temp);

        }
    }

    for (int i = 0; i < france.getDimensions().x; ++i)
        for (int j = 0; j < france.getDimensions().y; ++j)
            Game.Draw(france.get(PointInt(i, j)).getSprite());


    while (Game.IsOpened()) {
        while (Game.GetEvent(event)) {
            if (event.Type == sf::Event::Closed) Game.Close();
        }
        Game.Clear(Color(50, 50, 100));

        for (int i = 0; i < france.getDimensions().x; ++i) {
            for (int j = 0; j < france.getDimensions().y; ++j) {

                if (Game.GetInput().IsMouseButtonDown(sf::Mouse::Button::Left))
                france.get(PointInt(i, j)).handleInput(Game.GetInput());
                Game.Draw(france.get(PointInt(i, j)).getSprite());
            }
        }

        Game.Display();
    }

    //TODO: Begin the main game loop
}

