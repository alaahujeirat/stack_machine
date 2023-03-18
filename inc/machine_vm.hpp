#ifndef VM_HPP
#define VM_HPP

#include <cstddef>
#include <map>

#include "abstract_operation.hpp"
#include "stack.hpp"
#include "memory.hpp"
#include "code_segment.hpp"
#include "firmware.hpp"


namespace stackMachine {

class VM {
public:
    VM(const CodeSegment& a_code_segment, const Firmware& a_firmware);
    VM(VM const& a_other) = default;
    VM& operator=(VM const& a_other) = default;
    ~VM() = default;

    void Run();

private:
    const Firmware& m_firmware;
    const CodeSegment& m_code;
};


} //stackMachine

#endif