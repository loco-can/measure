/*
 * LOCO-CAN measure calculate class
 * 
 * @author: Thomas H Winkler
 * @copyright: 2020
 * @lizence: GG0
 */


#ifndef MEASURE_CALUCULATE_H
#define MEASURE_CALUCULATE_H

#include "measure_value.h"


class MEASURE_CALCULATE {

    public:

        void begin(void);                       // begin measuring 
        void reset(void);                       // reset value

        // calculate value and return result
        MEASURE_VALUE add_min(MEASURE_VALUE val);   // calculate minimum
        MEASURE_VALUE add_max(MEASURE_VALUE val);   // calculate maximum
        MEASURE_VALUE add_avr(MEASURE_VALUE val);   // calculate average

    private:
        void _clone(MEASURE_VALUE val);             // clone measure value without percentage

        MEASURE_VALUE _value;
        uint8_t _i;
};


#endif