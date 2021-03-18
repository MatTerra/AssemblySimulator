//
// Created by mateusberardo on 13/03/2021.
//

#include <processor.h>
#include <exceptions/invalidopcodeexception.h>
#include <exceptions/processorhaltedexception.h>
#include <exceptions/memoryoutofrangeexception.h>
#include "gtest/gtest.h"

TEST(Processor, may_instantiate_processor){
    auto mem = new Memory();
    auto processor = new Processor(mem);
    ASSERT_NE(nullptr, processor);
}

TEST(Processor, accumulator_should_start_on_zero){
    auto mem = new Memory();
    auto processor = new Processor(mem);
    ASSERT_EQ(0, processor->getAccumulator());
}

TEST(Processor, pc_should_start_on_zero){
    auto mem = new Memory();
    auto processor = new Processor(mem);
    ASSERT_EQ(0, processor->getProgramCounter());
}

TEST(Processor, should_have_memory_addr){
    auto mem = new Memory();
    auto processor = new Processor(mem);
    ASSERT_EQ(mem, processor->getMemory());
}

TEST(Processor, should_accept_starting_pc){
    auto mem = new Memory();
    auto processor = new Processor(mem, 3);
    ASSERT_EQ(3, processor->getProgramCounter());
}

TEST(Processor, cycle_should_update_pc){
    auto mem = new Memory();
    (*mem)[0]=1;
    (*mem)[1]=2;
    (*mem)[2]=1;
    auto processor = new Processor(mem, 0);
    processor->cycle();
    ASSERT_EQ(2, processor->getProgramCounter());
}

TEST(Processor, cycle_should_update_accumulator){
    auto mem = new Memory();
    (*mem)[0]=1;
    (*mem)[1]=2;
    (*mem)[2]=2;
    auto processor = new Processor(mem, 0);
    processor->cycle();
    ASSERT_EQ(2, processor->getAccumulator());
}

TEST(Processor, cycle_should_fail_if_opcode_unknown){
    auto mem = new Memory();
    (*mem)[0]=100;
    (*mem)[1]=2;
    (*mem)[2]=2;
    auto processor = new Processor(mem, 0);
    ASSERT_THROW(processor->cycle(), InvalidOpcodeException);
}

TEST(Processor, shouldnt_start_halted){
    auto mem = new Memory();
    (*mem)[0]=14;
    auto processor = new Processor(mem, 0);
    ASSERT_FALSE(processor->isHalted());
}

TEST(Processor, should_halt_after_stop){
    auto mem = new Memory();
    (*mem)[0]=14;
    auto processor = new Processor(mem, 0);
    processor->cycle();
    ASSERT_TRUE(processor->isHalted());
}

TEST(Processor, should_halt_after_exception){
    auto mem = new Memory();
    (*mem)[0]=100;
    auto processor = new Processor(mem, 0);
    try{
        processor->cycle();
    } catch (InvalidOpcodeException &e){
        // ignore
    }
    ASSERT_TRUE(processor->isHalted());
}

TEST(Processor, should_throw_halted_exception_if_halted_on_cycle){
    auto mem = new Memory();
    (*mem)[0]=100;
    auto processor = new Processor(mem, 0);
    try{
        processor->cycle();
    } catch (InvalidOpcodeException &e){
        // ignore
    }
    ASSERT_THROW(processor->cycle(), ProcessorHaltedException);
}

TEST(Processor, should_throw_memory_out_of_range_if_operand_out_of_range){
    auto mem = new Memory(2);
    (*mem)[0]=1;
    (*mem)[1]=5;
    auto processor = new Processor(mem, 0);
    ASSERT_THROW(processor->cycle(), MemoryOutOfRangeException);
}

TEST(Processor, should_halt_after_memory_out_of_range_exception){
    auto mem = new Memory(2);
    (*mem)[0]=1;
    (*mem)[1]=5;
    auto processor = new Processor(mem, 0);
    try{
        processor->cycle();
    } catch (MemoryOutOfRangeException &e){
        // ignore
    }
    ASSERT_TRUE(processor->isHalted());
}