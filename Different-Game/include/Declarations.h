/*
 * Declarations.h
 *
 *  Created on: Feb 17, 2012
 *      Author: jesse
 */

#ifndef DECLARATIONS_H_
#define DECLARATIONS_H_

#include <SFML/Graphics.hpp>
#include <boost/multi_array.hpp>

//Class forward declarations
enum Direction {SOUTH = 0, EAST, NORTH, WEST};
template<class T> class Grid;
template<class T> class GravityGrid;
class Visible;
class Movable;
class Clickable;
class Block;
class GameWindow;
class ScoreKeeper;

//Typedefs to ease portability.
template<typename T, unsigned long U> class GridMatrix;
typedef sf::Color Color;
typedef sf::Event Event;
typedef sf::Input InputHandler;
typedef sf::Image ImageFile;
typedef sf::Matrix3 Matrix2D;
typedef sf::Sprite Sprite;
typedef sf::String TextDisplay;
typedef sf::Rect<int> RectInt;
typedef sf::Rect<float> RectFloat;
typedef sf::RenderWindow Screen;
typedef sf::Vector2<int> VectorInt;
typedef sf::Vector2<float> VectorFloat;
typedef sf::VideoMode VideoMode;
typedef unsigned long long int uint64;


#endif /* DECLARATIONS_H_ */
