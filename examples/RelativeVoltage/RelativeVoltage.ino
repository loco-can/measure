/*
 * Setup for relative voltage measurement on two analog ports
 */

#include <Measure.h>


// define the port to be used
#define MEASURE_PORT_1 A0
#define MEASURE_PORT_2 A1


// initialize class
MEASURE voltage;


void setup() {

	Serial.begin(115200);

	Serial.print("Relative measurement between ports ");
	Serial.println(MEASURE_PORT_1);
	Serial.print(" and port ");
	Serial.println(MEASURE_PORT_2);

	// setup
	voltage.begin(MEASURE_PORT_1, MEASURE_PORT_2); // begin relative measurement
	voltage.setResolution(10); // set resolution to 10 bit
	voltage.calibrate(1); // calibrate to 1 > no change of the ADC values
}


void loop() {

	Serial.println("port 1-GND = ");
	Serial.print(voltage.get(MEASURE_VALUE_1));
	Serial.print(" Volts, port 2-GND = ");
	Serial.print(voltage.get(MEASURE_VALUE_1));
	Serial.print(" Volts, relative = ");
	Serial.print(voltage.get(MEASURE_VALUE_RELATIVE));
	Serial.println(" Volts");

	delay(1000);
}