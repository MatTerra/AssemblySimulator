//
// Created by mateusberardo on 18/03/2021.
//

#ifndef SIMULADOR_PROCESSORHALTEDEXCEPTION_H
#define SIMULADOR_PROCESSORHALTEDEXCEPTION_H

class ProcessorHaltedException : public std::runtime_error {
public:
    explicit ProcessorHaltedException(const std::string& what_arg)
            :std::runtime_error(what_arg){}
};

#endif //SIMULADOR_PROCESSORHALTEDEXCEPTION_H
