/*
 * Block.h
 *
 *Solar Attack
 *  Created on: Feb 18, 2012
 *      Author: jesse
 */

#ifndef BLOCK_H_
#define BLOCK_H_

#include "Declarations.h"

class Block : public Clickable, public Movable, public Visible
{
    public:
        Block();
        virtual ~Block();
};

#endif /* BLOCK_H_ */
