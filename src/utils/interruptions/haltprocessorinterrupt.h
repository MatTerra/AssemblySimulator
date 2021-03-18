//
// Created by mateusberardo on 18/03/2021.
//

#ifndef SIMULADOR_HALTPROCESSORINTERRUPT_H
#define SIMULADOR_HALTPROCESSORINTERRUPT_H

#include "baseinterrupt.h"

class HaltProcessorInterrupt : public BaseInterrupt {
public:
    explicit HaltProcessorInterrupt():BaseInterrupt('h'){}
};


#endif //SIMULADOR_HALTPROCESSORINTERRUPT_H
