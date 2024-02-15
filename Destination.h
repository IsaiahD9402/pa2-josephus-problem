#pragma once

#include "header.h"

// new Destination class to hold the sequence of destinations
class Destination
{
    public:
    // constructor and destructor
    Destination();
    Destination(string newDest, int newPos);
    ~Destination();

    // print position and destination to screen
    void printPosition();
    void printDestination();

    //getters
    int getPosition();
    string getDestination();

    //setters
    void setPosition(int newPos);
    void setDestination(string newDest);

    //Destination& operator=(Destination& lhs, Destination& rhs);

    private:
    string destination;
    int position;
};
