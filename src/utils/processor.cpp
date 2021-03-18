//
// Created by mateusberardo on 13/03/2021.
//

#include <exceptions/invalidopcodeexception.h>
#include <exceptions/processorhaltedexception.h>
#include <exceptions/memoryoutofrangeexception.h>
#include "processor.h"

Processor::Processor(Memory *memory, uint16_t pc)
    :memory(memory), programCounter(pc), accumulator(0), halted(false){
    instructionFactory = getBaseInstructionFactory();
}

int16_t Processor::getAccumulator() {
    return accumulator;
}

uint16_t Processor::getProgramCounter() const {
    return programCounter;
}

Memory *Processor::getMemory() {
    return memory;
}

void Processor::cycle() {
    try {
        if (halted)
            throw ProcessorHaltedException(std::to_string(programCounter));

        auto opcode = (*memory)[programCounter];
        auto instruction = instructionFactory->create(opcode, &programCounter,
                                                      &accumulator, memory);
        if (instruction == nullptr) {
            halted = true;
            throw InvalidOpcodeException(std::to_string(opcode));
        }

        instruction->process();
    } catch (MemoryOutOfRangeException &exception) {
        halted = true;
        throw exception;
    } catch (HaltProcessorException){
        halted = true;
    }
}

bool Processor::isHalted() const {
    return halted;
}

