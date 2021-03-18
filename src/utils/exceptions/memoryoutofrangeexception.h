//
// Created by mateusberardo on 13/03/2021.
//

#ifndef SIMULADOR_MEMORYOUTOFRANGEEXCEPTION_H
#define SIMULADOR_MEMORYOUTOFRANGEEXCEPTION_H


#include <stdexcept>

class MemoryOutOfRangeException : public std::runtime_error {
public:
    explicit MemoryOutOfRangeException(const std::string& what_arg)
            :std::runtime_error(what_arg){}

};


#endif //SIMULADOR_MEMORYOUTOFRANGEEXCEPTION_H
