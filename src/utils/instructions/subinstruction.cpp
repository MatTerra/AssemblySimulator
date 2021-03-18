//
// Created by mateusberardo on 13/03/2021.
//

#include "subinstruction.h"

SubInstruction::SubInstruction(uint16_t *pc, int16_t *accumulator, Memory *memory)
    :TypeTwoInstruction(pc, accumulator, memory){

}

void SubInstruction::process() {
    uint16_t operandAddress = (*memory)[(*pc + 1)];
    *accumulator -= (*memory)[operandAddress];

    updatePC();
}
