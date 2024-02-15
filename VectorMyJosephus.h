#pragma once

#include "Destination.h"
#include <vector>

class VectorMyJosephus 
{
public:
    // constructor/destructor
    VectorMyJosephus(int M_val, int N_val);
    ~VectorMyJosephus();

    void clear(); // clears the list/sequence
    int currentSize(); // get current size of list/sequence
    bool isEmpty(); // is current list/sequence empty?

    int getM();
    int getN();
    vector<Destination> getDestinations();

    Destination eliminateDestination(); // elimination logic for game

    void printAllDestinations(); // prints remaining elements

    void addDestination(Destination dest); // adds destination to list

    void initIt();

    private:
    int M;
    int N;
    vector<Destination> destinations;
    vector<Destination>::iterator it;
};