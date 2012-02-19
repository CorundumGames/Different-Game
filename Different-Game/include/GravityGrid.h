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
class GravityGrid<T> : public Grid<T>
{
    public:
        GravityGrid<T> ();

        //This overloaded constructor is preferred, but the default is fine.
        GravityGrid<T> (const VectorInt& newgridsize, const VectorFloat& newcellsize,
                        const VectorFloat& newlocation);
    private:
        direction down;

};
#endif //GRAVITYGRID_H_
