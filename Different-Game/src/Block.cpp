/*
 * Block.cpp
 *
 *  Created on: Feb 18, 2012
 *      Author: jesse
 */

#include "../include/Declarations.h"
#include "../include/Block.h"

ImageFile Block::image;
Direction block::down;

Block::Block(const Color newcolor, const VectorInt newgridposition)
{
    initialize(newcolor, newgridposition);
}

Block::~Block()
{

}

void Block::initialize(const Color newcolor, const VectorInt newgridposition)
{
    color = newcolor;
    gridposition = newgridposition;
    getSprite().SetImage(image);
}

void Block::handleInput(const InputHandler& input)
{

}

void Block::move()
{

}
