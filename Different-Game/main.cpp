#include "include/Declarations.h"
#include "include/GameWindow.h"
#include "include/Block.h"
#include "include/Grid.h"

GameWindow Game;

int main()
{
    Block::loadImage("./gfx/block.png");
    Block::initMap();
    Event event;
    Game.Clear(Color(50, 50, 100));
    Grid<Block> france(VectorInt(8, 8),
                       Block::getImageDims(),
                       VectorFloat(224, 48));

    france.setCellSize(VectorFloat(48, 48));

    Block::initContainer(&france);


    for (int i = 0; i < france.getDimensions().x; ++i) {
        for (int j = 0; j < france.getDimensions().y; ++j) {
            VectorInt temp(i, j);
            france.set(Block(Block::getRandomColor(7), temp), temp);
        }
    }




    while (Game.IsOpened()) {
        while (Game.GetEvent(event)) {
            if (event.Type == sf::Event::Closed) Game.Close();
        }
        Game.Clear(Color(50, 50, 100));

        for (int i = 0; i < france.getDimensions().x; ++i)
            for (int j = 0; j < france.getDimensions().y; ++j)
                Game.Draw(france.get(VectorInt(i, j)).getSprite());

        Game.Display();
    }

    //TODO: Get a GravityGrid visible
}

