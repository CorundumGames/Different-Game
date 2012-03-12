#ifndef VISIBLE_H_
#define VISIBLE_H_

#include "Declarations.h"

/*
 * Abstract base class meant to let objects be seen on screen.
 */
class Visible
{
    public:
        virtual ~Visible() {};

        //Used for drawing.
        Sprite& getSprite()
            { return sprite; }


        //Sets the position of the sprite.
        void setPosition(const PointFloat newpos)
            { sprite.SetPosition(newpos); }

        //Gets the position of the sprite.
        PointFloat getPosition() const
            { return sprite.GetPosition(); }

    protected:
        //Assigns an ImageFile to the sprite.
        void setSpriteImage(ImageFile& newimage)
            { sprite.SetImage(newimage); }

        //This way Visible can't be instantiated on its own.
        Visible() {};

    private:
        /*
         * ImageFiles must be owned by all derived objects, because they will
         * have different needs.  (e.g. some might want a static ImageFile,
         * others might not.)
         *
         * The image that is actually visible to the user.  Its built-in
         * position vector is meant to be used as the object's position.
         * Movable::move() should create a temporary vector that adds together
         * this sprite's position, Movable's velocity, and Movable's acceleration
         * THEN pass it to setPosition().
         */
        Sprite sprite;


};

#endif // VISIBLE_H_
