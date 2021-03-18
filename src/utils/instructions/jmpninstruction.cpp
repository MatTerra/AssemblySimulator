//
// Created by mateusberardo on 18/03/2021.
//

#include "jmpninstruction.h"

JmpnInstruction::JmpnInstruction(uint16_t *pc,
                                 int16_t *accumulator, Memory *memory)
        : TypeTwoInstruction(pc, accumulator, memory) {

}

void JmpnInstruction::process() {
    if (*accumulator < 0)
        *pc = (*memory)[*pc+1];
    else
        updatePC();
}
