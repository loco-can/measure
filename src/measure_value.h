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


#ifndef MEASURE_VALUE_H
#define MEASURE_VALUE_H


class MEASURE_VALUE {

  public:
    // begin = true: index available, value set
    bool begin(uint16_t reference);     // init and set reference value
    bool begin(uint16_t reference, uint8_t index);   // init with additional index

    void set(uint32_t value);           // set absolute value
    uint16_t get(void);                 // get absolute value

    void set_package(char* package);    // set from 4 byte package
    char* get_package(void);            // get data as 4 byte package

    uint16_t percentage(void);          // get percent of reference value (11 bit)
    void percentage(uint16_t);          // set percent of reference value (11 bit)

    uint16_t reference(void);           // get reference (16 bit)
    void reference(uint16_t);           // aet reference (16 bit)

    uint8_t index(void);                // get index
    void index(uint8_t);                // set index

  private:
    uint16_t _percentage;  // 11 bit used: 1/10 percent 0-205% = 0-2048
    uint8_t _index;        // index for similar values 0-255 (0=default)
    uint16_t _reference;   // 16 bit reference value

};

#endif