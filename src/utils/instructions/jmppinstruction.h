//
// Created by mateusberardo on 18/03/2021.
//

#ifndef SIMULADOR_JMPPINSTRUCTION_H
#define SIMULADOR_JMPPINSTRUCTION_H

#include <memory.h>
#include "typetwoinstruction.h"

class JmppInstruction : public TypeTwoInstruction {
public:
    JmppInstruction(uint16_t* pc, int16_t* accumulator, Memory* memory);
    void process() override;

};


#endif //SIMULADOR_JMPPINSTRUCTION_H
