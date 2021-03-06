//
// Created by mateusberardo on 13/03/2021.
//

#ifndef SIMULADOR_PROCESSOR_H
#define SIMULADOR_PROCESSOR_H

#include <iostream>
#include <regex>
#include <stdint.h>
#include <instructions/baseinstruction.h>
#include <exceptions/invalidopcodeexception.h>
#include <exceptions/processorhaltedexception.h>
#include <exceptions/memoryoutofrangeexception.h>
#include <interruptions/iointerrupt.h>
#include "memory.h"
#include "baseinstructionfactory.h"
#include "stringutils.h"

class Processor {

public:
    explicit Processor(Memory *memory, uint16_t pc=0,
                       std::istream *input=&std::cin,
                       std::ostream *output=&std::cout);
    int16_t getAccumulator() const;
    uint16_t getProgramCounter() const;
    Memory *getMemory();

    std::string cycle();

    bool isHalted() const;

private:
    Memory *memory;
    uint16_t programCounter;
    int16_t accumulator;
    BaseInstructionFactory<BaseInstruction> *instructionFactory;
    bool halted;
    std::istream *input;
    std::ostream *output;
    void getInput(uint16_t destAddr);
    std::string showOutput(uint16_t);
    std::string executeIOOperation(char command, uint16_t ioAddr);
};


#endif //SIMULADOR_PROCESSOR_H
