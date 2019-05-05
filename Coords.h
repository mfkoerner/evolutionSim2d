// Coords.h

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