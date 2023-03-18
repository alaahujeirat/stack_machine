#include <cstdint> //int64_t
#include <cstdio>
#include <iostream> //std::cin
#include "operations.hpp"



namespace stackMachine {

// NOP
NOP::NOP(CodeSegment& a_code)
: m_code(a_code)
{}

void NOP::Operate()
{
    m_code.SetIndex(m_code.GetIndex() + 1);
}


// Add
Add::Add(Stack& a_stack, CodeSegment& a_code)
: BinaryOps(a_stack, a_code)
{}

int64_t Add::Act(int64_t a_first, int64_t a_second)
{
    return a_first + a_second;
}


// Sub
Sub::Sub(Stack& a_stack, CodeSegment& a_code)
: BinaryOps(a_stack, a_code)
{}

int64_t Sub::Act(int64_t a_first, int64_t a_second)
{
    return a_first - a_second;
}


// And
And::And(Stack& a_stack, CodeSegment& a_code)
: BinaryOps(a_stack, a_code)
{}

int64_t And::Act(int64_t a_first, int64_t a_second)
{
    return a_first & a_second;
}


// Or
Or::Or(Stack& a_stack, CodeSegment& a_code)
: BinaryOps(a_stack, a_code)
{}

int64_t Or::Act(int64_t a_first, int64_t a_second)
{
    return a_first | a_second;
}


// Xor
Xor::Xor(Stack& a_stack, CodeSegment& a_code)
: BinaryOps(a_stack, a_code)
{}

int64_t Xor::Act(int64_t a_first, int64_t a_second)
{
    return a_first ^ a_second;
}


// Not
Not::Not(Stack& a_stack, CodeSegment& a_code)
: UnaryOps(a_stack, a_code)
{}

int64_t Not::Act(int64_t a_num)
{
    return !a_num;
}


// Compl
Compl::Compl(Stack& a_stack, CodeSegment& a_code)
: UnaryOps(a_stack, a_code)
{}

int64_t Compl::Act(int64_t a_num)
{
    return ~a_num;
}


// In
In::In(Stack& a_stack, CodeSegment& a_code)
: m_stack(a_stack)
, m_code(a_code)
{}


void In::Operate()
{
    int64_t a;
    std::cin >> a;
    char ch = (char)a;
    m_stack.Push(ch);
    m_code.SetIndex(m_code.GetIndex() + 1);
}


// Innum
Innum::Innum(Stack& a_stack, CodeSegment& a_code)
: m_stack(a_stack)
, m_code(a_code)
{}


void Innum::Operate()
{
    int64_t a;
    std::cin >> a;
    m_stack.Push(a);
    m_code.SetIndex(m_code.GetIndex() + 1);
}


// Out
Out::Out(Stack& a_stack, CodeSegment& a_code)
: OutputOps(a_stack, a_code)
{}

void Out::Act(int64_t a_num)
{
    char ch = (char)a_num;
    std::cout << ch;
}


// Outnum
Outnum::Outnum(Stack& a_stack, CodeSegment& a_code)
: OutputOps(a_stack, a_code)
{}

void Outnum::Act(int64_t a_num)
{
    std::cout << a_num;
}


// Load
Load::Load(Stack& a_stack, Memory& a_memory, CodeSegment& a_code)
: m_stack(a_stack)
, m_memory(a_memory)
, m_code(a_code)
{}


void Load::Operate()
{
    if (m_stack.Size() > 0) {
        int64_t a = m_stack.Pop();
        int64_t b = m_memory.Read(a);
        m_stack.Push(b);
        m_code.SetIndex(m_code.GetIndex() + 1);
    }
    else {
        throw StackExceptions("Underflow error\n");
    }
}


// Store
Store::Store(Stack& a_stack, Memory& a_memory, CodeSegment& a_code)
: m_stack(a_stack)
, m_memory(a_memory)
, m_code(a_code)
{}


void Store::Operate()
{
    if (m_stack.Size() > 1) {
        int64_t a = m_stack.Pop();
        int64_t b = m_stack.Pop();
        m_memory.Write(a, b);
        m_code.SetIndex(m_code.GetIndex() + 1);
    }
    else {
        throw StackExceptions("Underflow error\n");
    }
}

// Jump
Jump::Jump(Stack& a_stack, CodeSegment& a_code)
: m_stack(a_stack)
, m_code(a_code)
{}


void Jump::Operate()
{
    if (m_stack.Size() > 0) {
        int64_t a = m_stack.Pop();
        m_code.SetIndex(a);
    }
    else {
        throw StackExceptions("Underflow error\n");
    }
}


// JZ
JZ::JZ(Stack& a_stack, CodeSegment& a_code)
: JumpOps(a_stack)
, m_code(a_code)
{}

void JZ::Act(int64_t a_first, int64_t a_second)
{
    if (a_first == 0) {
        m_code.SetIndex(a_second);
    }
    m_code.SetIndex(m_code.GetIndex() + 1);
}


// JNZ
JNZ::JNZ(Stack& a_stack, CodeSegment& a_code)
: JumpOps(a_stack)
, m_code(a_code)
{}

void JNZ::Act(int64_t a_first, int64_t a_second)
{
    if (a_first != 0) {
        m_code.SetIndex(a_second);
    }
    m_code.SetIndex(m_code.GetIndex() + 1);
}


// Push
Push::Push(Stack& a_stack, CodeSegment& a_code)
: m_stack(a_stack)
, m_code(a_code)
{}


void Push::Operate()
{
    m_code.SetIndex(m_code.GetIndex() + 1);
    m_stack.Push(m_code.GetInstruction(m_code.GetIndex()));
    m_code.SetIndex(m_code.GetIndex() + 1);
}


// Dup
Dup::Dup(Stack& a_stack, CodeSegment& a_code)
: m_stack(a_stack)
, m_code(a_code)
{}


void Dup::Operate()
{
    int64_t a = m_stack.Pop();
    m_stack.Push(a);
    m_stack.Push(a);
    m_code.SetIndex(m_code.GetIndex() + 1);
}


// Swap
Swap::Swap(Stack& a_stack, CodeSegment& a_code)
: m_stack(a_stack)
, m_code(a_code)
{}


void Swap::Operate()
{
    int64_t a = m_stack.Pop();
    int64_t b = m_stack.Pop();
    m_stack.Push(a);
    m_stack.Push(b);
    m_code.SetIndex(m_code.GetIndex() + 1);
}


// Rol3
Rol3::Rol3(Stack& a_stack, CodeSegment& a_code)
: m_stack(a_stack)
, m_code(a_code)
{}


void Rol3::Operate()
{
    int64_t a = m_stack.Pop();
    int64_t b = m_stack.Pop();
    int64_t c = m_stack.Pop();
    m_stack.Push(a);
    m_stack.Push(c);
    m_stack.Push(b);
    m_code.SetIndex(m_code.GetIndex() + 1);
}


// Drop
Drop::Drop(Stack& a_stack, CodeSegment& a_code)
: m_stack(a_stack)
, m_code(a_code)
{}


void Drop::Operate()
{
    if (m_stack.Size() > 0) {
        m_stack.Pop();
        m_code.SetIndex(m_code.GetIndex() + 1);
    }
    else {
        throw StackExceptions("Underflow error\n");
    }
}



// PushIP
PushIP::PushIP(Stack& a_stackIP, CodeSegment& a_code)
: m_stackIP(a_stackIP)
, m_code(a_code)
{}


void PushIP::Operate()
{
    m_code.SetIndex(m_code.GetIndex() + 1);
    m_stackIP.Push(m_code.GetInstruction(m_code.GetIndex()));
    m_code.SetIndex(m_code.GetIndex() + 1);
}


// PopIP
PopIP::PopIP(Stack& a_stackIP, CodeSegment& a_code)
: StackIP(a_stackIP)
, m_code(a_code)
{}


void PopIP::Act(int64_t a_num)
{
    m_code.SetIndex(a_num);
}


// DropIP
DropIP::DropIP(Stack& a_stackIP, CodeSegment& a_code)
: StackIP(a_stackIP)
, m_code(a_code)
{}


void DropIP::Act(int64_t a_num)
{
    m_code.SetIndex(m_code.GetIndex() + 1);
}


// Exceptions
OperationsExceptions::OperationsExceptions(const char* a_str) 
: m_str(a_str) 
{}

const char* OperationsExceptions::what() throw() 
{
    return m_str.c_str();
}


} // stackMachine