//
// Created by mateusberardo on 18/03/2021.
//

#include "stopinstruction.h"

StopInstruction::StopInstruction(uint16_t *pc,
                                 int16_t *accumulator, Memory *memory)
        : TypeOneInstruction(pc, accumulator, memory) {

}

void StopInstruction::process() {
    throw HaltProcessorInterrupt();
}
