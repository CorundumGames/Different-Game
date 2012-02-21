/*
 * GravityGri.cpp
 *
 *  Created on: Feb 18, 2012
 *      Author: jesse
 */
#ifndef GRAVITYGRID_H_
#define GRAVITYGRID_H_

#include "Declarations.h"
#include "Grid.h"

template<class T>
class GravityGrid : public Grid<T>
{
    public:
        GravityGrid<T> ();

        //This overloaded constructor is preferred, but the default is fine.
        GravityGrid<T> (const VectorInt& newgridsize, const VectorFloat& newcellsize,
                        const VectorFloat& newlocation);
        //TODO: Inherit constructor from Grid<T>
    private:
        Direction down;

        //TODO: Write function to update matrix's elements by seeing where each block is on screen

};
#endif //GRAVITYGRID_H_
