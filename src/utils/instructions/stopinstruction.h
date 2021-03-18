//
// Created by mateusberardo on 18/03/2021.
//

#ifndef SIMULADOR_STOPINSTRUCTION_H
#define SIMULADOR_STOPINSTRUCTION_H

#include <memory.h>
#include <exceptions/haltprocessorexception.h>
#include "typeoneinstruction.h"

class StopInstruction : public TypeOneInstruction {
public:
    StopInstruction(uint16_t* pc, int16_t* accumulator, Memory* memory);
    void process() override;
};


#endif //SIMULADOR_STOPINSTRUCTION_H
