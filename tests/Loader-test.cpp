//
// Created by mateusberardo on 13/03/2021.
//
#include <memory.h>
#include <loader.h>
#include "gtest/gtest.h"

TEST(Loader, may_instantiate_loader){
    auto loader = new Loader("01 02 1");
    ASSERT_NE(nullptr, loader);
}

TEST(Loader, should_load_in_memory){
    auto mem = new Memory();
    auto loader = new Loader("01 02 1");
    loader->load(mem);
    ASSERT_EQ(1, (*mem)[0]);
    ASSERT_EQ(2, (*mem)[1]);
    ASSERT_EQ(1, (*mem)[2]);
}