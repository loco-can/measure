/*
 * measure class header file
 * 
 * @author: Thomas H Winkler
 * @copyright: 2020-2021
 * @lizence: GG0
 */

#ifndef MEASURE_H
#define MEASURE_H

#include <Arduino.h>

// get types
#define MEASURE_VALUE_1 1
#define MEASURE_VALUE_2 2
#define MEASURE_VALUE_RELATIVE 3


class MEASURE {

  public:
    MEASURE(); // create voltage class

    void begin(uint8_t); // absolute voltage to gnd
    void begin(uint8_t, uint16_t, uint16_t); // absolute voltage to gnd with resolution and calibration

    void begin(uint8_t, uint8_t); // relative voltage between two ports
    void begin(uint8_t, uint8_t, uint16_t, uint16_t); // relative voltage between two ports with resolution and calibration

    void setResolution(uint8_t); // set the ADC resolution in bits
    void calibrate(float); // calibrate

    void set_filter(float);
    float filter(float);

    int32_t get(void); // get the value from port 1
    int32_t get(uint8_t); // get the value from port by type

  private:
    uint8_t _port_1;
    int8_t _port_2;

    uint16_t _max_val; // maximal DAC value
    float _cal; // calibration value

    float _Tf;
    float _y_prev;
    uint32_t _timestamp_prev;

};


/*
 * VALUE CLASS
 *
 * package format
 *    package[4]
 *      byte 0: bit 3-7 = index
 *              bit 0-2 = percentage HIGH (bits 8-10)
 *      byte 1: bit 0-7 = percentage LOW (bits 0-7)
 *      byte 2: reference HIGH
 *      byte 3: reference LOW
 */
class MEASURE_VALUE {

  public:
    // begin = true: index available, value set
    bool begin(uint16_t reference);     // init and set reference value
    bool begin(uint16_t reference, uint8_t index);   // init with additional index

    void set(uint32_t value);           // set absolute value
    void set_package(char* package);    // set from 4 byte package
    char* get_package(void);            // get data as 4 byte package

    uint16_t percent(void);             // get percent of reference value (11 bit)
    uint16_t value(void);               // get absolute value (16 bit)
    uint8_t index(void);                // get index

  private:
    uint16_t _percentage;  // 11 bit used: 1/10 percent 0-205% = 0-2048
    uint8_t _index;        // index for similar values 0-255 (0=default)
    uint16_t _reference;   // 16 bit reference value

};

#endif