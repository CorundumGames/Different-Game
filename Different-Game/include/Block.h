#ifndef BLOCKS_H_
#define BLOCKS_H_

#include <memory>
#include <map>
#include "Declarations.h"
#include "Clickable.h"
#include "Movable.h"
#include "Visible.h"
#include "Grid.h"

class Block : public Clickable, public Movable, public Visible
{
    public:
        //Not called explicitly.  Only so it's legal in boost::multi_array
        Block() {};

        //This is what should be used.
        Block(const Color newcolor, const VectorInt newgridposition);

        //Removes self from the grid.
        virtual ~Block();

        //Gets and sets this Block's ability to move.
        bool isMoving() const;
        void setMoving(const bool newmoving);

        //Returns the color of this block.
        Color getColor() const;

        //Returns this Block's Grid (not screen) position
        VectorInt getGridPosition() const;


        //Moves this Block if all checks inside return true.
        void move();

        //Deter
        void handleInput(const InputHandler& input);

        //Loads the image from a file into the class.
        static void loadImage(std::string filename);

        //So the Block can know of the Grid's properties.
        //Converted to a std::shared_ptr
        static void initContainer(Grid<Block>* newcontainer);

        //Initializes the std::map used to look up color values
        static void initMap();

        static VectorFloat getImageDims();

        static Color getRandomColor(int max_colors);

    private:
        //Preps the block and neighbors to be cleared.
        void select();

        //Un-preps a block if anywhere else is clicked.
        void deselect();

        //These lighten and darken this Block respectively.
        //Used to illustrate selection.
        void blinkOn();
        void blinkOff();

        //Snaps this Block to the closest Grid cell by checking the centers
        //of both this Block and the relevant Grid cells.
        void snapToGrid();

        //Returns true if even one like-colored block is adjacent.
        bool anyBlocksAdjacent() const;



        //If true, this block can fall.
        bool moving;

        //If true, clicking this block again will destroy it and neighbors.
        bool selected;

        //Position on the GRID, not on the screen
        VectorInt gridposition;

        //Static so the image only needs to be loaded once.
        static ImageFile image;

        //So the block can fall the right direction.
        static Direction down;

        //Smart pointer to its container so that it can know its properties.
        static std::shared_ptr<Grid<Block>> container;

        //Map of available colors, for randomly assigning a color.
        static std::map<AvailableColor, Color> colors;
};

#endif //BLOCKS_H_
