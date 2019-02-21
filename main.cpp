#include <iostream>
#include <queue>

#include "Event.h"
#include "Person.h"
#include "EventSimulation.cpp"
using namespace std;

int main(int argc, char* argv[]) {

    if (argc != 3) {
        cout << "Run the code with the following command: ./project2 [input_file] [output_file]" << endl;
        return 1;
    }

    ifstream infile(argv[1]);
    EventSimulation* sim = new EventSimulation(infile);
    ofstream outFile;
    outFile.open(argv[2]);
    sim->case1(outFile);
    sim->case2(outFile);
    sim->case3(outFile);
    sim->case4(outFile);
    sim->case5(outFile);
    sim->case6(outFile);
    sim->case7(outFile);
    sim->case8(outFile);
    outFile.close();
    return 0;
}