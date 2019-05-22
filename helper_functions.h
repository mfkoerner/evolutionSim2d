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

-double getRandomAngle(double minAngle = 0., double maxAngle = 6.28318530)
    -returns a random angle from 0 to 2pi in radians or from inputted angles
    -functionally identical to getRandomFloat(low, high)

-Coords getRandomUnitVector()
    -returns a unit vector pointing in a random direction


*/

#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include "Creature.h"
#include <cstdlib>


double getRandomFloat(double low, double high);

Coords getRandomCoords(double minX, double maxX, double minY, double maxY);

Coords getRandomCoords(double min, double max);

Coords getRandomCoords();

double getRandomAngle(double minAngle = 0., double maxAngle = 6.28318530);

Coords getRandomUnitVector();





#endif //HELPER_FUNCTIONS_H
