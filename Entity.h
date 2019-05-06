// Entity.h

/*
-- Class: Entity --
    -Entity is a base class for entities
    -Comes with Coords position
    -Comes with string image to be later implemented for visualization
        -image is not currently implemented in Arena or Creature for output


Constructors
    -Entity(Coords position, std::string image)
    -Entity(Coords position)
        -sets image to "" (empty string)
    -Entity()
        -sets position to (0.0, 0.0) and image to ""

Getter and Setter functions (and some utility)
    -void move(Coords velocity)
        -relative motion: new position = old position + velocity

    -Coords getPosition()
        -returns the Coords of the entity's position

    -std::string getImage()
        -returns the image string

    -std::string toString()
        -returns a string of the below format:
            position: ${x},${y} image: ${IMAGE}

    -void setImage(std::string image)
        -sets the image string the given image

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