/*
 * Movable.cpp
 *
 *  Created on: Feb 18, 2012
 *      Author: jesse
 */

#include "../include/Declarations.h"

//For acceleration in the class below.
const float ACCEL = 0.5;

/*
 * Abstract base class to give objects movement functionality.
 */
class Movable
{
    public:
        Movable();
        virtual ~Movable();
        void move() = 0;

    protected:
        //For movement and rotation.
        Matrix2D matrix;

        //matrix is translated by this during movement.
        VectorFloat velocity;

        /*
         * Remember, enum Direction order is SOUTH, EAST, NORTH, WEST.
         * Acceleration is not meant to change.  Meant to be accessed by enum.
         */
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
