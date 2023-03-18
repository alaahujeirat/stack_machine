#include <stdexcept>
#include "code_segment.hpp"


namespace stackMachine {

CodeSegment::CodeSegment(const Code& a_code)
: m_code(a_code)
, m_ip(0)
{}


size_t CodeSegment::Size() const
{
    return m_code.size();
}


int64_t CodeSegment::GetInstruction(size_t a_idx) const
{
    if (a_idx >= m_code.size()) {
        throw std::invalid_argument("Index is out of range\n");
    }
    int64_t opcode = m_code[a_idx];
    return opcode;
}


size_t CodeSegment::GetIndex() const
{
    return m_ip;
}


void CodeSegment::SetIndex(size_t a_value)
{
    m_ip = a_value;
}


CodeSegmentExceptions::CodeSegmentExceptions(const char* a_str)
: m_str(a_str)
{}


const char* CodeSegmentExceptions::what() throw()
{
    return m_str.c_str();
}


} //stackMachine