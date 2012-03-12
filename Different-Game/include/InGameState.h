#ifndef INGAMESTATE_H
#define INGAMESTATE_H

#include "GameState.h"


class InGameState : public GameState
{
    public:
        InGameState();
        virtual ~InGameState();
        void input();
        void logic();
        void render();
    protected:
    private:

};

#endif // INGAMESTATE_H
