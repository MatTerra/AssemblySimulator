//
// Created by mateusberardo on 13/03/2021.
//

#ifndef SIMULADOR_TYPETHREEINSTRUCTION_H
#define SIMULADOR_TYPETHREEINSTRUCTION_H

#include "baseinstruction.h"

class TypeThreeInstruction : public BaseInstruction {
public:
    TypeThreeInstruction(uint16_t *pc, int16_t *accumulator, Memory *memory)
        :BaseInstruction(pc, accumulator, memory){}
    virtual void process() = 0;

protected:
    void updatePC() override{ *pc += 3; }
};


#endif //SIMULADOR_TYPETHREEINSTRUCTION_H
