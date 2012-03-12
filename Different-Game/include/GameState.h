#ifndef GAMESTATE_H
#define GAMESTATE_H


class GameState
{
    public:
        GameState() = 0;
        virtual ~GameState() = 0;
        virtual void input() = 0;
        virtual void logic() = 0;
        virtual void render() = 0;
    protected:
    private:
};

#endif // GAMESTATE_H
