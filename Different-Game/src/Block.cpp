/*
 * Block.cpp
 *
 *  Created on: Feb 18, 2012
 *      Author: jesse
 */

#include "../include/Declarations.h"
#include "../include/Block.h"

ImageFile Block::image;

Block::Block(const Color newcolor, const VectorInt newgridposition)
{
    color = Color(newcolor.r, newcolor.g, newcolor.b, newcolor.a);
    gridposition = VectorInt(newgridposition.x, newgridposition.y);
    sprite.SetImage(image);
}

Block::~Block()
{

}

void Block::initialize(const Color newcolor, const VectorInt newgridposition)
{
    color = Color(newcolor.r, newcolor.g, newcolor.b, newcolor.a);
    gridposition = VectorInt(newgridposition.x, newgridposition.y);
    sprite.SetImage(image);
}



void Block::handleInput(const InputHandler& input)
{

}

void Block::move()
{

}
