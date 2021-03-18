//
// Created by mateusberardo on 13/03/2021.
//

#include <exceptions/memoryoutofrangeexception.h>
#include <memory.h>
#include "gtest/gtest.h"

TEST(Memory, may_instantiate_memory){
    auto mem = new Memory();
    ASSERT_NE(nullptr, mem);
}

TEST(Memory, should_be_able_to_get_value_from_addr){
    Memory mem = *(new Memory());
    for (int i; i<216; i++)
        ASSERT_EQ(0, mem[i]);
}

TEST(Memory, get_address_out_of_range_should_throw_exception){
    Memory mem = *(new Memory());
    ASSERT_THROW(mem[216], MemoryOutOfRangeException);
}

TEST(Memory, should_be_able_to_set_capacity){
    Memory mem = *(new Memory(532));
    ASSERT_EQ(0, mem[531]);
}

TEST(Memory, should_be_able_to_set_addr){
    Memory mem = *(new Memory());
    mem[100] = 3;
    ASSERT_EQ(3, mem[100]);
}
