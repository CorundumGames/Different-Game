/*
 * Block.cpp
 *
 *  Created on: Feb 18, 2012
 *      Author: jesse
 */

#include "../include/Declarations.h"
#include "../include/Block.h"


Block::Block(Color newcolor, VectorInt newgridposition)
{
    color = newcolor;
    gridposition = newgridposition;
}

Block::~Block()
{

}
