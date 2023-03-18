#ifndef STACK_HPP
#define STACK_HPP

#include <stack>
#include <cstdint>
#include <string>
#include "abstract_exception.hpp"

namespace stackMachine {

class Stack {
public:
    Stack() : m_stack() {}
    Stack(Stack const& a_other) = default;
    Stack& operator=(Stack const& a_other) = default;
    ~Stack() = default;

    size_t Size() const;
    void Push(const int64_t& a_data);
    int64_t Pop();

private:
    std::stack<int64_t> m_stack;
};


class StackExceptions: public VMExceptions {
public:
    StackExceptions(const char* a_str) : m_str(a_str) {}
    StackExceptions(const StackExceptions& a_other) = default;
    StackExceptions& operator=(const StackExceptions& a_other) = default;
    ~StackExceptions() = default;

    const char* what() throw() override;

private:
    std::string m_str;
};


} //stackMachine

#include "inl/stack_inl.hxx"

#endif