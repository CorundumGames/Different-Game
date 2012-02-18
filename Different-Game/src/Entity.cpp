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
class Entity 
{
public:
	Image* getSprite();
	void setPosition(VectorInt new_position);
	VectorInt getPosition();
protected:
	ImageFile image;
	Image sprite;
	VectorInt position;
	Matrix2D transformation;
};
