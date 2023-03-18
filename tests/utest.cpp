#include "mu_test.h"
#include "machine_vm.hpp"
#include "stack.hpp"
#include "operations.hpp"
#include "firmware.hpp"
#include "compiler.hpp"

#include <iostream>

BEGIN_TEST(program_test)
    using stackMachine::VM;
    using stackMachine::Stack;
    using stackMachine::CodeSegment;
    using stackMachine::Memory;
    using stackMachine::Firmware;
    using stackMachine::Compiler;

    Compiler compiler;
    CodeSegment code(compiler.Compile("Program_code1.txt"));

    Stack stack;
    Stack stack_ip;
    Memory memory;
    Firmware firmware(stack, stack_ip, memory, code);
    VM vm(code, firmware);

    vm.Run();
    ASSERT_EQUAL(stack.Pop(), 15);
END_TEST


BEGIN_TEST(a_more_complex_program_test)
    using stackMachine::VM;
    using stackMachine::Stack;
    using stackMachine::CodeSegment;
    using stackMachine::Memory;
    using stackMachine::Firmware;
    using stackMachine::Compiler;

    Compiler compiler;
    CodeSegment code(compiler.Compile("Program_code2.txt"));

    Stack stack;
    Stack stack_ip;
    Memory memory;
    Firmware firmware(stack, stack_ip, memory, code);
    VM vm(code, firmware);

    vm.Run();
    ASSERT_EQUAL(stack.Pop(), 672);
END_TEST


BEGIN_TEST(another_complex_program_test)
    using stackMachine::VM;
    using stackMachine::Stack;
    using stackMachine::CodeSegment;
    using stackMachine::Memory;
    using stackMachine::Firmware;
    using stackMachine::Compiler;

    Compiler compiler;
    CodeSegment code(compiler.Compile("Program_code3.txt"));

    Stack stack;
    Stack stack_ip;
    Memory memory;
    Firmware firmware(stack, stack_ip, memory, code);
    VM vm(code, firmware);

    vm.Run();
    ASSERT_EQUAL(stack.Pop(), 1);
END_TEST


BEGIN_TEST(test_compiler_with_illegal_commands)
    using stackMachine::VM;
    using stackMachine::Stack;
    using stackMachine::CodeSegment;
    using stackMachine::Memory;
    using stackMachine::Firmware;
    using stackMachine::Compiler;
    using stackMachine::CompilerExceptions;

    Compiler compiler;
    try {
        CodeSegment code(compiler.Compile("Program_code4.txt"));
    } catch (CompilerExceptions &e) {
        ASSERT_PASS();
    }
END_TEST


BEGIN_SUITE(to push or to pop that is the stack)
    TEST(program_test)
    TEST(a_more_complex_program_test)
    TEST(another_complex_program_test)
    TEST(test_compiler_with_illegal_commands)
END_SUITE