//
// Created by mateusberardo on 18/03/2021.
//

#ifndef SIMULADOR_LOADINSTRUCTION_H
#define SIMULADOR_LOADINSTRUCTION_H

#include <memory.h>
#include "typetwoinstruction.h"

class LoadInstruction : public TypeTwoInstruction {
public:
    LoadInstruction(uint16_t* pc, int16_t* accumulator, Memory* memory);
    void process() override;

};


#endif //SIMULADOR_LOADINSTRUCTION_H
