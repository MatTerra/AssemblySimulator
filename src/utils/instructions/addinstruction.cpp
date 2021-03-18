//
// Created by mateusberardo on 13/03/2021.
//

#include "addinstruction.h"

AddInstruction::AddInstruction(uint16_t *pc, int16_t *accumulator, Memory *memory)
    :TypeTwoInstruction(pc, accumulator, memory){

}

void AddInstruction::process() {
    uint16_t operandAddress = (*memory)[(*pc + 1)];
    *accumulator += (*memory)[operandAddress];

    updatePC();
}
