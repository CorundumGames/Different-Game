#ifndef GAMEWINDOW_H_
#define GAMEWINDOW_H_

#include "Declarations.h"
#include <SFML/Graphics.hpp>
#include <string>

class GameWindow : public Screen
{
    public:
        GameWindow() : Screen(VideoMode(640, 480, 32), "France") {};
        void setScore(uint64 newscore);
        void increaseScore(uint64 scoretoadd);
        uint64 getScore() const;

        void takeScreenshot();
        void toggleFullScreen();

        friend class ScoreKeeper;

    private:
        bool isfullscreen;
        uint64 score;
};

#endif // GAMEWINDOW_H_