#include "machine_vm.hpp"
#include "code_segment.hpp"
#include <iostream>


namespace stackMachine {


VM::VM(const CodeSegment& a_code_segment, const Firmware& a_firmware)
: m_firmware(a_firmware)
, m_code(a_code_segment)
{
}

void VM::Run()
{
    size_t idx = m_code.GetIndex();
    size_t size = m_code.Size();
    while (idx < size) {
        int64_t opcode = m_code.GetInstruction(idx);
        if (opcode == 999) {
            break;
        }

        try {
            m_firmware[opcode]->Operate();
        } catch(const FirmwareExceptions& e){
            std::cout << "Illegal command\n";
            break;
        } catch (...) {
            std::cout << "MACHINE DOWN!\n";
            break;
        }
        idx = m_code.GetIndex();
    }
}





} //stackMachine