/*
 * GravityGri.cpp
 *
 *  Created on: Feb 18, 2012
 *      Author: jesse
 */
#ifndef GRAVITYGRID_H_
#define GRAVITYGRID_H_

#include <boost/multi_array.hpp>
#include "Declarations.h"
#include "Grid.h"

template<class T>
class GravityGrid : public Grid<T>
{
    public:
        GravityGrid<T> ();

        //This overloaded constructor is preferred, but the default is fine.
        GravityGrid<T> (const VectorInt newdimensions,
                        const VectorFloat newcellsize,
                        const VectorFloat newlocation);


    private:
        Direction down;
        VectorInt dimensions;
        VectorFloat cellsize;
        VectorFloat location;

        //TODO: Write function to update matrix's elements by seeing where each block is on screen

};

template<class T>
GravityGrid<T>::GravityGrid(const VectorInt newdimensions,
                            const VectorFloat newcellsize,
                            const VectorFloat newlocation)
{
      dimensions = VectorInt(newdimensions.x, newdimensions.y);
      cellsize = VectorFloat(newcellsize.x, newcellsize.y);
      location = VectorFloat(newlocation.x, newlocation.y);
}
#endif //GRAVITYGRID_H_
