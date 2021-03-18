//
// Created by mateusberardo on 18/03/2021.
//

#include "loadinstruction.h"

LoadInstruction::LoadInstruction(uint16_t *pc,
                                 int16_t *accumulator, Memory *memory)
        : TypeTwoInstruction(pc, accumulator, memory) {

}

void LoadInstruction::process() {
    uint16_t loadAddress = (*memory)[*pc+1];
    *accumulator = (*memory)[loadAddress];
    updatePC();
}
