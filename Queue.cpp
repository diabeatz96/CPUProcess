//
// Created by bigbl on 3/8/2022.
//

#include <iostream>
#include <fstream>
#include "Queue.h"

/*
 * Constructor functions for que, simple values for creating queue
 * Manipulating values for queues kept simple with basic constructior.
 */
Queue::Queue(int head, int tail, int maxSize, int count, const vector<Process*> &cpu) : head(head), tail(tail),
                                                                                       maxSize(maxSize), count(count),
                                                                                       CPU(cpu) {}
Queue::Queue(int maxSize) : maxSize(maxSize) {
    CPU.resize(maxSize);
}

Queue::Queue() = default;

void Queue::Enqueue(Process *process) {
    if(count == maxSize) {
        cout << "CPU has reached it's max size.";
        return;
    }
    CPU[tail] = process;
    tail = (tail + 1) % maxSize;
    count++;
}

bool Queue::Dequeue() {
    if(count == 0) {
        cout << "CPU HAS FINISHED PROCESSING";
        return false;
    }
    head = (head + 1) % maxSize;
    count--;
    return true;
}

bool Queue::isEmpty() {
    return count == 0;
}

void Queue::loadFile() {
    ifstream inFile;
    int line;
    inFile.open("cpu.txt"); //Absolute path for now cause im bad.

    /* Check if file is open,
     * if it is open, we work and analyze the values of each line, selecting the values then
     * processing the value at front.
     * */


    if (inFile.is_open()) {
        inFile >> line;
        maxSize = line;
        CPU.resize(maxSize);
        while (inFile >> line) {
            auto *newProcess = new Process();
            newProcess->setId(line);
            inFile >> line;
            newProcess->setArriveTime(line);
            inFile >> line;
            newProcess->setServiceTime(line);
            Enqueue(newProcess); //Broken Lol
        }
    }
    else {
        cout << "File input is not working!";
    }
    inFile.close();
}

void processInstructions() {

}

/**
 * Helper Method to show if input was correct, it is huzzah! :)
 */

void Queue::print() {
    for(int i = 0; i < maxSize; i++) {
        cout << CPU[i]->ID << "  " << CPU[i]->arriveTime << "  " << CPU[i]->serviceTime << endl;
    }
}

int Queue::getMaxSize() const {
    return maxSize;
}

int Queue::getCount() const {
    return count;
}

const vector<Process *> &Queue::getCpu() const {
    return CPU;
}

void Queue::setCpu(const vector<Process *> &cpu) {
    CPU = cpu;
}

int Queue::getHead() const {
    return head;
}
