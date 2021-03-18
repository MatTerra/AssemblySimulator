//
// Created by mateusberardo on 18/03/2021.
//

#include "copyinstruction.h"

CopyInstruction::CopyInstruction(uint16_t *pc,
                                 int16_t *accumulator, Memory *memory)
        : TypeThreeInstruction(pc, accumulator, memory) {

}

void CopyInstruction::process() {
    uint16_t destAddress = (*memory)[*pc+2];
    uint16_t originAddress = (*memory)[*pc+1];
    (*memory)[destAddress] = (*memory)[originAddress];
    updatePC();
}
