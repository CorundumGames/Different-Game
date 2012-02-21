#ifndef VISIBLE_H_
#define VISIBLE_H_

#include "Declarations.h"

/*
 * Abstract base class meant to let objects be seen on screen.
 */
class Visible
{
    public:
        //Used for drawing.
        Sprite& getSprite();

        //Sets the position of the sprite.
        void setPosition(const VectorFloat& newposition);

        //Gets the position of the sprite.
        VectorFloat getPosition() const;

    protected:
        ImageFile image;
        //TODO: Decide how to go about inheriting position
        //Static can be overwritten, right?

        //The image that is actually visible to the user.  Its built-in
        //position vector is meant to be used as the object's position.
        Sprite sprite;
};

#endif // VISIBLE_H_
