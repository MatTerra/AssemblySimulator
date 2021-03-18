//
// Created by mateusberardo on 18/03/2021.
//

#include "jmppinstruction.h"

JmppInstruction::JmppInstruction(uint16_t *pc,
                                 int16_t *accumulator, Memory *memory)
        : TypeTwoInstruction(pc, accumulator, memory) {

}

void JmppInstruction::process() {
    if (*accumulator > 0)
        *pc=(*memory)[*pc+1];
    else
        updatePC();
}
