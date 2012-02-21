/*
 * Visible.cpp
 *
 *  Created on: Feb 17, 2012
 *      Author: jesse
 */

#include "../include/Declarations.h"
#include "../include/Visible.h"

Sprite& Visible::getSprite()
{
    return sprite;
}

void Visible::setPosition(const VectorFloat& newposition)
{
    sprite.SetPosition(newposition);
}

VectorFloat Visible::getPosition() const
{
    return sprite.GetPosition();
}