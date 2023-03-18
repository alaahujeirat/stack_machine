#include "intermediate_op_classes.hpp"


namespace stackMachine {

StackBase::StackBase(Stack& a_stack)
: m_stack(a_stack)
{}

void StackBase::Operate()
{
    if (RequestedSize() > m_stack.Size()) {
        throw StackExceptions("Underflow error\n");
    }
    
    Execute();
}

int64_t StackBase::Pop()
{
    return m_stack.Pop();
}

void StackBase::Push(int64_t a_elem)
{
    m_stack.Push(a_elem);
}


BinaryOps::BinaryOps(Stack& a_stack, CodeSegment& a_code)
: StackBase(a_stack)
, m_code(a_code)
{}

size_t BinaryOps::RequestedSize()
{
    return 2;
}

void BinaryOps::Execute()
{
    int64_t a = Pop();
    int64_t b = Pop();
    Push(Act(a, b));
    m_code.SetIndex(m_code.GetIndex() + 1);
}


UnaryOps::UnaryOps(Stack& a_stack, CodeSegment& a_code)
: StackBase(a_stack)
, m_code(a_code)
{}

size_t UnaryOps::RequestedSize()
{
    return 1;
}

void UnaryOps::Execute()
{
    int64_t a = Pop();
    Push(Act(a));
    m_code.SetIndex(m_code.GetIndex() + 1);
}


OutputOps::OutputOps(Stack& a_stack, CodeSegment& a_code)
: StackBase(a_stack)
, m_code(a_code)
{}

size_t OutputOps::RequestedSize()
{
    return 1;
}

void OutputOps::Execute()
{
    int64_t a = Pop();
    Act(a);
    m_code.SetIndex(m_code.GetIndex() + 1);
}


JumpOps::JumpOps(Stack& a_stack)
: StackBase(a_stack)
{}

size_t JumpOps::RequestedSize()
{
    return 2;
}

void JumpOps::Execute()
{
    int64_t a = Pop();
    int64_t b = Pop();
    Act(a, b);
}


StackIP::StackIP(Stack& a_stackIP)
: StackBase(a_stackIP)
{}

size_t StackIP::RequestedSize()
{
    return 1;
}

void StackIP::Execute()
{
    int64_t a = Pop();
    Act(a);
}


} //stackMachine