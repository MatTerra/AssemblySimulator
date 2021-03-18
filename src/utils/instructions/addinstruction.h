//
// Created by mateusberardo on 13/03/2021.
//

#ifndef SIMULADOR_ADDINSTRUCTION_H
#define SIMULADOR_ADDINSTRUCTION_H

#include <memory.h>
#include <stdint-gcc.h>
#include "typetwoinstruction.h"

class AddInstruction : public TypeTwoInstruction {
public:
    AddInstruction(uint16_t *pc, int16_t *accumulator, Memory *memory);
    void process() override;
};


#endif //SIMULADOR_ADDINSTRUCTION_H
