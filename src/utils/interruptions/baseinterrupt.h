//
// Created by mateusberardo on 18/03/2021.
//

#ifndef SIMULADOR_BASEINTERRUPT_H
#define SIMULADOR_BASEINTERRUPT_H

#include <stdexcept>

class BaseInterrupt : public std::exception {
public:
    explicit BaseInterrupt(char command): command(command) { }
    char getCommand() const { return command; }
private:
    char command;
};


#endif //SIMULADOR_BASEINTERRUPT_H
