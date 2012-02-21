/*
 * Movable.cpp
 *
 *  Created on: Feb 18, 2012
 *      Author: jesse
 */

#include "../include/Declarations.h"
#include "../include/Movable.h"

//For acceleration in the class below.
const float ACCEL = 0.5;

const VectorFloat Movable::acceleration[4] = {
    VectorFloat(0, ACCEL), VectorFloat(ACCEL, 0),
    VectorFloat(0, -ACCEL), VectorFloat(-ACCEL, 0)
};


Movable::Movable()
{
    velocity = VectorFloat(0, 0);
}

VectorFloat Movable::getVelocity() const
{
    return velocity;
}

void Movable::setVelocity(const VectorFloat& newvelocity)
{
    velocity.x = newvelocity.x;
    velocity.y = newvelocity.y;
}

VectorFloat Movable::getAcceleration(Direction dir) const
{
    return acceleration[dir];
}