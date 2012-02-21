#ifndef MOVABLE_H_
#define MOVABLE_H_

#include "Declarations.h"

/*
 * Abstract base class to give objects movement functionality.
 * Should not have anything on its own that lets it be seen or clicked.
 */
class Movable
{
    public:
        Movable();
        virtual void move() = 0;

        VectorFloat getVelocity() const;
        void setVelocity(const VectorFloat& newvelocity);

        VectorFloat getAcceleration(Direction dir) const;
    protected:
        //For movement and rotation.
        Matrix2D matrix;

        //matrix is translated by this during movement.
        VectorFloat velocity;

        /*
         * Remember, enum Direction order is SOUTH, EAST, NORTH, WEST.
         * Acceleration is not meant to change.  Meant to be accessed by enum.
         */
        static const VectorFloat acceleration[4];
};

#endif // MOVABLE_H_