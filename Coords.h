// Coords.h

/*
-- Class: Coords --
    -Coords is a structure of 2-d coordinates to be used in the simulation.

    -This is a very general class that consists of an x-coordinate,
    y-coordinate, and methods for those coordinates

    -Below this point are the methods for Coords

    -precision is to 1e-6, no garuntee is made for good behavior of coordinates
    with smaller values


Constructors
    -Coords(double x, double y)
        -create a coordinate at point (x,y)

    Coords();
        -create a coordinate at point (0,0)


Modifier functions
    -void move(double x, double y)
        -move the coordinate by a vector (x,y)
        -example: (3.2, 4.0).move(-1.0, 2.3) -> (2.2, 6.3)

    -void move(Coords mover)
        -move the coordinate by a vector specifid by another coordinate

    -void toUnitVector()
        -converts the coordinate to a unit vector while preserving original
        direction
        -will do nothing if both |x| < 1e-6 & |y| < 1e-6

    -void resizeVector(double size)
        -converts the coordinate to a vector of length (size) while preserving
        original direction
        -will multiply original vector by size if both |x| < 1e-6 & |y| < 1e-6


Utility Functions
    -bool isZero()
        -returns True if |x| < 1e-6 & |y| < 1e-6, otherwise false

    -double getLength()
        -returns length of vector (x^2 + y^2)^(0.5)

    -double getDistance(Coords other)
        -returns distance between self and other

    -std::string toString()
        -returns a string of format "x,y"
        -no spaces, newlines, or () included
        -printed to 1e-6 precision because of to_string() c++ function

    -void print()
        -prints the string from toString()


Overloaded operators
    "=="
        -returns true if |x| < 1e-6 & |y| < 1e-6 for the difference of
        the operands

    "=" (assignment)
        -Currently using default assignment
        -Should provide a deep copy since Coords is mad of 2 doubles on stack

    "+"
        -Input: Coords + Coords
        -returns (x1+x2, y1+y2)

    "-"
        -Input: Coords - Coords
        -returns (x1-x2, y1-y2)

    "*"
        Input: Coords * double
        - (x,y) * z = (x*z, y*z)
        - does not work as double * Coords

    "/"
        Input: Coords / double
        -(x,y) / z = (x/z, y/z)


Variables
    -double x
        -x coordinate

    -double y
        -y coordinate
*/


#ifndef COORDS_H
#define COORDS_H

#include <iostream>
#include <string>

struct Coords {
    Coords(double x, double y);
    Coords();

    // overloaded operators
    bool operator==(Coords const &rhs) {
        return (this->x - rhs.x < 1e-6 && this->y - rhs.y < 1e-6 &&
            rhs.x - this->x < 1e-6 && rhs.y - this->y < 1e-6);
    }

    const Coords operator+(Coords const &rhs) {
        Coords output;
        output.x = this->x + rhs.x;
        output.y = this->y + rhs.y;
        return output;
    }
    const Coords operator-(Coords const &rhs) {
        Coords output;
        output.x = this->x - rhs.x;
        output.y = this->y - rhs.y;
        return output;
    }
    const Coords operator*(double const &rhs) {
        Coords output;
        output.x = this->x * rhs;
        output.y = this->y * rhs;
        return output;
    }
    const Coords operator/(double const &rhs) {
        Coords output;
        output.x = this->x / rhs;
        output.y = this->y / rhs;
        return output;
    }

    // modifier
    void move(double x, double y);
    void move(Coords mover);
    void toUnitVector();
    void resizeVector(double size);


    // getters
    bool isZero();
    double getLength();
    double getDistance(Coords other);


    // printer
    std::string toString();
    void print();

    // variables
    double x;
    double y;
};


#endif //COORDS_H