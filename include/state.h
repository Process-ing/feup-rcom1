#ifndef _STATE_H_
#define _STATE_H_

#include <stdint.h>

typedef enum {
    STATE_START,
    STATE_FLAG_RCV,
    STATE_A_RCV,
    STATE_C_RCV,
    STATE_SET_C_RCV,
    STATE_DISC_C_RCV,
    STATE_BCC1_OK,
    STATE_SET_BCC1_OK,
    STATE_DISC_BCC1_OK,
    STATE_DATA,
    STATE_DATA_ESC,
    STATE_DATA_STUFF,
    STATE_DATA_WRT_STUFF,
    STATE_DATA_ESC_WRT_STUFF,
    STATE_STOP,
    STATE_STOP_SET,
    STATE_STOP_DISC,
    STATE_BCC2_BAD,
    STATE_STUFF_BAD,
} State;

// Returns true if the given state is a data state, and false otherwise.
int isDataState(State state);

// Calculates the next state, in the parsing of a S/U frame.
State nextSOrUFrameState(State state, uint8_t byte, uint8_t addressField, uint8_t *controlField);

// Calculates the next state, in the parsing of an I frame.
State nextIFrameState(State state, uint8_t byte, uint8_t addressField, uint8_t *frameNumber, uint8_t xor);

#endif  // _STATE_H_
