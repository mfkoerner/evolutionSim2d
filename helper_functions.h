// helper_functions.h

/*
-double getRandomFloat(double low, double high)
    -returns a random float, uniformly distributed between low and high

-Coords getRandomCoords(double minX, double maxX, double minY, double maxY)
    -returns random coords uniformly distributed between specified bounds

-Coords getRandomCoords(double min, double max)
    -returns random coords in a uniformly distributed square
    from min to max on both ends

-Coords getRandomCoords()
    -returns random coords uniformly distributed from (0.0, 0.0) to (1.0, 1.0)
    -these coordinates could be anywhere in the unit square defined above
*/

#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include "Creature.h"
#include <cstdlib>


double getRandomFloat(double low, double high);

Coords getRandomCoords(double minX, double maxX, double minY, double maxY);

Coords getRandomCoords(double min, double max);

Coords getRandomCoords();


#endif //HELPER_FUNCTIONS_H
