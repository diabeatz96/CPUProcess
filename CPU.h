//
// Created by bigbl on 3/8/2022.
//

#include "Queue.h"
#include <Windows.h>


#ifndef CPUPROCESS_CPU_H
#define CPUPROCESS_CPU_H

#include "iostream"
#include "unistd.h"
using namespace std;

class CPU {


public:
    int totalTime = 0;
    double waitTime = 0;
    Queue instructions = Queue();

    void processInstructions();
};


#endif //CPUPROCESS_CPU_H
