#pragma once

#include "Destination.h"
#include <list>

class ListMyJosephus 
{
public:
    // constructor/destructor
    ListMyJosephus(int M_val, int N_val);
    ~ListMyJosephus();

    void clear(); // clears the list/sequence
    int currentSize(); // get current size of list/sequence
    bool isEmpty(); // is current list/sequence empty?

    int getM();
    int getN();
    list<Destination> getDestinations();

    Destination eliminateDestination(); // elimination logic for game

    void printAllDestinations(); // prints remaining elements

    void addDestination(Destination dest); // adds destination to list

    void initIt();

    private:
    int M;
    int N;
    list<Destination> destinations;
    list<Destination>::iterator it;
};