#ifndef BLOCKS_H_
#define BLOCKS_H_

#include "Declarations.h"
#include "Clickable.h"
#include "Movable.h"
#include "Visible.h"

class Block : public Clickable, public Movable, public Visible
{
    public:
        Block();
        Block(Color newcolor, VectorInt newgridposition);

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

    private:
        bool moving;
        bool selected;
        Color color;
        VectorInt gridposition;
};

#endif //BLOCKS_H_