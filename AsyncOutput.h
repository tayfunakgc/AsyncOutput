#ifndef ASYNCOUTPUT_ASYNCOUTPUT_H
#define ASYNCOUTPUT_ASYNCOUTPUT_H

#include "Arduino.h"

class AsyncOutput {

private:
    int pin;
    byte seconds;
    int initialValue;
    int finalValue;
    unsigned long startTime;
    unsigned long stopTime;
    bool isDone;

public:
    AsyncOutput(int pin, byte seconds, int initialValue);
    void init();
    void start();
    void stop();
    void reset();
    float getPercent();

    bool getIsDone();
    unsigned long getStartTime();
    unsigned long getStopTime();
    void print();
};

#endif
