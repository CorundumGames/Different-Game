/*
 * Clickable.cpp
 *
 *  Created on: Feb 18, 2012
 *      Author: jesse
 */

#include "../include/Declarations.h"
#include "../include/Clickable.h"

Clickable::Clickable()
{
    clickable = false;
}

void Clickable::setClickable(bool newclickable) { clickable = newclickable; }

bool Clickable::isClickable() const { return clickable; }