//
// Created by mateusberardo on 13/03/2021.
//

#include <loader.h>
#include <memory.h>
#include <processor.h>
#include <iostream>
#include <fstream>

std::string readFile(std::string filename);

void showExecutionInformation(Processor *processor);

void executeProgram(Processor *processor);

int main(int argc, char **argv){
    if (argc != 2) {
        std::cout << "Expected filename as single argument to executable!";
        return 1;
    }

    auto filename = std::string(argv[1]);

    auto extension = filename.substr(filename.find_last_of('.'));
    if (extension != ".obj"){
        std::cout << "Expected an .obj file!";
        return 1;
    }

    auto loader = new Loader(readFile(filename));
    auto memory = new Memory();

    uint16_t PC;
    PC = loader->load(memory);

    auto processor = new Processor(memory, PC);

    executeProgram(processor);

    return 0;
}

void executeProgram(Processor *processor) {
    while (!processor->isHalted()) {
        processor->cycle();
        showExecutionInformation(processor);
    }
}

void showExecutionInformation(Processor *processor) {
    std::cout << "PC <- " << processor->getProgramCounter() << std::endl;
    std::cout << "ACC <- " << processor->getAccumulator() << std::endl;
    std::cout << std::endl;
}

std::string readFile(std::string filename) {
    std::ifstream file(filename);
    return std::string ((std::istreambuf_iterator<char>(file)),
                        std::istreambuf_iterator<char>());
}
