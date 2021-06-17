# AsyncOutput
Non-blocking digital output library for arduino 


## Example Usages

```cpp
#include <AsyncOutput.h>

AsyncOutput Led(LED_BUILTIN, 5, LOW);

unsigned long wait;


void setup() {
	Serial.begin(9600);
	Led.init();
	wait = millis();
}

void loop() {
	Led.start();
	Serial.println(Led.getPercent());
	Serial.println(Led.getStartTime());
	Serial.println(Led.getStopTime());
	if(millis() - wait >= 10000) {
		wait = millis();
		Led.reset();
	}
}

```
