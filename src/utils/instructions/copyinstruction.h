//
// Created by mateusberardo on 18/03/2021.
//

#ifndef SIMULADOR_COPYINSTRUCTION_H
#define SIMULADOR_COPYINSTRUCTION_H

#include "typethreeinstruction.h"
#include <memory.h>

class CopyInstruction : public TypeThreeInstruction {
public:
    CopyInstruction(uint16_t* pc, int16_t* accumulator, Memory* memory);
    void process() override;
};


#endif //SIMULADOR_COPYINSTRUCTION_H
