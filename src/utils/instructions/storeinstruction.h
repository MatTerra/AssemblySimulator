//
// Created by mateusberardo on 18/03/2021.
//

#ifndef SIMULADOR_STOREINSTRUCTION_H
#define SIMULADOR_STOREINSTRUCTION_H

#include <memory.h>
#include "typetwoinstruction.h"

class StoreInstruction : public TypeTwoInstruction  {
public:
    StoreInstruction(uint16_t* pc, int16_t* accumulator, Memory* memory);
    void process() override;
};


#endif //SIMULADOR_STOREINSTRUCTION_H
