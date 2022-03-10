//
// Created by bigbl on 3/8/2022.
//

#include "CPU.h"

void CPU::processInstructions() {

    do {
        int arriveTime = instructions.getCpu().at(instructions.getHead())->arriveTime;
        int serviceTime = instructions.getCpu().at(instructions.getHead())->serviceTime;
        totalTime += serviceTime;
        double turnAroundTime =  totalTime - arriveTime;
        double waitingTime = turnAroundTime - serviceTime;
        waitTime += waitingTime;

        auto normalizedTat = (turnAroundTime/serviceTime);

        //usleep(1000000); (For Fun)
        cout << "Process: " << instructions.getCpu().at(instructions.getHead()) -> getId() << " Your output is: " << endl;
        cout << " TURN AROUND TIME: " << turnAroundTime << endl;
        cout << " TOTAL WAITING TIME: " << waitingTime << endl;
        cout << " NORMALIZED TAT: " << normalizedTat << endl;

        cout << endl << endl;

    }
    while(instructions.Dequeue() && instructions.getCount() != 0);

    cout << "Average Waiting Time:" << waitTime/instructions.getMaxSize() << endl;
    cout << "Total Waiting Time:" << waitTime;
}
