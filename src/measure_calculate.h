/*
 * LOCO-CAN measure calculate class
 * 
 * @author: Thomas H Winkler
 * @copyright: 2020
 * @lizence: GG0
 */


#ifndef MEASURE_CALUCULATE_H
#define MEASURE_CALUCULATE_H

#include "value.h"


class MEASURE_CALCULATE {

    public:

        void begin(void);                       // begin measuring 
        void reset(void);                       // reset value
        VALUE get(void);                        // return measure value
        uint16_t percentage(void);              // get percentage


        // calculate value and return result
        VALUE add_min(VALUE val);   // calculate minimum
        VALUE add_max(VALUE val);   // calculate maximum
        VALUE add_avr(VALUE val);   // calculate average

    private:
        void _clone(VALUE val);             // clone measure value without percentage

        VALUE _value;
        uint8_t _i;
        uint8_t _avr_count;
};


#endif