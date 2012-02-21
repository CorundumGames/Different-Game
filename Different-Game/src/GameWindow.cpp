/*
 * GameWindo.cpp
 *
 *  Created on: Feb 18, 2012
 *      Author: jesse
 */

#include "../include/Declarations.h"
#include "../include/GameWindow.h"

void GameWindow::setScore(uint64 newscore)
{
    score = newscore;
}

void GameWindow::increaseScore(uint64 newscore)
{
    score += newscore;
}

uint64 GameWindow::getScore() const
{
    return score;
}

void GameWindow::takeScreenshot()
{
    //TODO: Implement screenshot functionality; can it be const?
}

void GameWindow::toggleFullScreen()
{
    
}