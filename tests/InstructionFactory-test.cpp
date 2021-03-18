//
// Created by mateusberardo on 14/03/2021.
//
#include "gtest/gtest.h"
#include <baseinstructionfactory.h>

TEST(BaseInstructionFactory, may_get_instruction_factory){
    auto instFactory = getBaseInstructionFactory();
    ASSERT_NE(nullptr, instFactory);
}

TEST(BaseInstructionFactory_Add, unknown_returns_nullptr){
    uint16_t pc=0;
    int16_t accumulator=0;
    auto memory = new Memory();
    auto instFactory = getBaseInstructionFactory();
    auto nullI = instFactory->create(100, &pc, &accumulator, memory);
    ASSERT_EQ(nullptr, nullI);
}

TEST(BaseInstructionFactory_Add, may_get_add_instruction){
    uint16_t pc=0;
    int16_t accumulator=0;
    auto memory = new Memory();
    auto instFactory = getBaseInstructionFactory();
    auto add = instFactory->create(1, &pc, &accumulator, memory);
    ASSERT_NE(nullptr, add);
}

TEST(BaseInstructionFactory_Sub, may_get_sub_instruction){
    uint16_t pc=0;
    int16_t accumulator=0;
    auto memory = new Memory();
    auto instFactory = getBaseInstructionFactory();
    auto sub = instFactory->create(2, &pc, &accumulator, memory);
    ASSERT_NE(nullptr, sub);
}

TEST(BaseInstructionFactory_Mul, may_get_mul_instruction){
    uint16_t pc=0;
    int16_t accumulator=0;
    auto memory = new Memory();
    auto instFactory = getBaseInstructionFactory();
    auto mul = instFactory->create(3, &pc, &accumulator, memory);
    ASSERT_NE(nullptr, mul);
}

TEST(BaseInstructionFactory_div, may_get_div_instruction){
    uint16_t pc=0;
    int16_t accumulator=0;
    auto memory = new Memory();
    auto instFactory = getBaseInstructionFactory();
    auto div = instFactory->create(4, &pc, &accumulator, memory);
    ASSERT_NE(nullptr, div);
}

TEST(BaseInstructionFactory_jmp, may_get_jmp_instruction){
    uint16_t pc=0;
    int16_t accumulator=0;
    auto memory = new Memory();
    auto instFactory = getBaseInstructionFactory();
    auto jmp = instFactory->create(5, &pc, &accumulator, memory);
    ASSERT_NE(nullptr, jmp);
}

TEST(BaseInstructionFactory_jmpn, may_get_jmpn_instruction){
    uint16_t pc=0;
    int16_t accumulator=0;
    auto memory = new Memory();
    auto instFactory = getBaseInstructionFactory();
    auto jmpn = instFactory->create(6, &pc, &accumulator, memory);
    ASSERT_NE(nullptr, jmpn);
}

TEST(BaseInstructionFactory_jmpp, may_get_jmpp_instruction){
    uint16_t pc=0;
    int16_t accumulator=0;
    auto memory = new Memory();
    auto instFactory = getBaseInstructionFactory();
    auto jmpp = instFactory->create(7, &pc, &accumulator, memory);
    ASSERT_NE(nullptr, jmpp);
}

TEST(BaseInstructionFactory_jmpz, may_get_jmpz_instruction){
    uint16_t pc=0;
    int16_t accumulator=0;
    auto memory = new Memory();
    auto instFactory = getBaseInstructionFactory();
    auto jmpz = instFactory->create(8, &pc, &accumulator, memory);
    ASSERT_NE(nullptr, jmpz);
}

TEST(BaseInstructionFactory_copy, may_get_copy_instruction){
    uint16_t pc=0;
    int16_t accumulator=0;
    auto memory = new Memory();
    auto instFactory = getBaseInstructionFactory();
    auto copy = instFactory->create(9, &pc, &accumulator, memory);
    ASSERT_NE(nullptr, copy);
}

TEST(BaseInstructionFactory_load, may_get_load_instruction){
    uint16_t pc=0;
    int16_t accumulator=0;
    auto memory = new Memory();
    auto instFactory = getBaseInstructionFactory();
    auto load = instFactory->create(10, &pc, &accumulator, memory);
    ASSERT_NE(nullptr, load);
}

TEST(BaseInstructionFactory_store, may_get_store_instruction){
    uint16_t pc=0;
    int16_t accumulator=0;
    auto memory = new Memory();
    auto instFactory = getBaseInstructionFactory();
    auto store = instFactory->create(11, &pc, &accumulator, memory);
    ASSERT_NE(nullptr, store);
}

TEST(BaseInstructionFactory_stop, may_get_stop_instruction){
    uint16_t pc=0;
    int16_t accumulator=0;
    auto memory = new Memory();
    auto instFactory = getBaseInstructionFactory();
    auto stop = instFactory->create(14, &pc, &accumulator, memory);
    ASSERT_NE(nullptr, stop);
}