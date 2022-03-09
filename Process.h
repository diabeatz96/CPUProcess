//
// Created by bigbl on 3/8/2022.
//

#include <string>

using namespace std;

#ifndef CPUPROCESS_PROCESS_H
#define CPUPROCESS_PROCESS_H

class Process{

public:

    //Getter and Setter Methods.

    int getArriveTime() const {
        return arriveTime;
    }

    void setArriveTime(int arriveTime) {
        Process::arriveTime = arriveTime;
    }

    int getServiceTime() const {
        return serviceTime;
    }

    void setServiceTime(int serviceTime) {
        Process::serviceTime = serviceTime;
    }

    int getId() const {
        return ID;
    }

    void setId(const int &id) {
        ID = id;
    }

    int getTurnOver() const {
        return turnOver;
    }

    void setTurnOver(int turnOver) {
        Process::turnOver = turnOver;
    }

    int serviceTime;
    int ID;
    int turnOver;
    int arriveTime;


};



#endif //CPUPROCESS_PROCESS_H
