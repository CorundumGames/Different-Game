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

Block::Block(const Color newcolor,
             const VectorInt newgridposition,
             Grid<Block>* newcontainer)
{
    color = newcolor;
    gridposition = newgridposition;
    container = std::shared_ptr<Grid<Block>>(newcontainer);
    getSprite().SetImage(image);
    getSprite().SetPosition(gridposition*(container->getCellSize().x),
                            gridposition*(container->getCellSize().y));
}

Block::~Block()
{

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
