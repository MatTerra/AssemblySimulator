//
// Created by mateusberardo on 13/03/2021.
//

#ifndef SIMULADOR_LOADER_H
#define SIMULADOR_LOADER_H


#include <string>
#include <utility>
#include <uniwidth.h>
#include "memory.h"

class Loader {

public:
    explicit Loader(std::string memoryContent)
        :memoryContent(std::move(memoryContent)) {}
    uint16_t load(Memory *memory, uint16_t startingAddr=0);

private:
    std::string memoryContent;

};


#endif //SIMULADOR_LOADER_H
