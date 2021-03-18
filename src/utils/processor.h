//
// Created by mateusberardo on 13/03/2021.
//

#ifndef SIMULADOR_PROCESSOR_H
#define SIMULADOR_PROCESSOR_H


#include <uniwidth.h>
#include <instructions/baseinstruction.h>
#include "memory.h"
#include "baseinstructionfactory.h"

class Processor {

public:
    explicit Processor(Memory *memory, uint16_t pc=0);
    int16_t getAccumulator();
    uint16_t getProgramCounter() const;
    Memory *getMemory();

    void cycle();

    bool isHalted() const;

private:
    Memory *memory;
    uint16_t programCounter;
    int16_t accumulator;
    BaseInstructionFactory<BaseInstruction> *instructionFactory;
    bool halted;
};


#endif //SIMULADOR_PROCESSOR_H
