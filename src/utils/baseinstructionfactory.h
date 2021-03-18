//
// Created by mateusberardo on 13/03/2021.
//

#ifndef MONTADOR_BASEINSTRUCTIONFACTORY_H
#define MONTADOR_BASEINSTRUCTIONFACTORY_H

#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <instructions/baseinstruction.h>
#include <instructions/addinstruction.h>
#include <instructions/subinstruction.h>
#include <instructions/mulinstruction.h>
#include <instructions/divinstruction.h>
#include <instructions/jmpinstruction.h>
#include <instructions/jmpninstruction.h>
#include <instructions/jmppinstruction.h>
#include <instructions/jmpzinstruction.h>
#include <instructions/copyinstruction.h>
#include <instructions/loadinstruction.h>
#include <instructions/storeinstruction.h>
#include <instructions/inputinstruction.h>
//#include <instructions/outputinstruction.h>
#include <instructions/stopinstruction.h>

template <typename T>
class BaseInstructionFactory {

public:
    template <typename TDerived>
    void registerType(int16_t opcode)
    {
        static_assert(std::is_base_of<T, TDerived>::value,
                "Factory::registerType doesn't accept this"
                " type because doesn'T derive from base class");
        _createFuncs[opcode] = &createFunc<TDerived>;
    }

    T* create(int16_t opcode, uint16_t *pc, int16_t *accumulator,
              Memory *memory) {
        if (_createFuncs.find(opcode) != _createFuncs.end()) {
            return _createFuncs[opcode](pc, accumulator, memory);
        }
        return nullptr;
    }


private:
    template <typename TDerived>
    static T* createFunc(uint16_t *pc, int16_t *accumulator, Memory *memory)
    {
        return (BaseInstruction *)new TDerived(pc, accumulator, memory);
    }

    typedef T* (*PCreateFunc)(uint16_t *, int16_t *, Memory *);
    std::unordered_map<int16_t, PCreateFunc> _createFuncs;
};

static BaseInstructionFactory<BaseInstruction> *getBaseInstructionFactory(){
    auto *instFactory = new BaseInstructionFactory<BaseInstruction>();
    instFactory->registerType<AddInstruction>(1);
    instFactory->registerType<SubInstruction>(2);
    instFactory->registerType<MulInstruction>(3);
    instFactory->registerType<DivInstruction>(4);
    instFactory->registerType<JmpInstruction>(5);
    instFactory->registerType<JmpnInstruction>(6);
    instFactory->registerType<JmppInstruction>(7);
    instFactory->registerType<JmpzInstruction>(8);
    instFactory->registerType<CopyInstruction>(9);
    instFactory->registerType<LoadInstruction>(10);
    instFactory->registerType<StoreInstruction>(11);
    instFactory->registerType<InputInstruction>(12);
//    instFactory->registerType<OutputInstruction>(13);
    instFactory->registerType<StopInstruction>(14);
    return instFactory;
}


#endif //MONTADOR_BASEINSTRUCTIONFACTORY_H
