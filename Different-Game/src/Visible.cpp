/*
 * Visible.cpp
 *
 *  Created on: Feb 17, 2012
 *      Author: jesse
 */

#include "../include/Declarations.h"

/*
 * Abstract base class meant to let objects be seen on screen.
 */
class Visible
{
    public:
        //Used for drawing.
        Sprite& getSprite() const;

        //Sets the position of the sprite.
        void setPosition(const VectorFloat& newposition);

        //Gets the position of the sprite.
        VectorFloat getPosition() const;

    protected:
        //The underlying image file.  Cannot be directly displayed.
        ImageFile image;

        //The image that is actually visible to the user.  Its built-in
        //position vector is meant to be used as the object's position.
        Sprite sprite;
};
