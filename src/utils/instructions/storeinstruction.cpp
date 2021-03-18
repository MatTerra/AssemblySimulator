//
// Created by mateusberardo on 18/03/2021.
//

#include "storeinstruction.h"

StoreInstruction::StoreInstruction(uint16_t *pc,
                                   int16_t *accumulator, Memory *memory)
        : TypeTwoInstruction(pc, accumulator, memory) {

}

void StoreInstruction::process() {
    uint16_t storeAddress = (*memory)[*pc+1];
    (*memory)[storeAddress] = *accumulator;
    updatePC();
}
