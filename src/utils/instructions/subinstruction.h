//
// Created by mateusberardo on 13/03/2021.
//

#ifndef SIMULADOR_SUBINSTRUCTION_H
#define SIMULADOR_SUBINSTRUCTION_H

#include <memory.h>
#include <stdint-gcc.h>
#include "typetwoinstruction.h"

class SubInstruction : public TypeTwoInstruction {
public:
    SubInstruction(uint16_t *pc, int16_t *accumulator, Memory *memory);
    void process() override;
};


#endif //SIMULADOR_SUBINSTRUCTION_H
