//
// Created by mateusberardo on 14/03/2021.
//

#ifndef SIMULADOR_DIVINSTRUCTION_H
#define SIMULADOR_DIVINSTRUCTION_H

#include <memory.h>
#include <stdint-gcc.h>
#include "typetwoinstruction.h"

class DivInstruction : public TypeTwoInstruction {
public:
    DivInstruction(uint16_t *pc, int16_t *accumulator, Memory *memory);
    void process() override;
};


#endif //SIMULADOR_DIVINSTRUCTION_H
