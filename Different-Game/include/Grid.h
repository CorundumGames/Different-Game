/*
 * Grid.h
 *
 *  Created on: Feb 18, 2012
 *      Author: jesse
 */

#ifndef GRID_H_
#define GRID_H_

#include "Declarations.h"
#include "Block.h"
#include <boost/multi_array.hpp>

/*
 * Holds anything.  Grid<T> is designed to be showed on screen.  It's designed
 * to be flexible, safe, and easy.  This class is contained entirely in a header
 * because splitting templated classes into multiple files is a bitch.
 */
template<class T>
class Grid
{

    public:
        Grid<T> () {}

        //This overloaded constructor is preferred, but the default is fine.
        Grid<T> (const VectorInt& newdimensions,
                 const VectorFloat newcellsize,
                 const VectorFloat newlocation);

        ~Grid<T>();

        /*** Begin object operations ******************************************/

        T get(const VectorInt& thelocation) const;
        void set(const T t, const VectorInt& newlocation);

        /*** End object operations ********************************************/


        /*** Begin cell operations ********************************************/

        //Also recalculates gridsize
        void setCellSize(const VectorFloat newcellsize);
        VectorFloat getCellSize() const;
        RectFloat getCellRect() const;

        /*** End cell operations **********************************************/


        /*** Begin grid operations ********************************************/

        //Sees if a given coordinate is inside the grid's area.
        bool isInGrid(const VectorFloat theposition) const;

        //Also recalculates cellsize
        void setGridSize(const VectorFloat newgridsize);
        VectorFloat getGridSize() const;

        //Clears the grid and resizes it.  Will remove all blocks on it!
        //Also, all objects inside must be default-constructible.
        void resetGrid(const VectorInt& newdimensions);


        //Returns the size of the grid in blocks
        VectorInt getDimensions() const;

        //This may delete the grid's contents!
        //Does not affect cellsize, gridsize, or location.
        void setDimensions(const VectorInt newdimensions);

        /*** End grid operations **********************************************/


        /*** Begin location operations ****************************************/

        //Does not affect grid's contents.
        void setLocation(const VectorFloat newlocation);

        //Returns the upper left corner of the grid.
        VectorFloat getLocation() const;

        /*** End location operations ******************************************/


        /*** Begin validity checkers ******************************************/

        //Sees if a position is in a particular cell.
        bool isInCell(const VectorFloat theposition, const VectorInt thecell) const;

        /*** End validity checkers ********************************************/

        //TODO: Implement static const unit vectors to multiply speed or velocity by.
    private:

        //Remakes the grid after all blocks have fallen.
        void updateGrid();

        //Clears the grid and anything on it.
        void clearGrid();

        //Location of upper left corner.
        VectorFloat location;

        //Size of each cell.  Each cell must be the same size!
        VectorFloat cellsize;

        //Holds all the blocks.
        GridMatrix objects;

        //TODO: Write function to update matrix's elements by seeing where each block is on screen

};

template<class T>
Grid<T>::Grid(const VectorInt& newdimensions,
              const VectorFloat newcellsize,
              const VectorFloat newlocation)
{
    setDimensions(newdimensions);
    cellsize = newcellsize;
    location = newlocation;
}

template<class T>
Grid<T>::~Grid()
{
}

template<class T>
T Grid<T>::get(const VectorInt& thelocation) const
{
    return objects[thelocation.x][thelocation.y];
}

template<class T>
void Grid<T>::set(const T t, const VectorInt& newlocation)
{
    objects[newlocation.x][newlocation.y] = t;
}

template<class T>
VectorFloat Grid<T>::getCellSize() const
{
    return cellsize;
}

template<class T>
VectorInt Grid<T>::getDimensions() const
{
    return VectorInt(objects.shape()[0], objects.shape()[1]);
}

template<class T>
void Grid<T>::setDimensions(const VectorInt newdimensions)
{
    objects.resize(boost::extents[newdimensions.x][newdimensions.y]);
}

template<class T>
void Grid<T>::resetGrid(const VectorInt& newdimensions)
{
     objects.resize(boost::extents[newdimensions.x][newdimensions.y]);
     for (int i = 0; i < newdimensions.x; ++i)
          for (int j = 0; j < newdimensions.y; ++j)
               objects[i][j] = T();
}

#endif /* GRID_H_ */
