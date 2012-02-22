/*
 * Block.cpp
 *
 *  Created on: Feb 18, 2012
 *      Author: jesse
 */

#include "../include/Declarations.h"
#include "../include/Block.h"

ImageFile Block::image;

Block::Block(const Color& newcolor, const VectorInt& newgridposition)
{
    color = newcolor;
    gridposition = newgridposition;
    image.LoadFromFile("../gfx/block.png");
    sprite.SetImage(image);
}

Block::~Block()
{

}

void Block::initialize(const Color& newcolor, const VectorInt& newgridposition)
{
    color = newcolor;
    gridposition = newgridposition;
    image.LoadFromFile("../gfx/block.png");
    sprite.SetImage(image);
}

void Block::handleInput(const InputHandler& input)
{

}

void Block::move()
{

}
