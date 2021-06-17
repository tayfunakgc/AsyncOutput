#include "Arduino.h"
#include "AsyncOutput.h"

AsyncOutput::AsyncOutput(int pin, byte seconds, int initialValue) {
    this->pin = pin;
    this->seconds = seconds;
    this->initialValue = (initialValue == LOW) ? LOW : HIGH;
    this->finalValue = (this->initialValue == LOW) ? HIGH : LOW;
    this->startTime = 0;
    this->isDone = false;
}

void AsyncOutput::init() {
    pinMode(this->pin, OUTPUT);
    digitalWrite(this->pin, this->initialValue);
}

void AsyncOutput::start() {
    if(this->isDone == true)
        return;

    if(this->startTime == 0)
        this->startTime = millis();

    if(millis() - this->startTime >= (this->seconds * 1000)) {
        this->stop();
    } else {
        digitalWrite(this->pin, this->finalValue);
    }
}

void AsyncOutput::stop() {
    digitalWrite(this->pin, this->initialValue);
    this->stopTime = millis();
    this->isDone = true;
}

void AsyncOutput::reset() {
    this->isDone = false;
    this->startTime = 0;
}

float AsyncOutput::getPercent() {
    if(this->isDone == true)
        return 100.0f;
    unsigned long stopTime = this->startTime + (this->seconds * 1000);
    return (float)(millis() * 100) / (float)stopTime;
}

bool AsyncOutput::getIsDone() {
    return this->isDone;
}

unsigned long AsyncOutput::getStartTime() {
    return this->startTime;
}

unsigned long AsyncOutput::getStopTime() {
    return this->stopTime;
}

void AsyncOutput::print() {
    Serial.println(String("Pin: ") + this->pin);
    Serial.println(String("Seconds: ") + this->seconds);
    Serial.println(String("Initial Value: ") + ((this->initialValue == LOW) ? "LOW" : "HIGH"));
    Serial.println(String("Final Value: ") + ((this->finalValue == LOW) ? "LOW" : "HIGH"));
}
