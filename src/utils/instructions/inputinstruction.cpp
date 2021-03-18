//
// Created by mateusberardo on 18/03/2021.
//

#include "inputinstruction.h"

InputInstruction::InputInstruction(uint16_t *pc,
                                   int16_t *accumulator, Memory *memory)
        : TypeTwoInstruction(pc, accumulator, memory) {

}

void InputInstruction::process() {
    uint16_t inputAddr = (*memory)[*pc+1];
    updatePC();
    throw IOInterrupt('i', inputAddr);
}
