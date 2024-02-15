#include "TestListMyJosephus.h"

void testList()
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

    ListMyJosephus list(256, 512);
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

    cout << "---------- ** Test ListMyJosephus ** ----------" << endl;
    cout << "M: " << list.getM() << " N: " << list.getN() << " Selected Line: " << j << endl;
    cout << "Original Destinations: " << endl;

    while(i < list.getN())
    {
        getline(inputFile, line, ';');
        Destination dest(line, i);
        line = " ";
        list.addDestination(dest);
        i++;
    }

    list.printAllDestinations();

    i = 0;

    ListMyJosephus removedElements(list.getM(), list.getN());

    list.initIt();
    clock_t startElim = clock();
     
    while (list.currentSize() > 1)
    {
        cout << endl << "ROUND #" << i + 1 << " - - - - Remaining Destinations:" << endl;
        removedElements.addDestination(list.eliminateDestination());
        list.printAllDestinations();
        i++;
    }

    clock_t endElim = clock();

    double elimTime = (endElim - startElim) / list.getN();
    elimTime = elimTime / CLOCKS_PER_MS;

    cout << "--------" << endl;
    cout << "Order of Elimination: " << endl;

    for(auto& dest : removedElements.getDestinations())
    {
        dest.printDestination();
        cout << endl;
    }

    cout << "Destination Chosen: ";
    list.printAllDestinations();
    cout << endl;

    clock_t endSim = clock();
    double simTime = (endSim - startSim) / CLOCKS_PER_MS;

    outfile << "~~List Testing~~" << endl;

    outfile << "M = " << list.getM() << " N = " << list.getN() << endl;

    outfile << "Total CPU Time: " << simTime << " milliseconds" << endl;

    outfile << "Avg Elim Time: " << elimTime << " milliseconds" << endl;

    inputFile.close();
}