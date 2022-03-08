//
// Created by bigbl on 3/8/2022.
//

#include "string"
#include "vector"
#include "Process.h"
#ifndef CPUPROCESS_QUEUE_H
#define CPUPROCESS_QUEUE_H

using namespace std;

class Queue {
private:
    int head = 0;
    int tail = 0;
    int maxSize = 0;
    int count = 0;

public:
    void Enqueue(Process process);

};


#endif //CPUPROCESS_QUEUE_H
