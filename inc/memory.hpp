#ifndef MEMORY_HPP
#define MEMORY_HPP

#include <array>
#include <cstdint>
#include <stdexcept>
#include "abstract_exception.hpp"

namespace stackMachine {

//could be written as template: template<size_t N, typename T = int64_t>
class Memory {
public:
    explicit Memory() = default;
    Memory(Memory const& a_other) = default;
    Memory& operator=(Memory const& a_other) = default;
    ~Memory() = default;

    int64_t Read(size_t a_idx);
    void Write(size_t a_idx, int64_t a_data);

private:
    std::array<int64_t, 1024> m_memory;
};


class MemoryExceptions: public VMExceptions {
public:
    MemoryExceptions(const char* a_str) : m_str(a_str) {}
    MemoryExceptions(const MemoryExceptions& a_other) = default;
    MemoryExceptions& operator=(const MemoryExceptions& a_other) = default;
    ~MemoryExceptions() = default;

    const char* what() throw() override;

private:
    std::string m_str;
};


} //stackMachine


#include "inl/memory_inl.hxx"

#endif