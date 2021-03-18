//
// Created by mateusberardo on 13/03/2021.
//

#include "processor.h"

Processor::Processor(Memory *memory, uint16_t pc,
                     std::istream *input,
                     std::ostream *output)
    :memory(memory), programCounter(pc), accumulator(0), halted(false),
     input(input), output(output){
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
    } catch (HaltProcessorInterrupt &e){
        halted = true;
    } catch (IOInterrupt &ioInterrupt){
        std::string line;
        getline(*input, line);
        trim(line);
        if (!std::regex_match(line, std::regex("[0-6]{0,1}[0-9]{0,4}"))) {
            halted = true;
            throw std::invalid_argument(line);
        }
        int lineValue = std::stoi(line);
        if (lineValue>=65536) {
            halted = true;
            throw std::invalid_argument(std::to_string(lineValue));
        }
        (*memory)[ioInterrupt.getAddress()] = (int16_t) lineValue;
    }
}

bool Processor::isHalted() const {
    return halted;
}

