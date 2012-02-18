/*
 * Grid.h
 *
 *  Created on: Feb 18, 2012
 *      Author: jesse
 */

#ifndef GRID_H_
#define GRID_H_

#include "Declarations.h"

/* Holds blocks.  Design this to be useful in many projects! */
template<class T>
class Grid
{

public:
	Grid<T>();

	//This overloaded constructor is preferred, but the default is fine, too.
	Grid<T>(const   VectorInt& newgridsize,
			const VectorFloat& newcellsize,
			const VectorFloat& newlocation);

	/* Begin objects */
	T    get(const VectorInt& newlocation) const;
	void set(const T& t,
			 const VectorInt& newlocation);
	/* End objects */

	/* Begin dimensions */
	void setSize(const VectorInt& newdimensions);
	/* End dimensions */

	/* Begin cellsize */
	/* End cellsize */

	/* Begin gridsize */
	/* End gridsize */

	/* Begin location */
	/* End location */

	/* Begin validity checkers */
	bool isCellValid(const VectorInt& cell);
	bool isInGrid(const VectorFloat& newposition);
	bool isInCell(const VectorFloat& newposition,
				  const VectorInt& cell);
	/* End validity checkers */

	//TODO: Implement const unit vectors to multiply speed or velocity by.
private:
protected:
	//Size of the grid in blocks.
	VectorInt dimensions;

	//Size of each cell.  Each cell must be the same size!
	VectorFloat cellsize;

	//Size of the whole grid.  Get/setters must recalculate this and cellsize!
	VectorFloat gridsize;

	//Where the upper left corner of the grid is.
	VectorFloat location;



	/*
	 * A double array.  Need to initialize with a nested for loop.
	 * Must remember to delete it in the destructor and in setGridSize()!
	 */
	T** objects;

};


#endif /* GRID_H_ */
