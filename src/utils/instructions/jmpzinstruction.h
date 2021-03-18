//
// Created by mateusberardo on 18/03/2021.
//

#ifndef SIMULADOR_JMPZINSTRUCTION_H
#define SIMULADOR_JMPZINSTRUCTION_H

#include <memory.h>
#include "typetwoinstruction.h"

class JmpzInstruction : public TypeTwoInstruction {
public:
    JmpzInstruction(uint16_t* pc, int16_t* accumulator, Memory* memory);
    void process() override;

};


#endif //SIMULADOR_JMPZINSTRUCTION_H
