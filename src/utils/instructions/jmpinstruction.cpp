//
// Created by mateusberardo on 18/03/2021.
//

#include "jmpinstruction.h"

JmpInstruction::JmpInstruction(uint16_t *pc,
                               int16_t *accumulator, Memory *memory)
        : TypeTwoInstruction(pc, accumulator, memory) {

}

void JmpInstruction::process() {
    *pc = (*memory)[*pc+1];
}
