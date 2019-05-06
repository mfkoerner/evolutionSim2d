// Entity.h

/*
-- Class: Entity --
    -Entity is a base class for entities that have a position and image tag

    -This is intended to allow for restrictions such as periodic boundary
    conditions or solid boudaries that should apply to all entities in an
    arena

    -Entity also allows for a proper object oriented class on top of the
    more primative Coords structure

    -Precision and specifics of Coordinate implementation can be
    found in Coords.h


Constructors
    -Entity(Coords position, std::string image)
        -Fully specified constructor
        -position is location of entity
        -image is intended for later visualization purposes
        -image is currently not implemented in output file, but will be later

    -Entity(Coords position)
        -sets image to "" (empty string)

    -Entity()
        -sets position to (0.0, 0.0) and image to ""

Getter and Setter functions (and some utility)
    -void move(Coords velocity)
        -moves the entity by the given vector
        -this is a relative movement, so (0.0, 1.0).move((2.1, -1.0)) would
        result in the entity being moved to (2.1, 0.0)

    -Coords getPosition()
        -returns the Coords of the entity's position
        -does not modify the Entity

    -std::string getImage()
        -returns the image string

    -std::string toString()
        -returns a string of the below format:
            position: ${x},${y} image: "${IMAGE}"

    -void setImage(std::string image)
        -sets the image string to a new string

*/





#ifndef ENTITY_H
#define ENTITY_H

#include "Coords.h"
#include <iostream>
#include <string>

class Entity {
public:
    // Constructors
    Entity(Coords position, std::string image);
    Entity(Coords position);
    Entity();

    void move(Coords velocity);
    Coords getPosition();
    std::string getImage();
    std::string toString();

    void setImage(std::string image);
private:
    Coords position;
    std::string image;
};


#endif //ENTITY_H