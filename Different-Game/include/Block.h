#ifndef BLOCKS_H_
#define BLOCKS_H_

#include "Declarations.h"
#include "Clickable.h"
#include "Movable.h"
#include "Visible.h"

class Block : public Clickable, public Movable, public Visible
{
    public:
        Block() {};
        Block(const Color newcolor, const VectorInt newgridposition);

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

        static void loadImage() { image.LoadFromFile("./gfx/block.png"); }

    private:
        bool moving;
        bool selected;
        static ImageFile image;
        static Direction down;

        Color color;
        VectorInt gridposition;

};

#endif //BLOCKS_H_
