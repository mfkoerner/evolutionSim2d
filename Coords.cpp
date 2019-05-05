// Coords.cpp

#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include "Coords.h"

using namespace std;

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

string Coords::toString() {
    string output;
    output = to_string(x) + "," + to_string(y);
    return output;
}

void Coords::print() {
    cout << toString() << endl;
}

