/*
 * Entity.cpp
 *
 *  Created on: Feb 17, 2012
 *      Author: jesse
 */

#include "../include/Declarations.h"

/*
 * Used for the actual drawing.  Abstract base class.
 */
class Visible
{
    public:
        //Used for drawing.
        Sprite& getSprite() const;

        void setPosition(const VectorFloat& newposition);
        VectorFloat getPosition() const;

    protected:
        //The underlying image file.  Not meant to be displayed.
        ImageFile image;

        //The image that is actually visible to the user.
        Sprite sprite;

        //Position on the screen.
        VectorFloat position;


};
