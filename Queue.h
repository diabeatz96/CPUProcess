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

private:
    int maxSize = 0;
    int count = 0;
    vector<Process*> CPU;

public:
    const vector<Process *> &getCpu() const;
    void setCpu(const vector<Process *> &cpu);
    int getMaxSize() const;
    int getCount() const;
    int getHead() const;


public:
    void Enqueue(Process *process);
    bool Dequeue();
    bool isEmpty();
    void loadFile();
    void print();

    Queue(int head, int tail, int maxSize, int count, const vector<Process*> &cpu);
    Queue(int maxSize);
    Queue();

};


#endif //CPUPROCESS_QUEUE_H
