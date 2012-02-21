#include "include/Declarations.h"
#include "include/GravityGrid.h"
#include "include/GameWindow.h"

GameWindow Game;

int main()
{
    Event event;
    Game.Clear();
    GravityGrid<Block> france(VectorInt(8, 8), VectorFloat(64, 64),
                              VectorFloat(0, 0));
    while (Game.IsOpened()) {
        while (Game.GetEvent(event)) {
            if (event.Type == sf::Event::Closed) Game.Close();
        }




        Game.Display();
    }

    //TODO: Get a GravityGrid visible
    //TODO: Have a Grid fill itself with blocks
    //TODO: Implement a GameState, and derive more states from it
}
