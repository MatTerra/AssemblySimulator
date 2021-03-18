//
// Created by mateusberardo on 13/03/2021.
//

#include <exceptions/memoryoutofrangeexception.h>
#include "memory.h"

int16_t &Memory::operator[](uint16_t pos) {
    if (pos >= capacity)
        throw MemoryOutOfRangeException(std::to_string(pos));
    return memory[pos];
}

Memory::Memory(uint16_t capacity) : capacity(capacity) {

}
