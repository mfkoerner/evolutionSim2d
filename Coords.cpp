// Coords.cpp

#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include "Coords.h"

using namespace std;

const float PI = 3.141592;

Coords::Coords(double x, double y) {
    this->x = x;
    this->y = y;
}

Coords::Coords() {
    x = 0.;
    y = 0.;
}

void Coords::move(double x, double y) {
    this->x += x;
    this->y += y;
}

void Coords::move(Coords mover) {
    this->x += mover.x;
    this->y += mover.y;
}

void Coords::toUnitVector() {
    if (!isZero()) {
        double length = getLength();
        *this = *this / length;
    } // if it is already zero, it remains zero
    // else {
    //     *this = Coords(0., 0.); // converts small to zero
    // }

}

void Coords::resizeVector(double size) {
    toUnitVector();
    *this = *this * size;
}

bool Coords::isZero() {
    Coords zeroCoord(0., 0.);
    return *this == zeroCoord;
}

double Coords::getLength() {
    return sqrt(pow(x, 2.0) + pow(y, 2.0));
}

double Coords::getDistance(Coords other) {
    Coords temp = *this - other;
    return temp.getLength();
}

double Coords::getAngle() {
    if (x == 0. && y == 0.) {
        return 0.;
    } else if ( x == 0.) {
        if (y > 0.) {
            return PI/2;
        } else {
            return 3*PI/2;
        }
    } else if ( y == 0.) {
        if (x > 0.) {
            return 0.;
        } else {
            return PI;
        }
    } else {
        double angle = acos(x/getLength());
        if (y > 0) {
            return angle;
        } else {
            return 2*PI - angle;
        }
    }
}

double Coords::getAngleBetween(Coords other) {
    angle1 = getAngle();
    angle2 = other.getAngle();
    angleBetween = reduceAngle(angle2 - angle1);
    return angleBetween;
}

string Coords::toString() {
    string output;
    output = to_string(x) + "," + to_string(y);
    return output;
}

void Coords::print() {
    cout << toString() << endl;
}

double dotProduct(Coords a, Coords b) {
    return (a.x*b.x + a.y*b.y);
}

double reduceAngle(double theta) {
    if (theta > PI) {
        while (theta > 2*PI) {
            theta -= 2*PI;
        }
    } else if (theta < -1*PI) {
        while (theta < -1*PI) {
            theta += 2*PI;
        }
    }
    return theta;
}
