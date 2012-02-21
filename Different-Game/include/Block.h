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
        Block(const Color& newcolor, const VectorInt& newgridposition);

        void initialize(const Color& newcolor,
                        const VectorInt& newgridposition);

        virtual ~Block();

        bool isMoving() const;
        void setMoving(const bool newmoving);

        Color getColor() const;
        void setColor(const Color& newcolor);
        void blinkOn();
        void blinkOff();

        VectorInt getGridPosition() const;
        void setGridPosition(const VectorInt& newgridposition);

        bool anyBlocksAdjacent() const;
        void select();
        void deselect();
        void move();
        void handleInput(const InputHandler& input);

    private:
        bool moving;
        bool selected;
        static ImageFile image;
        Color color;
        VectorInt gridposition;
};

#endif //BLOCKS_H_
