#include "VectorMyJosephus.h"

VectorMyJosephus::VectorMyJosephus(int M_val, int N_val)
{
    this->M = M_val;
    this->N = N_val;
}

VectorMyJosephus::~VectorMyJosephus() {}

void VectorMyJosephus::clear() 
{
    destinations.clear();
}

int VectorMyJosephus::currentSize() 
{
    return destinations.size();
}

bool VectorMyJosephus::isEmpty()
{
    return destinations.empty();
}

int VectorMyJosephus::getM()
{
    return this->M;
}

int VectorMyJosephus::getN()
{
    return this->N;
}

vector<Destination> VectorMyJosephus::getDestinations()
{
    return this->destinations;
}

Destination VectorMyJosephus::eliminateDestination() 
{
    // Perform M iterations
    for (int i = 0; i < M; ++i) 
    {
        // If the iterator reaches the end of the Vector, wrap around to the beginning
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

    // Remove the destination from the Vector
    it = destinations.erase(it);

    //Reset it back to begin if it is at the end
    if(it == destinations.end())
    {
        it = destinations.begin();
    }

    // Return the eliminated destination
    return eliminated_dest;
}


void VectorMyJosephus::printAllDestinations()
{
    for (auto& dest : destinations) 
    {
        dest.printPosition();
        cout << ". ";
        dest.printDestination();
        cout << " ";
    }
}

void VectorMyJosephus::addDestination(Destination dest)
{
    this->destinations.push_back(dest);
}

void VectorMyJosephus::initIt()
{
    this->it = this->destinations.begin();
}
