//
// Created by mateusberardo on 13/03/2021.
//

#include <loader.h>
#include <memory.h>
#include <processor.h>
#include <iostream>
#include <fstream>

bool DEBUG = false;

std::string readFile(std::string filename);

void showExecutionInformation(Processor *processor);

void executeProgram(Processor *processor);

int main(int argc, char **argv){

    if (argc < 2 || argc > 3) {
        std::cout << "Expected filename as single argument to executable!";
        return 1;
    }
    if (argc == 3) {
        if (std::string(argv[2]) == "-d")
            DEBUG = true;
        else
            std::cout << "Expected only filename or filename -d for debug!";
    }

    auto filename = std::string(argv[1]);

    auto extension = filename.substr(filename.find_last_of('.'));
    if (extension != ".obj"){
        std::cout << "Expected an .obj file!";
        return 1;
    }

    std::ofstream output;
    output.open(filename.substr(0, filename.find_last_of('.'))+".out") ;

    auto loader = new Loader(readFile(filename));
    auto memory = new Memory();

    uint16_t PC;
    PC = loader->load(memory);

    auto processor = new Processor(memory, PC, &std::cin, &output);

    executeProgram(processor);

    output.flush();
    output.close();

    return 0;
}

void executeProgram(Processor *processor) {
    std::string output;
    while (!processor->isHalted()) {
        try {
            output = processor->cycle();
            showExecutionInformation(processor);
            if (output != "")
                std::cout << "OUTPUT: " << output;
            std::cout << std::endl;
            if (DEBUG)
                getchar();
        } catch (std::exception) {
            std::cerr << "Algo deu errado ao processar o arquivo!"
                << "\nEncerrando a execução!" << std::endl;
        }
    }
}

void showExecutionInformation(Processor *processor) {
    std::cout << "PC <- " << processor->getProgramCounter() << std::endl;
    std::cout << "ACC <- " << processor->getAccumulator() << std::endl;
}

std::string readFile(std::string filename) {
    std::ifstream file(filename);
    return std::string ((std::istreambuf_iterator<char>(file)),
                        std::istreambuf_iterator<char>());
}
