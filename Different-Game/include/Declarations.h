/*
 * Declarations.h
 *
 *  Created on: Feb 17, 2012
 *      Author: jesse
 */

#ifndef DECLARATIONS_H_
#define DECLARATIONS_H_

#include <SFML/Graphics.hpp>


//Class forward declarations
enum direction {SOUTH = 0, EAST, NORTH, WEST};
template<class T> class Grid;
template<class T> class GravityGrid;
class Visible;
class Movable;
class Clickable;
class Block;

//Typedefs to ease portability.
typedef sf::Color Color;
typedef sf::Input InputHandler;
typedef sf::Image ImageFile;
typedef sf::Matrix3 Matrix2D;
typedef sf::Sprite Sprite;
typedef sf::Rect<int> RectInt;
typedef sf::Rect<float> RectFloat;
typedef sf::Vector2<int> VectorInt;
typedef sf::Vector2<float> VectorFloat;


#endif /* DECLARATIONS_H_ */
