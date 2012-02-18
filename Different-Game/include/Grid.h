/*
 * Grid.h
 *
 *  Created on: Feb 18, 2012
 *      Author: jesse
 */

#ifndef GRID_H_
#define GRID_H_

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
        Grid<T> ();

        //This overloaded constructor is preferred, but the default is fine.
        Grid<T> (const VectorInt& newgridsize, const VectorFloat& newcellsize,
                const VectorFloat& newlocation);

        /*** Begin object operations ***/

        T get(const VectorInt& newlocation) const;
        void set(const T& t, const VectorInt& newlocation);

        /*** End object operations ***/

        /*** Begin dimension operations ***/

        //This will delete the grid's contents!
        //Does not affect cellsize, gridsize, or location.
        void setDimensions(const VectorInt& newdimensions);
        VectorInt getDimensions() const;

        /*** End dimension operations ***/

        /*** Begin cell operations ***/

        //Also recalculates gridsize
        void setCellSize(const VectorFloat& newcellsize);
        VectorFloat getCellSize() const;

        /*** End cell operations ***/

        /*** Begin grid operations ***/

        //Sees if a given coordinate is inside the grid's area.
        bool isInGrid(const VectorFloat& newposition) const;

        //Also recalculates cellsize
        void setGridSize(const VectorFloat& newgridsize);

        VectorFloat getGridSize() const;

        /*** End grid operations ***/

        /*** Begin location operations ***/

        //Does not affect grid's contents.
        void setLocation(const VectorFloat& newlocation);
        VectorFloat getLocation() const;

        /*** End location operations ***/

        /*** Begin validity checkers ***/
        bool isCellValid(const VectorInt& cell) const;

        bool
                isInCell(const VectorFloat& newposition, const VectorInt& cell) const;
        /*** End validity checkers ***/

        //TODO: Implement static const unit vectors to multiply speed or velocity by.
    protected:
        //Size of the grid in blocks.
        VectorInt dimensions;

        //Location of upper left corner.
        VectorFloat location;

        //Size of each cell.  Each cell must be the same size!
        VectorFloat cellsize;

        //Size of the whole grid.  Get/setters must recalculate this and cellsize!
        VectorFloat gridsize;

        //A rectangle representing the grid's area.
        RectFloat gridarea;

        //Called internally by the constructor and setGridSize().
        void initializeGrid(const VectorInt& newsize);

        //Clears the grid and anything on it.
        void deleteGrid();

        /*
         * A 2D array.  Need to initialize with a nested for loop.
         * Must remember to delete it in the destructor and in setGridSize()!
         */
        T** objects;

};

#endif /* GRID_H_ */
