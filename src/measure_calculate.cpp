/*
 * LOCO-CAN measure calculate class
 * 
 * @author: Thomas H Winkler
 * @copyright: 2020
 * @lizence: GG0
 */

#include <Arduino.h>
#include "measure_calculate.h"


void MEASURE_CALCULATE::begin(void) {
    reset();
}


// reset value
void MEASURE_CALCULATE::reset(void) {
    _value.percentage(0);
}


// calculate minimum
MEASURE_VALUE MEASURE_CALCULATE::add_min(MEASURE_VALUE val) {

    _clone(val);

    if (_value.percentage() > val.percentage()) {
        _value.percentage(val.percentage());
    }

    return _value;
}


// calculate maximum
MEASURE_VALUE MEASURE_CALCULATE::add_max(MEASURE_VALUE val) {

    _clone(val);

    if (_value.percentage() < val.percentage()) {
        _value.percentage(val.percentage());
    }

    return _value;
}


// calculate average
MEASURE_VALUE MEASURE_CALCULATE::add_avr(MEASURE_VALUE val) {

    _clone(val);

    _value.percentage((uint16_t)(((uint32_t)_value.percentage() + (uint32_t)val.percentage()) / 2));

    return _value;
}


void MEASURE_CALCULATE::_clone(MEASURE_VALUE val) {

    _value.reference(val.reference());
    _value.index(val.index());
}