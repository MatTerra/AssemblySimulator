//
// Created by mateusberardo on 13/03/2021.
//

#include "loader.h"

uint16_t Loader::load(Memory *memory, uint16_t startAddr) {
    size_t nextSpace = 0;
    size_t lastSpace = 0;
    uint16_t addr = startAddr;

    while (nextSpace != std::string::npos) {
        nextSpace = memoryContent.find(' ', lastSpace+1);

        (*memory)[addr++] = std::stoi(
                memoryContent.substr(lastSpace, nextSpace-lastSpace));

        lastSpace=nextSpace;
    }

    return startAddr;
}
