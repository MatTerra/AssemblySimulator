//
// Created by mateusberardo on 13/03/2021.
//

#ifndef SIMULADOR_BASEINSTRUCTION_H
#define SIMULADOR_BASEINSTRUCTION_H

#include <uniwidth.h>
#include "memory.h"

class BaseInstruction {
public:
    BaseInstruction(uint16_t *pc, int16_t *accumulator, Memory *memory)
        :pc(pc), accumulator(accumulator), memory(memory){}
    virtual void process() = 0;

protected:
    uint16_t* pc;
    int16_t* accumulator;
    Memory* memory;

    virtual void updatePC() = 0;
};


#endif //SIMULADOR_BASEINSTRUCTION_H
