//
// Created by mateusberardo on 13/03/2021.
//

#ifndef SIMULADOR_INVALIDOPCODEEXCEPTION_H
#define SIMULADOR_INVALIDOPCODEEXCEPTION_H


#include <stdexcept>

class InvalidOpcodeException : public std::runtime_error {
public:
    explicit InvalidOpcodeException(const std::string& what_arg)
        :std::runtime_error(what_arg){}

};


#endif //SIMULADOR_InvalidOpcodeEXCEPTION_H
