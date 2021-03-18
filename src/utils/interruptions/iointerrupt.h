//
// Created by mateusberardo on 18/03/2021.
//

#ifndef SIMULADOR_IOINTERRUPT_H
#define SIMULADOR_IOINTERRUPT_H

#include "baseinterrupt.h"

class IOInterrupt : public BaseInterrupt {
public:
    IOInterrupt(char command, uint16_t address)
        : BaseInterrupt(command), address(address){}
    uint16_t getAddress() const { return address; }
private:
    uint16_t address;

};


#endif //SIMULADOR_IOINTERRUPT_H
