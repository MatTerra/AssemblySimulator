//
// Created by mateusberardo on 13/03/2021.
//

#ifndef SIMULADOR_TYPEONEINSTRUCTION_H
#define SIMULADOR_TYPEONEINSTRUCTION_H

#include "baseinstruction.h"

class TypeOneInstruction : public BaseInstruction {
public:
    TypeOneInstruction(uint16_t *pc, int16_t *accumulator, Memory *memory)
        :BaseInstruction(pc, accumulator, memory){}
    virtual void process() = 0;

protected:
    void updatePC() override{ *pc += 1; }
};


#endif //SIMULADOR_TYPEONEINSTRUCTION_H
