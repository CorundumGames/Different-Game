#ifndef BLOCKS_H_
#define BLOCKS_H_

#include <memory>
#include "Declarations.h"
#include "Clickable.h"
#include "Movable.h"
#include "Visible.h"
#include "Grid.h"

class Block : public Clickable, public Movable, public Visible
{
    public:
        Block() {};
        Block(const Color newcolor,
              const VectorInt newgridposition,
              Grid<Block>* newcontainer);

        void initialize(const Color newcolor,
                        const VectorInt newgridposition);

        virtual ~Block();

        bool isMoving() const;
        void setMoving(const bool newmoving);

        Color getColor() const;
        void setColor(const Color newcolor);
        void blinkOn();
        void blinkOff();

        VectorInt getGridPosition() const;
        void setGridPosition(const VectorInt newgridposition);
        void snapToGrid();  //Works via its center.

        bool anyBlocksAdjacent() const;
        void select();
        void deselect();
        void move();
        void handleInput(const InputHandler& input);

        static void loadImage(std::string filename);

    private:
        bool moving;
        bool selected;

        Color color;
        VectorInt gridposition;

        static ImageFile image;
        static Direction down;
        std::shared_ptr<Grid<Block>> container;
};

#endif //BLOCKS_H_
