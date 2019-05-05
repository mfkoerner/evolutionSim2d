// Entity.h

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