/*
 * Block.cpp
 *
 *  Created on: Feb 18, 2012
 *      Author: jesse
 */

#include <memory>
#include "../include/Declarations.h"
#include "../include/Grid.h"
#include "../include/Block.h"

ImageFile Block::image;
Direction Block::down;
std::shared_ptr<Grid<Block>> Block::container;

Block::Block(const Color newcolor, const VectorInt newgridposition)
{
    color = newcolor;
    gridposition = newgridposition;
    getSprite().SetImage(image);
    getSprite().SetPosition(gridposition.x*(container->getCellSize().x),
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
