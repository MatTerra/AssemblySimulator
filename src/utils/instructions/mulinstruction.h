//
// Created by mateusberardo on 14/03/2021.
//

#ifndef SIMULADOR_MULINSTRUCTION_H
#define SIMULADOR_MULINSTRUCTION_H

#include <memory.h>
#include <stdint-gcc.h>
#include "typetwoinstruction.h"

class MulInstruction : public TypeTwoInstruction {
public:
    MulInstruction(uint16_t *pc, int16_t *accumulator, Memory *memory);
    void process() override;
};


#endif //SIMULADOR_MULINSTRUCTION_H
