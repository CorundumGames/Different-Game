/*
 * Grid.h
 *
 *  Created on: Feb 18, 2012
 *      Author: jesse
 */

#ifndef GRID_H_
#define GRID_H_

#include <boost/numeric/ublas/matrix.hpp>
#include "Declarations.h"

/*
 * Holds anything.  Grid<T> is designed to be showed on screen.  It's designed
 * to be flexible, safe, and easy.  This class is contained entirely in a header
 * because splitting templated classes into multiple files is a bitch.
 *
 */
template<class T>
class Grid
{

    public:
        Grid<T> () {};

        //This overloaded constructor is preferred, but the default is fine.
        Grid<T> (const VectorInt& newdimensions, const VectorFloat& newcellsize,
                 const VectorFloat& newlocation);

        /*** Begin object operations ***/

        T get(const VectorInt& newlocation) const;
        void set(const T& t, const VectorInt& newlocation);

        /*** End object operations ***/


        /*** Begin dimension operations ***/

        //These will delete the grid's contents!
        //Does not affect cellsize, gridsize, or location.
        void setDimensions(const VectorInt& newdimensions);
        VectorInt getDimensions() const { return dimensions; }

        /*** End dimension operations ***/


        /*** Begin cell operations ***/

        //Also recalculates gridsize
        void setCellSize(const VectorFloat& newcellsize);
        VectorFloat getCellSize() const { return cellsize; }
        RectFloat getCellRect() const;

        /*** End cell operations ***/


        /*** Begin grid operations ***/

        //Sees if a given coordinate is inside the grid's area.
        bool isInGrid(const VectorFloat& newposition) const;
        bool isInGrid(const RectFloat& newposition) const;

        //Also recalculates cellsize
        void setGridSize(const VectorFloat& newgridsize);

        //Clears the grid and resizes it.  Will remove all blocks on it!
        void resetGrid(const VectorInt& newdimensions);

        VectorFloat getGridSize() const;

        /*** End grid operations ***/


        /*** Begin location operations ***/

        //Does not affect grid's contents.
        void setLocation(const VectorFloat& newlocation);

        //Returns the upper left corner of the grid.
        VectorFloat getLocation() const;

        /*** End location operations ***/


        /*** Begin validity checkers ***/

        //bool isCellValid(const VectorInt& cell) const;

        //Sees if a position is in a particular cell.
        bool isInCell(const VectorFloat& newposition, const VectorInt& cell) const;

        /*** End validity checkers ***/

        //TODO: Implement static const unit vectors to multiply speed or velocity by.
    protected:

        //Remakes the grid after all blocks have fallen.
        void updateGrid();

        //Clears the grid and anything on it.
        void clearGrid();

        //Size of the grid in blocks.
        VectorInt dimensions;

        //Location of upper left corner.
        VectorFloat location;

        //Size of each cell.  Each cell must be the same size!
        VectorFloat cellsize;

        //Size of the whole grid.  Get/setters must recalculate this and cellsize!
        VectorFloat gridsize;

        //Holds all the blocks.
        GridMatrix objects;

};

template<class T>
Grid<T>::Grid(const VectorInt& newdimensions, const VectorFloat& newcellsize,
        const VectorFloat& newlocation)
{
    dimensions = VectorInt(newdimensions.x, newdimensions.y);
    cellsize = VectorFloat(newcellsize.x, newcellsize.y);
    location = VectorFloat(newlocation.x, newlocation.y);
    resetGrid(dimensions);
}

template<class T>
T Grid<T>::get(const VectorInt& newlocation) const
{
     return objects[newlocation.x][newlocation.y];
}

template<class T>
void Grid<T>::resetGrid(const VectorInt& newdimensions)
{
     objects.resize(boost::extents[newdimensions.x][newdimensions.y]);
     for (int i = 0; i < objects.shape()[0]; ++i)
          for (int j = 0; j < objects.shape()[1]; ++j)
               objects[i][j] = Block(Color::White, VectorInt(i, j));

}

/*template<class T>
bool Grid<T>::isCellValid(const VectorInt& cell) const
{
     return (cell.x >= 0) && (cell.y >= 0) &&
            (cell.x < objects.shape()[0]) && (cell.y < objects.shape()[1]);
}  Deprecated?  */


#endif /* GRID_H_ */
