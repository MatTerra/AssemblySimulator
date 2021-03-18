//
// Created by mateusberardo on 14/03/2021.
//

#include "mulinstruction.h"

MulInstruction::MulInstruction(uint16_t *pc,
                               int16_t *accumulator, Memory *memory)
        : TypeTwoInstruction(pc, accumulator, memory) {

}

void MulInstruction::process() {
    uint16_t operandAddress = (*memory)[(*pc + 1)];
    *accumulator *= (*memory)[operandAddress];

    updatePC();
}


