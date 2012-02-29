#include "include/Declarations.h"
#include "include/GameWindow.h"
#include "include/Block.h"
#include "include/Grid.h"

GameWindow Game;

int main()
{
    Block::loadImage("./gfx/block.png");

    Event event;
    Game.Clear(Color(50, 50, 100));
    Grid<Block> france(VectorInt(8, 8),
                       Block::getImageDims(),
                       VectorFloat(0, 0));

    Block::initContainer(&france);


    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            VectorInt temp(i, j);

            france.set(Block(Color::White, temp), temp);
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

