//
// Created by mateusberardo on 13/03/2021.
//

#ifndef SIMULADOR_MEMORY_H
#define SIMULADOR_MEMORY_H


#include <cstdint>

class Memory {
public:
    explicit Memory(uint16_t i=216);

    int16_t& operator[](uint16_t pos);

private:
    uint16_t capacity;
    int16_t memory[65536] = {};

};


#endif //SIMULADOR_MEMORY_H
