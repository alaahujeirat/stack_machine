#ifndef ABSTRACT_OP_HPP
#define ABSTRACT_OP_HPP

#include "abstract_exception.hpp"

namespace stackMachine {

class AbstractOperation {
public:
    virtual ~AbstractOperation() = default;
    virtual void Operate() = 0;

protected:
    AbstractOperation() = default;
    AbstractOperation(AbstractOperation const& a_other) = default;
    AbstractOperation& operator=(AbstractOperation const& a_other) = default;
};

} //stackMachine

#endif