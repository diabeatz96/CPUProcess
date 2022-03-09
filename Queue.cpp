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
Queue::Queue(int head, int tail, int maxSize, int count, const vector<Process> &cpu) : head(head), tail(tail),
                                                                                       maxSize(maxSize), count(count),
                                                                                       CPU(cpu) {}
Queue::Queue(int maxSize) : maxSize(maxSize) {
    CPU.resize(maxSize);
}

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
        cout << "Queue is empty";
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

    /* Check if file is open, then we check if head is nullptr, if its not nullptr then do normal functionality
     * */


    if (inFile.is_open()) {
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
