#ifndef OPERATIONS_HPP
#define OPERATIONS_HPP

#include <cstddef>
#include "intermediate_op_classes.hpp"

namespace stackMachine {


class NOP : public AbstractOperation {
public:
    NOP(CodeSegment& a_code);
    NOP(NOP const& a_other) = default;
    NOP& operator=(NOP const& a_other) = default;
    ~NOP() = default;

    void Operate() override;

private:
    CodeSegment& m_code;
};


class Add : public BinaryOps {
public:
    Add(Stack& a_stack, CodeSegment& a_code);
    Add(Add const& a_other) = default;
    Add& operator=(Add const& a_other) = default;
    ~Add() = default;

private:
    int64_t Act(int64_t a_first, int64_t a_second) override;
};


class Sub : public BinaryOps {
public:
    Sub(Stack& a_stack, CodeSegment& a_code);
    Sub(Sub const& a_other) = default;
    Sub& operator=(Sub const& a_other) = default;
    ~Sub() = default;

private:
    int64_t Act(int64_t a_first, int64_t a_second) override;
};


class And : public BinaryOps {
public:
    And(Stack& a_stack, CodeSegment& a_code);
    And(And const& a_other) = default;
    And& operator=(And const& a_other) = default;
    ~And() = default;

private:
    int64_t Act(int64_t a_first, int64_t a_second) override;
};


class Or : public BinaryOps {
public:
    Or(Stack& a_stack, CodeSegment& a_code);
    Or(Or const& a_other) = default;
    Or& operator=(Or const& a_other) = default;
    ~Or() = default;

private:
    int64_t Act(int64_t a_first, int64_t a_second) override;
};


class Xor : public BinaryOps {
public:
    Xor(Stack& a_stack, CodeSegment& a_code);
    Xor(Xor const& a_other) = default;
    Xor& operator=(Xor const& a_other) = default;
    ~Xor() = default;

private:
    int64_t Act(int64_t a_first, int64_t a_second) override;
};


class Not : public UnaryOps {
public:
    Not(Stack& a_stack, CodeSegment& a_code);
    Not(Not const& a_other) = default;
    Not& operator=(Not const& a_other) = default;
    ~Not() = default;

private:
    int64_t Act(int64_t a_num) override;
};


class Compl: public UnaryOps {
public:
    Compl(Stack& a_stack, CodeSegment& a_code);
    Compl(Compl const& a_other) = default;
    Compl& operator=(Compl const& a_other) = default;
    ~Compl() = default;

private:
    int64_t Act(int64_t a_num) override;
};



class In : public AbstractOperation {
public:
    In(Stack& a_stack, CodeSegment& a_code);
    In(In const& a_other) = default;
    In& operator=(In const& a_other) = default;
    ~In() = default;

    void Operate() override;

private:
    Stack& m_stack;
    CodeSegment& m_code;
};


class Innum: public AbstractOperation {
public:
    Innum(Stack& a_stack, CodeSegment& a_code);
    Innum(Innum const& a_other) = default;
    Innum& operator=(Innum const& a_other) = default;
    ~Innum() = default;

    void Operate();

private:
    Stack& m_stack;
    CodeSegment& m_code;
};


class Out : public OutputOps {
public:
    Out(Stack& a_stack, CodeSegment& a_code);
    Out(Out const& a_other) = default;
    Out& operator=(Out const& a_other) = default;
    ~Out() = default;

private:
    void Act(int64_t a_num) override;
};


class Outnum: public OutputOps {
public:
    Outnum(Stack& a_stack, CodeSegment& a_code);
    Outnum(Outnum const& a_other) = default;
    Outnum& operator=(Outnum const& a_other) = default;
    ~Outnum() = default;

private:
    void Act(int64_t a_num) override;
};


class Load : public AbstractOperation {
public:
    Load(Stack& a_stack, Memory& a_memory, CodeSegment& a_code);
    Load(Load const& a_other) = default;
    Load& operator=(Load const& a_other) = default;
    ~Load() = default;

    void Operate() override;

private:
    Stack& m_stack;
    Memory& m_memory;
    CodeSegment& m_code;
};


class Store : public AbstractOperation {
public:
    Store(Stack& a_stack, Memory& a_memory, CodeSegment& a_code);
    Store(Store const& a_other) = default;
    Store& operator=(Store const& a_other) = default;
    ~Store() = default;

    void Operate() override;

private:
    Stack& m_stack;
    Memory& m_memory;
    CodeSegment& m_code;
};


class Jump : public AbstractOperation {
public:
    Jump(Stack& a_stack, CodeSegment& a_code);
    Jump(Jump const& a_other) = default;
    Jump& operator=(Jump const& a_other) = default;
    ~Jump() = default;

    void Operate() override;

private:
    Stack& m_stack;
    CodeSegment& m_code;
};


class JZ : public JumpOps {
public:
    JZ(Stack& a_stack, CodeSegment& a_code);
    JZ(JZ const& a_other) = default;
    JZ& operator=(JZ const& a_other) = default;
    ~JZ() = default;

private:
    void Act(int64_t a_first, int64_t a_second) override;

private:
    CodeSegment& m_code;
};


class JNZ: public JumpOps {
public:
    JNZ(Stack& a_stack, CodeSegment& a_code);
    JNZ(JNZ const& a_other) = default;
    JNZ& operator=(JNZ const& a_other) = default;
    ~JNZ() = default;

private:
    void Act(int64_t a_first, int64_t a_second) override;

private:
    CodeSegment& m_code;
};


class Push : public AbstractOperation {
public:
    Push(Stack& a_stack, CodeSegment& a_code);
    Push(Push const& a_other) = default;
    Push& operator=(Push const& a_other) = default;
    ~Push() = default;

    void Operate();

private:
    Stack& m_stack;
    CodeSegment& m_code;
};


class Dup: public AbstractOperation {
public:
    Dup(Stack& a_stack, CodeSegment& a_code);
    Dup(Dup const& a_other) = default;
    Dup& operator=(Dup const& a_other) = default;
    ~Dup() = default;

    void Operate();

private:
    Stack& m_stack;
    CodeSegment& m_code;
};


class Swap: public AbstractOperation {
public:
    Swap(Stack& a_stack, CodeSegment& a_code);
    Swap(Swap const& a_other) = default;
    Swap& operator=(Swap const& a_other) = default;
    ~Swap() = default;

    void Operate();

private:
    Stack& m_stack;
    CodeSegment& m_code;
};


class Rol3: public AbstractOperation {
public:
    Rol3(Stack& a_stack, CodeSegment& a_code);
    Rol3(Rol3 const& a_other) = default;
    Rol3& operator=(Rol3 const& a_other) = default;
    ~Rol3() = default;

    void Operate();

private:
    Stack& m_stack;
    CodeSegment& m_code;
};


class Drop: public AbstractOperation {
public:
    Drop(Stack& a_stack, CodeSegment& a_code);
    Drop(Drop const& a_other) = default;
    Drop& operator=(Drop const& a_other) = default;
    ~Drop() = default;

    void Operate();

private:
    Stack& m_stack;
    CodeSegment& m_code;
};



class PushIP: public AbstractOperation {
public:
    PushIP(Stack& a_stackIP, CodeSegment& a_code);
    PushIP(PushIP const& a_other) = default;
    PushIP& operator=(PushIP const& a_other) = default;
    ~PushIP() = default;

    void Operate();

private:
    Stack& m_stackIP;
    CodeSegment& m_code;
};


class PopIP: public StackIP {
public:
    PopIP(Stack& a_stackIP, CodeSegment& a_code);
    PopIP(PopIP const& a_other) = default;
    PopIP& operator=(PopIP const& a_other) = default;
    ~PopIP() = default;

private:
    void Act(int64_t a_num) override;

private:
    CodeSegment& m_code;
};


class DropIP: public StackIP {
public:
    DropIP(Stack& a_stackIP, CodeSegment& a_code);
    DropIP(DropIP const& a_other) = default;
    DropIP& operator=(DropIP const& a_other) = default;
    ~DropIP() = default;

private:
    void Act(int64_t a_num) override;

private:
    CodeSegment& m_code;
};


// Exceptions
class OperationsExceptions: public VMExceptions {
public:
    OperationsExceptions(const char* a_str);
    OperationsExceptions(const OperationsExceptions& a_other) = default;
    OperationsExceptions& operator=(const OperationsExceptions& a_other) = default;
    ~OperationsExceptions() = default;

    const char* what() throw() override;

private:
    std::string m_str;
};


} //stackMachine

#endif