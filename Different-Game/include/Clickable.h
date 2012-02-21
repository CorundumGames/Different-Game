#ifndef CLICKABLE_H_
#define CLICKABLE_H_

#include "Declarations.h"

/*
 * Abstract base class meant to give input-handling functionality.
 * Should not have anything on its own that lets it move or be seen.
 */
class Clickable
{
    public:
        Clickable();
        virtual void handleInput(const InputHandler& input) = 0;

        void setClickable(bool newclickable);
        bool isClickable() const;

    protected:
        bool clickable;
};

#endif //CLICKABLE_H_