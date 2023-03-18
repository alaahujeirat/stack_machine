#include <utility>
#include "firmware.hpp"
#include "operations.hpp"


namespace stackMachine {

Firmware::Firmware(Stack& a_stack, Stack& a_stackIP, Memory& a_memory, CodeSegment& a_code)
: m_stack(a_stack)
, m_stackIP(a_stackIP)
, m_memory(a_memory)
, m_code(a_code)
, m_firmware(CreateFirmware())
{}


Firmware::~Firmware()
{
    size_t size = m_firmware.size();
    for (size_t i=0; i < size; ++i) {
        delete m_firmware[i];
    }
}


AbstractOperation* Firmware::operator[](int64_t a_key) const
{
    try {
        return m_firmware.at(a_key);
    } catch (const std::out_of_range& e) {
        throw FirmwareExceptions("Illegal command\n");
    }
}


Operations Firmware::CreateFirmware()
{
    Operations operations;
    
    operations.insert({0, new NOP(m_code)});
    operations.insert({1, new Add(m_stack, m_code)});
    operations.insert({2, new Sub(m_stack, m_code)});
    operations.insert({3, new And(m_stack, m_code)});
    operations.insert({4, new Or(m_stack, m_code)});
    operations.insert({5, new Xor(m_stack, m_code)});
    operations.insert({6, new Not(m_stack, m_code)});
    operations.insert({7, new In(m_stack, m_code)});
    operations.insert({8, new Out(m_stack, m_code)});
    operations.insert({9, new Load(m_stack, m_memory, m_code)});
    operations.insert({10, new Store(m_stack, m_memory, m_code)});
    operations.insert({11, new Jump(m_stack, m_code)});
    operations.insert({12, new JZ(m_stack, m_code)});
    operations.insert({13, new Push(m_stack, m_code)});
    operations.insert({14, new Dup(m_stack, m_code)});
    operations.insert({15, new Swap(m_stack, m_code)});
    operations.insert({16, new Rol3(m_stack, m_code)});
    operations.insert({17, new Outnum(m_stack, m_code)});
    operations.insert({18, new Innum(m_stack, m_code)});
    operations.insert({19, new JNZ(m_stack, m_code)});
    operations.insert({20, new Drop(m_stack, m_code)});
    operations.insert({21, new Compl(m_stack, m_code)});
    operations.insert({22, new PushIP(m_stackIP, m_code)});
    operations.insert({23, new PopIP(m_stackIP, m_code)});
    operations.insert({24, new DropIP(m_stackIP, m_code)});
    
    return operations;
}


// Exceptions
FirmwareExceptions::FirmwareExceptions(const char* a_str) 
: m_str(a_str) 
{}


const char* FirmwareExceptions::what() throw()
{
    return m_str.c_str();
}

} //stackMachine