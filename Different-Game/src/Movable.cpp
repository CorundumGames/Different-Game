/*
 * Movable.cpp
 *
 *  Created on: Feb 18, 2012
 *      Author: jesse
 */

#include "../include/Declarations.h"
#include "../include/Movable.h"

//For acceleration in the array below.  Death to magic numbers!  ///////////////
static const float ACCEL = 0.5;
////////////////////////////////////////////////////////////////////////////////

//Because I apparently have to define static members in a .cpp file.  Lame.
const VectorFloat Movable::acceleration[4] = {
        VectorFloat(0, ACCEL),  //SOUTH
        VectorFloat(ACCEL, 0),  //EAST
        VectorFloat(0, -ACCEL), //NORTH
        VectorFloat(-ACCEL, 0)  //WEST
};
