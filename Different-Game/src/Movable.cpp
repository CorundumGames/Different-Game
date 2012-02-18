/*
 * Movable.cpp
 *
 *  Created on: Feb 18, 2012
 *      Author: jesse
 */

#include "../include/Declarations.h"

//For acceleration in the class below.
const float ACCEL = 4.5;

class Movable
{
    public:
        Movable();
        virtual ~Movable();

    protected:
        //For movement and rotation.
        Matrix2D matrix;

        //matrix is translated by this during movement.
        VectorFloat velocity;

        //Remember, enum Direction order is SOUTH, EAST, NORTH, WEST
        //acceleration is not meant to change.
        static const VectorFloat acceleration[4] = {
                VectorFloat(0, ACCEL), VectorFloat(ACCEL, 0),
                VectorFloat(0, -ACCEL), VectorFloat(-ACCEL, 0)
        };



};

Movable::Movable()
{
    // TODO Auto-generated constructor stub

}

Movable::~Movable()
{
    // TODO Auto-generated destructor stub
}
