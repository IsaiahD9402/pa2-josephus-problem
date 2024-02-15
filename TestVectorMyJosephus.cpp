#include "TestVectorMyJosephus.h"
#include "VectorMyJosephus.cpp"

void testVector()
{
    clock_t startSim = clock();
    srand(time(nullptr));

    ifstream inputFile;

    ofstream outfile;

    outfile.open("Reports.log", std::ios_base::app);

    inputFile.open("destinations.csv", std::ios::in);

    if(inputFile.fail())
    {
        cout << "Error Opening File!";
    }

    VectorMyJosephus Vector(256, 512);
    string line = " ";
    //char c = ' ';

    int j = rand() % 25 + 1;
    int i = 0;

    for(; i < j; i++)
    {
        //inputFile.ignore(LONG_MAX, '\n');
        getline(inputFile, line);
        line = " ";
    }

    i = 0;

    cout << "---------- ** Test VectorMyJosephus ** ----------" << endl;
    cout << "M: " << Vector.getM() << " N: " << Vector.getN() << " Selected Line: " << j << endl;
    cout << "Original Destinations: " << endl;

    while(i < Vector.getN())
    {
        getline(inputFile, line, ';');
        Destination dest(line, i);
        line = " ";
        Vector.addDestination(dest);
        i++;
    }

    Vector.printAllDestinations();

    i = 0;

    VectorMyJosephus removedElements(Vector.getM(), Vector.getN());

    Vector.initIt();
    clock_t startElim = clock();
     
    while (Vector.currentSize() > 1)
    {
        cout << endl << "ROUND #" << i + 1 << " - - - - Remaining Destinations:" << endl;
        removedElements.addDestination(Vector.eliminateDestination());
        Vector.printAllDestinations();
        i++;
    }

    clock_t endElim = clock();

    double elimTime = (endElim - startElim) / Vector.getN();
    elimTime = elimTime / CLOCKS_PER_MS;

    cout << "--------" << endl;
    cout << "Order of Elimination: " << endl;

    for(auto& dest : removedElements.getDestinations())
    {
        dest.printDestination();
        cout << endl;
    }

    cout << "Destination Chosen: ";
    Vector.printAllDestinations();
    cout << endl;

    clock_t endSim = clock();
    double simTime = (endSim - startSim) / CLOCKS_PER_MS;

    outfile << endl;

    outfile << "~~Vector Testing~~" << endl;

    outfile << "M = " << Vector.getM() << " N = " << Vector.getN() << endl;

    outfile << "Total CPU Time: " << simTime << " milliseconds" << endl;

    outfile << "Avg Elim Time: " << elimTime << " milliseconds" << endl;

    outfile << "-------------------------------------------------------------------------------------------" << endl;

    inputFile.close();
}