#include "Destination.h"

Destination::Destination()
{
    this->destination = " ";
    this->position = -1;
}

Destination::Destination(string newDest, int newPos)
{
    this->destination = newDest;
    this->position = newPos;
}

Destination::~Destination()
{

}

void Destination::printPosition()
{
    cout << this->position;
}

void Destination::printDestination()
{
    cout << this->destination;
}

int Destination::getPosition()
{
    return this->position;
}

string Destination::getDestination()
{
    return this->destination;
}

void Destination::setPosition(int newPos)
{
    this->position = newPos;
}

void Destination::setDestination(string newDest)
{
    this->destination = newDest;
}
