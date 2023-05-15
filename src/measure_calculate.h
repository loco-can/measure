/*
 * LOCO-CAN measure calculate class
 * 
 * @author: Thomas H Winkler
 * @copyright: 2020
 * @lizence: GG0
 */


#ifndef MEASURE_CALUCULATE_H
#define MEASURE_CALUCULATE_H

#include "intelliValue.h"


class MEASURE_CALCULATE {

    public:

        void begin(void);                       // begin measuring 
        void reset(void);                       // reset value
        INTELLIVALUE get(void);                        // return measure value
        uint16_t percentage(void);              // get percentage


        // calculate value and return result
        INTELLIVALUE add_min(INTELLIVALUE val);   // calculate minimum
        INTELLIVALUE add_max(INTELLIVALUE val);   // calculate maximum
        INTELLIVALUE add_avr(INTELLIVALUE val);   // calculate average

    private:
        void _clone(INTELLIVALUE val);             // clone measure value without percentage

        INTELLIVALUE _value;
        uint8_t _i;
        uint8_t _avr_count;
};


#endif