#ifndef INTERMEDIATE_OPS
#define INTERMEDIATE_OPS

#include "abstract_operation.hpp"
#include "stack.hpp"
#include "memory.hpp"
#include "code_segment.hpp"

namespace stackMachine {

class StackBase: public AbstractOperation {
public:
    StackBase(Stack& a_stack);
    StackBase(StackBase const& a_other) = default;
    StackBase& operator=(StackBase const& a_other) = default;
    ~StackBase() = default;

protected:
    virtual size_t RequestedSize() = 0;
    virtual void Execute() = 0;
    void Operate() override;
    int64_t Pop();
    void Push(int64_t a_elem);

private:
    Stack& m_stack;
};


class BinaryOps: public StackBase {
public:
    BinaryOps(Stack& a_stack, CodeSegment& a_code);
    BinaryOps(BinaryOps const& a_other) = default;
    BinaryOps& operator=(BinaryOps const& a_other) = default;
    ~BinaryOps() = default;

private:
    size_t RequestedSize() override;
    void Execute() override;
    virtual int64_t Act(int64_t a_first, int64_t a_second) = 0;

private:
    CodeSegment& m_code;
};


class UnaryOps: public StackBase {
public:
    UnaryOps(Stack& a_stack, CodeSegment& a_code);
    UnaryOps(UnaryOps const& a_other) = default;
    UnaryOps& operator=(UnaryOps const& a_other) = default;
    ~UnaryOps() = default;

private:
    size_t RequestedSize() override;
    void Execute() override;
    virtual int64_t Act(int64_t a_num) = 0;

private:
    CodeSegment& m_code;
};


class OutputOps: public StackBase {
    public:
    OutputOps(Stack& a_stack, CodeSegment& a_code);
    OutputOps(OutputOps const& a_other) = default;
    OutputOps& operator=(OutputOps const& a_other) = default;
    ~OutputOps() = default;

private:
    size_t RequestedSize() override;
    void Execute() override;
    virtual void Act(int64_t a_num) = 0;

private:
    CodeSegment& m_code;
};


class JumpOps: public StackBase {
    public:
    JumpOps(Stack& a_stack);
    JumpOps(JumpOps const& a_other) = default;
    JumpOps& operator=(JumpOps const& a_other) = default;
    ~JumpOps() = default;

private:
    size_t RequestedSize() override;
    void Execute() override;
    virtual void Act(int64_t a_first, int64_t a_second) = 0;
};


class StackIP: public StackBase {
public:
    StackIP(Stack& a_stackIP);
    StackIP(StackIP const& a_other) = default;
    StackIP& operator=(StackIP const& a_other) = default;
    ~StackIP() = default;

private:
    size_t RequestedSize() override;
    void Execute() override;
    virtual void Act(int64_t a_num) = 0;
};



} //stackMachine

#endif