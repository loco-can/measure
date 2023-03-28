/*
 * A single voltage measurement on one analog port A0
 */

#include <Measure.h>


// define the port to be used
#define MEASURE_PORT A0


// initialize class
MEASURE voltage;


void setup() {

	Serial.begin(115200);

	Serial.print("Measurement on port ");
	Serial.println(MEASURE_PORT);

	// setup
	voltage.begin(MEASURE_PORT); // begin measurement on port A0
	voltage.setResolution(10); // set resolution to 10 bit
	voltage.calibrate(1); // calibrate to 1 > no change of the ADC values
}


void loop() {

	Serial.print(voltage.get());
	Serial.println(" Volts");

	delay(1000);
}