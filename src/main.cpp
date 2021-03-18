//
// Created by mateusberardo on 13/03/2021.
//

#include <loader.h>
#include <memory.h>
#include <processor.h>

int main(){
    auto loader = new Loader("01 04 02 05 1 -1");
    auto memory = new Memory();

    uint16_t PC;
    PC = loader->load(memory);

    auto processor = new Processor(memory, PC);
    return 0;
}