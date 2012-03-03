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
#include <utility>

//Class forward declarations
enum class Direction : char {SOUTH = 0, EAST, NORTH, WEST};
enum class AvailableColor : char {
    RED = 0, BLUE, GREEN, YELLOW, CYAN, PURPLE, WHITE
};
class Visible;
class Movable;
class Clickable;
class Block;
class GameWindow;
class ScoreKeeper;
template<class T> class Grid;

//Typedefs to ease portability.
typedef boost::multi_array<Block, 2> GridMatrix;
typedef sf::Color Color;
typedef sf::Event Event;
typedef sf::Input InputHandler;
typedef sf::Image ImageFile;
typedef sf::Sprite Sprite;
typedef sf::String TextDisplay;
typedef sf::Randomizer RandomNumber;
typedef sf::Rect<int> RectInt;
typedef sf::Rect<float> RectFloat;
typedef sf::RenderWindow Screen;
typedef sf::Vector2<int> VectorInt;
typedef sf::Vector2<int> PointInt;   //Same as VectorInt, just for clarity!
typedef sf::Vector2<float> VectorFloat;
typedef sf::Vector2<float> PointFloat;   //Again for VectorFloat
typedef sf::VideoMode VideoMode;
typedef std::pair<AvailableColor, Color> ColorPair;

#endif /* DECLARATIONS_H_ */
