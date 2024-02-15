#include "ListMyJosephus.h"

ListMyJosephus::ListMyJosephus(int M_val, int N_val)
{
    this->M = M_val;
    this->N = N_val;
}

ListMyJosephus::~ListMyJosephus() {}

void ListMyJosephus::clear() 
{
    destinations.clear();
}

int ListMyJosephus::currentSize() 
{
    return destinations.size();
}

bool ListMyJosephus::isEmpty()
{
    return destinations.empty();
}

int ListMyJosephus::getM()
{
    return this->M;
}

int ListMyJosephus::getN()
{
    return this->N;
}

list<Destination> ListMyJosephus::getDestinations()
{
    return this->destinations;
}

Destination ListMyJosephus::eliminateDestination() 
{
    // Perform M iterations
    for (int i = 0; i < M; ++i) 
    {
        // If the iterator reaches the end of the list, wrap around to the beginning
        if (++it == destinations.end())
        {
            it = destinations.begin();
        }
        else
        {
            // Move the iterator forward
            //it++;
        }
        
    }

    // Get the destination to eliminate
    Destination eliminated_dest = *it;

    // Remove the destination from the list
    it = destinations.erase(it);

    //Reset it back to begin if it is at the end
    if(it == destinations.end())
    {
        it = destinations.begin();
    }

    // Return the eliminated destination
    return eliminated_dest;
}


void ListMyJosephus::printAllDestinations()
{
    for (auto& dest : destinations) 
    {
        dest.printPosition();
        cout << ". ";
        dest.printDestination();
        cout << " ";
    }
}

void ListMyJosephus::addDestination(Destination dest)
{
    this->destinations.push_back(dest);
}

void ListMyJosephus::initIt()
{
    this->it = this->destinations.begin();
}
