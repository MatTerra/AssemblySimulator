//
// Created by mateusberardo on 13/03/2021.
//

#include <memory.h>
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
#include <instructions/stopinstruction.h>
#include <interruptions/haltprocessorinterrupt.h>
#include <instructions/inputinstruction.h>
#include <interruptions/iointerrupt.h>
#include "gtest/gtest.h"

TEST(AddInstruction, may_instantiate_add){
    uint16_t pc = 0;
    int16_t accumulator = 0;
    auto memory = new Memory();
    auto add = new AddInstruction(&pc, &accumulator, memory);
    ASSERT_NE(nullptr, add);
}

TEST(AddInstruction, add_should_sum_on_accumulator){
    int16_t accumulator = 0;
    uint16_t pc=0;
    auto memory = new Memory();
    (*memory)[0]=1;
    (*memory)[1]=2;
    (*memory)[2]=1;
    auto add = new AddInstruction(&pc, &accumulator, memory);
    add->process();
    ASSERT_EQ(1, accumulator);
}

TEST(AddInstruction, pc_should_move_two_units){
    int16_t accumulator = 0;
    uint16_t pc=0;
    auto memory = new Memory();
    (*memory)[0]=1;
    (*memory)[1]=2;
    (*memory)[2]=1;
    auto add = new AddInstruction(&pc, &accumulator, memory);
    add->process();
    ASSERT_EQ(2, pc);
}

TEST(SubInstruction, may_instantiate_sub){
    uint16_t pc = 0;
    int16_t accumulator = 0;
    auto memory = new Memory();
    auto sub = new SubInstruction(&pc, &accumulator, memory);
    ASSERT_NE(nullptr, sub);
}

TEST(SubInstruction, sub_should_subtract_on_accumulator){
    int16_t accumulator = 0;
    uint16_t pc=0;
    auto memory = new Memory();
    (*memory)[0]=2;
    (*memory)[1]=2;
    (*memory)[2]=1;
    auto sub = new SubInstruction(&pc, &accumulator, memory);
    sub->process();
    ASSERT_EQ(-1, accumulator);
}

TEST(SubInstruction, pc_should_move_two_units){
    int16_t accumulator = 0;
    uint16_t pc=0;
    auto memory = new Memory();
    (*memory)[0]=2;
    (*memory)[1]=2;
    (*memory)[2]=1;
    auto sub = new SubInstruction(&pc, &accumulator, memory);
    sub->process();
    ASSERT_EQ(2, pc);
}

TEST(MulInstruction, may_instantiate_mul){
    uint16_t pc = 0;
    int16_t accumulator = 0;
    auto memory = new Memory();
    auto mul = new MulInstruction(&pc, &accumulator, memory);
    ASSERT_NE(nullptr, mul);
}

TEST(MulInstruction, mul_should_multiply_on_accumulator){
    int16_t accumulator = 1;
    uint16_t pc=0;
    auto memory = new Memory();
    (*memory)[0]=3;
    (*memory)[1]=2;
    (*memory)[2]=4;
    auto mul = new MulInstruction(&pc, &accumulator, memory);
    mul->process();
    ASSERT_EQ(4, accumulator);
}

TEST(MulInstruction, pc_should_move_two_units){
    int16_t accumulator = 0;
    uint16_t pc=0;
    auto memory = new Memory();
    (*memory)[0]=3;
    (*memory)[1]=2;
    (*memory)[2]=1;
    auto mul = new MulInstruction(&pc, &accumulator, memory);
    mul->process();
    ASSERT_EQ(2, pc);
}

TEST(DivInstruction, may_instantiate_div){
    uint16_t pc = 0;
    int16_t accumulator = 0;
    auto memory = new Memory();
    auto div = new DivInstruction(&pc, &accumulator, memory);
    ASSERT_NE(nullptr, div);
}

TEST(DivInstruction, div_should_divide_on_accumulator){
    int16_t accumulator = 4;
    uint16_t pc=0;
    auto memory = new Memory();
    (*memory)[0]=4;
    (*memory)[1]=2;
    (*memory)[2]=2;
    auto div = new DivInstruction(&pc, &accumulator, memory);
    div->process();
    ASSERT_EQ(2, accumulator);
}

TEST(DivInstruction, pc_should_move_two_units){
    int16_t accumulator = 0;
    uint16_t pc=0;
    auto memory = new Memory();
    (*memory)[0]=4;
    (*memory)[1]=2;
    (*memory)[2]=1;
    auto div = new DivInstruction(&pc, &accumulator, memory);
    div->process();
    ASSERT_EQ(2, pc);
}

TEST(JmpInstruction, may_instantiate_jmp){
    uint16_t pc = 0;
    int16_t accumulator = 0;
    auto memory = new Memory();
    auto jmp = new JmpInstruction(&pc, &accumulator, memory);
    ASSERT_NE(nullptr, jmp);
}

TEST(JmpInstruction, shouldnt_change_accumulator){
    int16_t accumulator = 4;
    uint16_t pc=0;
    auto memory = new Memory();
    (*memory)[0]=5;
    (*memory)[1]=3;
    (*memory)[2]=14;
    (*memory)[3]=14;
    auto jmp = new JmpInstruction(&pc, &accumulator, memory);
    jmp->process();
    ASSERT_EQ(4, accumulator);
}

TEST(JmpInstruction, pc_should_move_to_operand){
    int16_t accumulator = 0;
    uint16_t pc=0;
    auto memory = new Memory();
    (*memory)[0]=5;
    (*memory)[1]=3;
    (*memory)[2]=14;
    (*memory)[3]=14;
    auto jmp = new JmpInstruction(&pc, &accumulator, memory);
    jmp->process();
    ASSERT_EQ(3, pc);
}

TEST(JmpnInstruction, may_instantiate_jmpn){
    uint16_t pc = 0;
    int16_t accumulator = 0;
    auto memory = new Memory();
    auto jmpn = new JmpnInstruction(&pc, &accumulator, memory);
    ASSERT_NE(nullptr, jmpn);
}

TEST(JmpnInstruction, shouldnt_change_accumulator){
    int16_t accumulator = 4;
    uint16_t pc=0;
    auto memory = new Memory();
    (*memory)[0]=6;
    (*memory)[1]=3;
    (*memory)[2]=14;
    (*memory)[3]=14;
    auto jmpn = new JmpnInstruction(&pc, &accumulator, memory);
    jmpn->process();
    ASSERT_EQ(4, accumulator);
}

TEST(JmpnInstruction, pc_should_move_to_operand_if_accumulator_negative){
    int16_t accumulator = -1;
    uint16_t pc=0;
    auto memory = new Memory();
    (*memory)[0]=6;
    (*memory)[1]=3;
    (*memory)[2]=14;
    (*memory)[3]=14;
    auto jmpn = new JmpnInstruction(&pc, &accumulator, memory);
    jmpn->process();
    ASSERT_EQ(3, pc);
}

TEST(JmpnInstruction, pc_should_move_2_if_accumulator_positive){
    int16_t accumulator = 1;
    uint16_t pc=0;
    auto memory = new Memory();
    (*memory)[0]=6;
    (*memory)[1]=3;
    (*memory)[2]=14;
    (*memory)[3]=14;
    auto jmpn = new JmpnInstruction(&pc, &accumulator, memory);
    jmpn->process();
    ASSERT_EQ(2, pc);
}

TEST(JmpnInstruction, pc_should_move_2_if_accumulator_zero){
    int16_t accumulator = 0;
    uint16_t pc=0;
    auto memory = new Memory();
    (*memory)[0]=6;
    (*memory)[1]=3;
    (*memory)[2]=14;
    (*memory)[3]=14;
    auto jmpn = new JmpnInstruction(&pc, &accumulator, memory);
    jmpn->process();
    ASSERT_EQ(2, pc);
}

TEST(JmppInstruction, may_instantiate_jmpp){
    uint16_t pc = 0;
    int16_t accumulator = 0;
    auto memory = new Memory();
    auto jmpp = new JmppInstruction(&pc, &accumulator, memory);
    ASSERT_NE(nullptr, jmpp);
}

TEST(JmppInstruction, shouldnt_change_accumulator){
    int16_t accumulator = 4;
    uint16_t pc=0;
    auto memory = new Memory();
    (*memory)[0]=7;
    (*memory)[1]=3;
    (*memory)[2]=14;
    (*memory)[3]=14;
    auto jmpp = new JmppInstruction(&pc, &accumulator, memory);
    jmpp->process();
    ASSERT_EQ(4, accumulator);
}

TEST(JmppInstruction, pc_should_move_2_if_accumulator_negative){
    int16_t accumulator = -1;
    uint16_t pc=0;
    auto memory = new Memory();
    (*memory)[0]=7;
    (*memory)[1]=3;
    (*memory)[2]=14;
    (*memory)[3]=14;
    auto jmpp = new JmppInstruction(&pc, &accumulator, memory);
    jmpp->process();
    ASSERT_EQ(2, pc);
}

TEST(JmppInstruction, pc_should_move_2_if_accumulator_zero){
    int16_t accumulator = 0;
    uint16_t pc=0;
    auto memory = new Memory();
    (*memory)[0]=7;
    (*memory)[1]=3;
    (*memory)[2]=14;
    (*memory)[3]=14;
    auto jmpp = new JmppInstruction(&pc, &accumulator, memory);
    jmpp->process();
    ASSERT_EQ(2, pc);
}

TEST(JmppInstruction, pc_should_move_to_operand_if_accumulator_positive){
    int16_t accumulator = 1;
    uint16_t pc=0;
    auto memory = new Memory();
    (*memory)[0]=7;
    (*memory)[1]=3;
    (*memory)[2]=14;
    (*memory)[3]=14;
    auto jmpp = new JmppInstruction(&pc, &accumulator, memory);
    jmpp->process();
    ASSERT_EQ(3, pc);
}

TEST(JmpzInstruction, may_instantiate_jmpz){
    uint16_t pc = 0;
    int16_t accumulator = 0;
    auto memory = new Memory();
    auto jmpz = new JmpzInstruction(&pc, &accumulator, memory);
    ASSERT_NE(nullptr, jmpz);
}

TEST(JmpzInstruction, shouldnt_change_accumulator){
    int16_t accumulator = 1;
    uint16_t pc=0;
    auto memory = new Memory();
    (*memory)[0]=8;
    (*memory)[1]=3;
    (*memory)[2]=14;
    (*memory)[3]=14;
    auto jmpz = new JmpzInstruction(&pc, &accumulator, memory);
    jmpz->process();
    ASSERT_EQ(1, accumulator);
}

TEST(JmpzInstruction, pc_should_move_2_if_accumulator_positive){
    int16_t accumulator = 1;
    uint16_t pc=0;
    auto memory = new Memory();
    (*memory)[0]=8;
    (*memory)[1]=3;
    (*memory)[2]=14;
    (*memory)[3]=14;
    auto jmpz = new JmpzInstruction(&pc, &accumulator, memory);
    jmpz->process();
    ASSERT_EQ(2, pc);
}

TEST(JmpzInstruction, pc_should_move_2_if_accumulator_negative){
    int16_t accumulator = -1;
    uint16_t pc=0;
    auto memory = new Memory();
    (*memory)[0]=8;
    (*memory)[1]=3;
    (*memory)[2]=14;
    (*memory)[3]=14;
    auto jmpz = new JmpzInstruction(&pc, &accumulator, memory);
    jmpz->process();
    ASSERT_EQ(2, pc);
}

TEST(JmpzInstruction, pc_should_move_to_operand_if_accumulator_zero){
    int16_t accumulator = 0;
    uint16_t pc=0;
    auto memory = new Memory();
    (*memory)[0]=8;
    (*memory)[1]=3;
    (*memory)[2]=14;
    (*memory)[3]=14;
    auto jmpz = new JmpzInstruction(&pc, &accumulator, memory);
    jmpz->process();
    ASSERT_EQ(3, pc);
}

TEST(CopyInstruction, may_instantiate_copy){
    int16_t accumulator = 0;
    uint16_t pc=0;
    auto memory = new Memory();
    auto copy = new CopyInstruction(&pc, &accumulator, memory);
    ASSERT_NE(nullptr, copy);
}

TEST(CopyInstruction, pc_should_move_3){
    uint16_t pc = 0;
    int16_t acc = 0;
    auto memory = new Memory();
    auto copy = new CopyInstruction(&pc, &acc, memory);
    copy->process();
    ASSERT_EQ(3, pc);
}

TEST(CopyInstruction, should_copy_from_op1_to_op2){
    uint16_t pc = 0;
    int16_t acc = 0;
    auto memory = new Memory();
    (*memory)[0]=9;
    (*memory)[1]=4;
    (*memory)[2]=5;
    (*memory)[3]=14;
    (*memory)[4]=0;
    (*memory)[5]=3;
    auto copy = new CopyInstruction(&pc, &acc, memory);
    copy->process();
    ASSERT_EQ(0, (*memory)[5]);
}

TEST(LoadInstruction, may_instantiate_load){
    int16_t accumulator = 0;
    uint16_t pc=0;
    auto memory = new Memory();
    auto load = new LoadInstruction(&pc, &accumulator, memory);
    ASSERT_NE(nullptr, load);
}

TEST(LoadInstruction, pc_should_move_2){
    uint16_t pc = 0;
    int16_t acc = 0;
    auto memory = new Memory();
    (*memory)[0]=10;
    (*memory)[1]=3;
    (*memory)[2]=14;
    (*memory)[3]=2;
    auto load = new LoadInstruction(&pc, &acc, memory);
    load->process();
    ASSERT_EQ(2, pc);
}

TEST(LoadInstruction, should_load_from_memory_into_acc){
    uint16_t pc = 0;
    int16_t acc = 0;
    auto memory = new Memory();
    (*memory)[0]=10;
    (*memory)[1]=3;
    (*memory)[2]=14;
    (*memory)[3]=2;
    auto load = new LoadInstruction(&pc, &acc, memory);
    load->process();
    ASSERT_EQ(2, acc);
}

TEST(StoreInstruction, may_instantiate_store){
    int16_t accumulator = 0;
    uint16_t pc=0;
    auto memory = new Memory();
    auto store = new StoreInstruction(&pc, &accumulator, memory);
    ASSERT_NE(nullptr, store);
}

TEST(StoreInstruction, pc_should_move_2){
    uint16_t pc = 0;
    int16_t acc = 0;
    auto memory = new Memory();
    (*memory)[0]=11;
    (*memory)[1]=3;
    (*memory)[2]=14;
    (*memory)[3]=2;
    auto store = new StoreInstruction(&pc, &acc, memory);
    store->process();
    ASSERT_EQ(2, pc);
}

TEST(StoreInstruction, should_store_from_acc_into_memory){
    uint16_t pc = 0;
    int16_t acc = 0;
    auto memory = new Memory();
    (*memory)[0]=11;
    (*memory)[1]=3;
    (*memory)[2]=14;
    (*memory)[3]=2;
    auto store = new StoreInstruction(&pc, &acc, memory);
    store->process();
    ASSERT_EQ(0, (*memory)[3]);
}

TEST(InputInstruction, may_instantiate_input){
    int16_t accumulator = 0;
    uint16_t pc=0;
    auto memory = new Memory();
    auto input = new InputInstruction(&pc, &accumulator, memory);
    ASSERT_NE(nullptr, input);
}

TEST(InputInstruction, pc_should_move_2){
    int16_t accumulator = 0;
    uint16_t pc=0;
    auto memory = new Memory();
    (*memory)[0] = 12;
    (*memory)[1] = 2;
    (*memory)[2] = 0;
    auto input = new InputInstruction(&pc, &accumulator, memory);
    try {
        input->process();
    } catch (IOInterrupt &interrupt) {

    }
    ASSERT_EQ(2, pc);
}

TEST(InputInstruction, should_throw_iointerrupt_with_command_i){
    int16_t accumulator = 0;
    uint16_t pc=0;
    auto memory = new Memory();
    (*memory)[0] = 12;
    (*memory)[1] = 2;
    (*memory)[2] = 0;
    auto input = new InputInstruction(&pc, &accumulator, memory);
    ASSERT_THROW(input->process(), IOInterrupt);
    try {
        input->process();
    } catch (IOInterrupt &interrupt) {
        ASSERT_EQ('i', interrupt.getCommand());
    }
}

TEST(InputInstruction, should_throw_iointerrupt_with_addr){
    int16_t accumulator = 0;
    uint16_t pc=0;
    auto memory = new Memory();
    (*memory)[0] = 12;
    (*memory)[1] = 2;
    (*memory)[2] = 0;
    auto input = new InputInstruction(&pc, &accumulator, memory);
    try {
        input->process();
    } catch (IOInterrupt &interrupt) {
        ASSERT_EQ(2, interrupt.getAddress());
    }
}

TEST(OutputInstruction, pc_should_move_2){
    int16_t accumulator = 0;
    uint16_t pc=0;
    auto memory = new Memory();
    (*memory)[0] = 13;
    (*memory)[1] = 2;
    (*memory)[2] = 5;
    auto output = new OutputInstruction(&pc, &accumulator, memory);
    try {
        output->process();
    } catch (IOInterrupt &interrupt) {

    }
    ASSERT_EQ(2, pc);
}
//
//TEST(InputInstruction, should_throw_iointerrupt_with_command_i){
//    int16_t accumulator = 0;
//    uint16_t pc=0;
//    auto memory = new Memory();
//    (*memory)[0] = 12;
//    (*memory)[1] = 2;
//    (*memory)[2] = 0;
//    auto input = new InputInstruction(&pc, &accumulator, memory);
//    ASSERT_THROW(input->process(), IOInterrupt);
//    try {
//        input->process();
//    } catch (IOInterrupt &interrupt) {
//        ASSERT_EQ('i', interrupt.getCommand());
//    }
//}
//
//TEST(InputInstruction, should_throw_iointerrupt_with_addr){
//    int16_t accumulator = 0;
//    uint16_t pc=0;
//    auto memory = new Memory();
//    (*memory)[0] = 12;
//    (*memory)[1] = 2;
//    (*memory)[2] = 0;
//    auto input = new InputInstruction(&pc, &accumulator, memory);
//    try {
//        input->process();
//    } catch (IOInterrupt &interrupt) {
//        ASSERT_EQ(2, interrupt.getAddress());
//    }
//}

TEST(StopInstruction, may_instantiate_stop){
    int16_t accumulator = 0;
    uint16_t pc=0;
    auto memory = new Memory();
    auto stop = new StopInstruction(&pc, &accumulator, memory);
    ASSERT_NE(nullptr, stop);
}

TEST(StopInstruction, pc_shouldnt_move){
    uint16_t pc = 0;
    int16_t acc = 0;
    auto memory = new Memory();
    (*memory)[0]=14;
    auto stop = new StopInstruction(&pc, &acc, memory);
    try {
        stop->process();
    } catch (HaltProcessorInterrupt &e) {
        //ignore
    }
    ASSERT_EQ(0, pc);
}

TEST(StopInstruction, should_thrown_halt_processor_exception){
    uint16_t pc = 0;
    int16_t acc = 0;
    auto memory = new Memory();
    (*memory)[0]=14;
    auto stop = new StopInstruction(&pc, &acc, memory);
    ASSERT_THROW(stop->process(), HaltProcessorInterrupt);
}