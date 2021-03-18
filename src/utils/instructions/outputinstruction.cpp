//
// Created by mateusberardo on 18/03/2021.
//

#include "outputinstruction.h"

OutputInstruction::OutputInstruction(uint16_t *pc,
                                   int16_t *accumulator, Memory *memory)
        : TypeTwoInstruction(pc, accumulator, memory) {

}

void OutputInstruction::process() {
    uint16_t outputAddr = (*memory)[*pc+1];
    updatePC();
    throw IOInterrupt('o', outputAddr);
}
