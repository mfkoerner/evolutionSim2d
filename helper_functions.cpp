// helper_functions.cpp

#include "Creature.h"
#include <cstdlib>



double getRandomFloat(double low, double high) {
    return low + static_cast <double> (std::rand()) /( static_cast <double> (RAND_MAX/(high-low)));
}

Coords getRandomCoords(double minX, double maxX, double minY, double maxY) {
    double x = getRandomFloat(minX, maxX);
    double y = getRandomFloat(minY, maxY);
    return Coords(x, y);
}

Coords getRandomCoords(double min, double max) {
    return getRandomCoords(min, max, min, max);
}

Coords getRandomCoords() {
    return getRandomCoords(0., 1.);
}

double getRandomAngle(double minAngle = 0., double maxAngle = 6.28318530) {
    return getRandomFloat(minAngle, maxAngle);
}

Coords getRandomUnitVector() {
    Coords outVector(0., 1.);
    float randAngle = getRandomAngle();
    outVector.rotate(randAngle);
    return outVector;
}