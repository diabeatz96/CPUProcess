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
    vector<Process> CPU;

public:
    void Enqueue(Process *process);
    bool Dequeue();
    bool isEmpty();
    void loadFile();

    Queue(int head, int tail, int maxSize, int count, const vector<Process> &cpu);
    explicit Queue(int maxSize);

};


#endif //CPUPROCESS_QUEUE_H
