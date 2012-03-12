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
#include <ctime>
#include <cmath>
#include <stdexcept>


ImageFile Block::image;
Direction Block::down;
Grid<Block>* Block::container;
std::map<AvailableColor, Color> Block::colors;
uint64_t Block::generated_numbers;



Block::Block(const Color& newcolor, const PointInt& newgridposition)
{
    gridposition = newgridposition;
    getSprite().SetImage(image);
    getSprite().SetColor(newcolor);
    getSprite().SetPosition(container->getLocation().x +
                                gridposition.x*(container->getCellSize().x),
                            container->getLocation().y +
                                gridposition.y*(container->getCellSize().y));

    getSprite().SetScale(1.0/(getImageDims().x/container->getCellSize().x),
                         1.0/(getImageDims().y/container->getCellSize().y));
    area = getArea();
}

Block::~Block()
{

}

VectorFloat Block::getImageDims()
{
    return VectorFloat(image.GetWidth(), image.GetHeight());
}

RectInt Block::getArea()
{
    return RectInt(int(getSprite().GetPosition().x),
                   int(getSprite().GetPosition().y),
                   int(getSprite().GetPosition().x + getSprite().GetSize().x),
                   int(getSprite().GetPosition().y + getSprite().GetSize().y)
                   );
}

void Block::handleInput(const InputHandler& input)
{

        if (area.Contains(input.GetMouseX(), input.GetMouseY()))
        std::cout << "Clicked Block at (" << gridposition.x
                  << ", " << gridposition.y << ")\n";
}

void Block::move()
{

}

void Block::loadImage(std::string filename)
{
    if (!image.LoadFromFile(filename))
        throw std::runtime_error("Block image could not be loaded!");
}

void Block::initContainer(Grid<Block>* newcontainer)
{
    container = newcontainer;
}

void Block::initMap()
{
    generated_numbers = 0;
    colors.insert(ColorPair(AvailableColor::RED, Color::Red));
    colors.insert(ColorPair(AvailableColor::BLUE, Color::Blue));
    colors.insert(ColorPair(AvailableColor::GREEN, Color::Green));
    colors.insert(ColorPair(AvailableColor::YELLOW, Color::Yellow));
    colors.insert(ColorPair(AvailableColor::CYAN, Color::Cyan));
    colors.insert(ColorPair(AvailableColor::PURPLE, Color::Magenta));
    colors.insert(ColorPair(AvailableColor::WHITE, Color::White));
}

Color& Block::getRandomColor(const int max_colors)
{
    if (max_colors > 7 || max_colors < 4)
        throw std::out_of_range("Invalid block value of " + max_colors);

    RandomNumber rand;
    rand.SetSeed(time(NULL)* ++generated_numbers);
    return colors[AvailableColor(rand.Random(0, max_colors - 1))];
}

float Block::computeBlockDims(const int x)
{
    //I got this formula with my graphing calculator and Wolfram Alpha.
    if (x % 8 != 0 || x > 32)
        throw std::invalid_argument("Grid size is not between divisible by 8!");

    return (-pow(x, 3)/256)+(.3125*pow(x, 2))-(8.75*x)+100;
}
