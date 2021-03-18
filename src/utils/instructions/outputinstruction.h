//
// Created by mateusberardo on 18/03/2021.
//

#ifndef SIMULADOR_OUTPUTINSTRUCTION_H
#define SIMULADOR_OUTPUTINSTRUCTION_H

#include <memory.h>
#include <interruptions/iointerrupt.h>
#include "typetwoinstruction.h"

class OutputInstruction : public TypeTwoInstruction {
public:
    OutputInstruction(uint16_t* pc, int16_t* accumulator, Memory* memory);
    void process() override;
};


#endif //SIMULADOR_OUTPUTINSTRUCTION_H
