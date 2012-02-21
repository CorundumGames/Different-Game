#include "include/Declarations.h"
#include "include/GravityGrid.h"
#include "include/GameWindow.h"
#include "include/Block.h"

GameWindow Game;

int main()
{
    Event event;
    Game.Clear(Color(50, 50, 100));
    GravityGrid<Block> france(VectorInt(8, 8), VectorFloat(64, 64),
                              VectorFloat(0, 0));
    france.resetGrid(france.getDimensions());
    Game.Draw(france.get(VectorInt(0, 0)).getSprite());


    while (Game.IsOpened()) {
        while (Game.GetEvent(event)) {
            if (event.Type == sf::Event::Closed) Game.Close();
        }




        Game.Display();
    }

    //TODO: Get a GravityGrid visible
}
