//
// Created by mateusberardo on 18/03/2021.
//

#ifndef SIMULADOR_JMPNINSTRUCTION_H
#define SIMULADOR_JMPNINSTRUCTION_H

#include "typetwoinstruction.h"
#include <memory.h>

class JmpnInstruction : public TypeTwoInstruction {
public:
    JmpnInstruction(uint16_t* pc, int16_t* accumulator, Memory* memory);
    void process() override;
};


#endif //SIMULADOR_JMPNINSTRUCTION_H
