//
// Created by mateusberardo on 18/03/2021.
//

#ifndef SIMULADOR_INPUTINSTRUCTION_H
#define SIMULADOR_INPUTINSTRUCTION_H

#include <memory.h>
#include <interruptions/iointerrupt.h>
#include "typetwoinstruction.h"

class InputInstruction : public TypeTwoInstruction {
public:
    InputInstruction(uint16_t* pc, int16_t* accumulator, Memory* memory);
    void process() override;
};


#endif //SIMULADOR_INPUTINSTRUCTION_H
