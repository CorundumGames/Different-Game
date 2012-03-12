#ifndef GAMEWINDOW_H_
#define GAMEWINDOW_H_

#include <ctime>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "Declarations.h"

constexpr int FULL = sf::Style::Fullscreen;
constexpr int WINDOW = sf::Style::Titlebar|sf::Style::Close;
const char* TITLE = "Different Game";

class GameWindow : public Screen
{
    public:
        //Ugly hack, I need to overload this later.
        GameWindow() : Screen(VideoMode(640, 480, 32), TITLE, WINDOW)
            { fullscreen = false; score = 0;}

        //Get/setters, with special guest Increaser.
        void setScore(const uint64_t newscore)
            { score = newscore; }

        void increaseScore(const uint64_t scoretoadd)
            { score += scoretoadd; }

        uint64_t getScore() const
            { return score; }

        //Saves the current screen to a file.
        void takeScreenshot() const
        {
            std::ostringstream temp;
            temp << "screen" << time << ".png";
            Capture().SaveToFile(temp.str());
        }

        //Turns fullscreen on or off.
        void toggleFullScreen()
        {
            fullscreen = !fullscreen;
            Create(VideoMode(640, 480, 32), TITLE, fullscreen ? FULL : WINDOW);
        }

    private:
        bool fullscreen;
        uint64_t score;
};

#endif // GAMEWINDOW_H_
