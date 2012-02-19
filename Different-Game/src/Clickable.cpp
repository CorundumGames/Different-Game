/*
 * Clickable.cpp
 *
 *  Created on: Feb 18, 2012
 *      Author: jesse
 */

#include "../include/Declarations.h"

/*
 * Abstract base class meant to give input-handling functionality.
 */
class Clickable
{
    public:
        Clickable();
        virtual ~Clickable();

        virtual void handleInput(const InputHandler& input) = 0;
        void setClickable(bool newclickable);
        bool isClickable() const;
    protected:
        bool clickable;
    private:
};
