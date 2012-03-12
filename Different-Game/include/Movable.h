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
        Movable()
            { velocity = std::move(VectorFloat(0, 0)); }

        virtual void move() = 0;

        //Get/setters
        VectorFloat getVelocity() const
            { return velocity; }
        void setVelocity(const VectorFloat newvel)
            { velocity = newvel; }

    protected:
        //Acceleration due to gravity will be constant, as it is in real life.
        VectorFloat getAcceleration(const Direction dir) const
            { return acceleration[int(dir)]; }
    private:
        //Position, held by the sprite, is translated by this during movement.
        VectorFloat velocity;

         //Remember, enum Direction order is SOUTH, EAST, NORTH, WEST.
         //Acceleration is not meant to change. Should be accessed by enum.
        static const VectorFloat acceleration[4];
};

#endif // MOVABLE_H_
