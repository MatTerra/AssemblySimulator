//
// Created by mateusberardo on 13/03/2021.
//

#ifndef SIMULADOR_TYPETWOINSTRUCTION_H
#define SIMULADOR_TYPETWOINSTRUCTION_H

#include "baseinstruction.h"

class TypeTwoInstruction : public BaseInstruction {
public:
    virtual void process() = 0;

    TypeTwoInstruction(uint16_t *pc, int16_t *accumulator, Memory *memory)
        :BaseInstruction(pc, accumulator, memory){}

protected:
    void updatePC() override{ *pc += 2; }
};


#endif //SIMULADOR_TYPETWOINSTRUCTION_H
