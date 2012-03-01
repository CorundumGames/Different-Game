/*
 * Block.cpp
 *
 *  Created on: Feb 18, 2012
 *      Author: jesse
 */

#include "../include/Declarations.h"
#include "../include/Grid.h"
#include "../include/Block.h"
#include <iostream>
#include <chrono>


ImageFile Block::image;
Direction Block::down;
std::shared_ptr<Grid<Block>> Block::container;
std::map<AvailableColor, Color> Block::colors;



Block::Block(const Color newcolor, const VectorInt newgridposition)
{
    gridposition = newgridposition;
    getSprite().SetImage(image);
    getSprite().SetColor(newcolor);
    getSprite().SetPosition(container->getLocation().x +
                                gridposition.x*(container->getCellSize().x),
                            container->getLocation().y +
                                gridposition.y*(container->getCellSize().y));
}

Block::~Block()
{

}

VectorFloat Block::getImageDims()
{
    return VectorFloat(image.GetWidth(), image.GetHeight());
}

void Block::handleInput(const InputHandler& input)
{

}

void Block::move()
{

}

void Block::loadImage(std::string filename)
{
    image.LoadFromFile(filename);
}

void Block::initContainer(Grid<Block>* newcontainer)
{
    container = std::shared_ptr<Grid<Block>>(newcontainer);
}

void Block::initMap()
{
    colors.insert(ColorPair(AvailableColor::RED, Color::Red));
    colors.insert(ColorPair(AvailableColor::BLUE, Color::Blue));
    colors.insert(ColorPair(AvailableColor::GREEN, Color::Green));
    colors.insert(ColorPair(AvailableColor::YELLOW, Color::Yellow));
    colors.insert(ColorPair(AvailableColor::CYAN, Color::Cyan));
    colors.insert(ColorPair(AvailableColor::PURPLE, Color::Magenta));
    colors.insert(ColorPair(AvailableColor::WHITE, Color::White));
}

Color Block::getRandomColor(int max_colors)
{
    //We don't want to load a color that doesn't exist!
    try {
        if (max_colors > 7 || max_colors < 4) throw;
    }
    catch (...) {
        std::cerr << "Invalid block value given!  " << max_colors << std::endl;
        exit(1);
    }


    RandomNumber rand;
    rand.SetSeed(time.now().time_since_epoch());
    return colors[AvailableColor(rand.Random(0, max_colors))];
}
