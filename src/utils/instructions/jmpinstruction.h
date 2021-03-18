//
// Created by mateusberardo on 18/03/2021.
//

#ifndef SIMULADOR_JMPINSTRUCTION_H
#define SIMULADOR_JMPINSTRUCTION_H

#include <memory.h>
#include "typetwoinstruction.h"

class JmpInstruction : public TypeTwoInstruction {
public:
    JmpInstruction(uint16_t* pc, int16_t* accumulator, Memory* memory);
    void process() override;
};


#endif //SIMULADOR_JMPINSTRUCTION_H
