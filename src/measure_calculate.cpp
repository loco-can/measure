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
    Serial.println("reset");
    _value.percentage(0);
    _avr_count = 0;
}


// calculate minimum
VALUE MEASURE_CALCULATE::add_min(VALUE val) {

    _avr_count = 0;

    // init percentage for minimum
    if (_value.percentage() == 0) {
        _value.percentage(val.percentage());
    }

    _clone(val);

    if (_value.percentage() > val.percentage()) {
        _value.percentage(val.percentage());
    }

    return _value;
}


// calculate maximum
VALUE MEASURE_CALCULATE::add_max(VALUE val) {

    _avr_count = 0;

    _clone(val);

    if (_value.percentage() < val.percentage()) {
        _value.percentage(val.percentage());
    }

    return _value;
}


// calculate average (max 32 values)
VALUE MEASURE_CALCULATE::add_avr(VALUE val) {

    _clone(val);

    if (_avr_count < 32) {
        _value.percentage(_value.percentage() + val.percentage());
        _avr_count++;
    }

    else {
        reset();
    }

    return _value;
}


void MEASURE_CALCULATE::_clone(VALUE val) {

    _value.reference(val.reference());
    _value.index(val.index());
}


VALUE MEASURE_CALCULATE::get(void) {

}


uint16_t MEASURE_CALCULATE::percentage(void) {

    if (_avr_count != 0) {
        return _value.percentage() / _avr_count;
    }

    return _value.percentage();
}