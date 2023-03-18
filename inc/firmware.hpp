#ifndef FIRMWARE_HPP
#define FIRMWARE_HPP

#include <map>
#include "abstract_operation.hpp"
#include "stack.hpp"
#include "memory.hpp"
#include "code_segment.hpp"

namespace stackMachine {

typedef std::map<int64_t, AbstractOperation*> Operations;

class Firmware {
public:
    Firmware(Stack& a_stack, Stack& a_stackIP, Memory& a_memory, CodeSegment& a_code);
    Firmware(Firmware const& a_other) = default;
    Firmware& operator=(Firmware const& a_other) = default;
    ~Firmware();

    AbstractOperation* operator[](int64_t a_key) const;

private:
    Operations CreateFirmware();

private:
    Stack& m_stack;
    Stack& m_stackIP;
    Memory& m_memory;
    CodeSegment& m_code;
    Operations m_firmware;
};


class FirmwareExceptions: public VMExceptions {
public:
    FirmwareExceptions(const char* a_str);
    FirmwareExceptions(const FirmwareExceptions& a_other) = default;
    FirmwareExceptions& operator=(const FirmwareExceptions& a_other) = default;
    ~FirmwareExceptions() = default;

    const char* what() throw() override;

private:
    std::string m_str;
};


} //stackMachine

#endif
