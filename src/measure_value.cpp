/*
 * LOCO-CAN maesure value class
 * 
 * @author: Thomas H Winkler
 * @copyright: 2023
 * @lizence: GG0
 */

#include <Arduino.h>
#include "measure_value.h"


/*
 * init measure value with reference
 */
bool MEASURE_VALUE::begin(uint16_t reference) {
    begin(reference, 0);

    return true;
}


bool MEASURE_VALUE::begin(uint16_t reference, uint8_t index) {
    _reference = reference;

    if (index < 32) {
        _index = index;
        return true;
    }

    _index = 0;
    return false;
}


void MEASURE_VALUE::set(uint32_t value) {
    _percentage = ((value / _reference) * 100) >> 5;
}


// get absolute value
uint16_t MEASURE_VALUE::get(void) {
    return (uint16_t)(((uint32_t)_percentage * (uint32_t)_reference) / 100);
}


// set values from message package
void MEASURE_VALUE::set_package(char* package) {
    _percentage = package[1] | ((package[0] & 0x07) >> 8);
    _index = package[0] >> 5;
    _reference = (package[2] << 8) | package[3];
}


// get package from values
char* MEASURE_VALUE::get_package(void) {
    uint8_t data[4];

    data[0] = (_index << 5) | (_percentage >> 8);
    data[1] = _percentage & 0xff;
    data[2] = _reference >> 8;
    data[3] = _reference & 0xff;

    return data;
}


// get percentage
uint16_t MEASURE_VALUE::percentage(void) {
    return _percentage;
}

// set percentage
void MEASURE_VALUE::percentage(uint16_t val) {
    _percentage = val & 0b11111111111;
}


// get reference value
uint16_t MEASURE_VALUE::reference(void) {
    return _reference;
}

// set reference value
void MEASURE_VALUE::reference(uint16_t val) {
    _reference = val;
}


// get index
uint8_t MEASURE_VALUE::index(void) {
    return _index;
}

// set index
void MEASURE_VALUE::index(uint8_t val) {
    _index = val;
}