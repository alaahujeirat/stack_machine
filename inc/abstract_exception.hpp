#ifndef ABSTRACT_EXCEPTION_HPP
#define ABSTRACT_EXCEPTION_HPP


namespace stackMachine {

class VMExceptions {
public:
    virtual ~VMExceptions() = default;
    virtual const char* what() throw() = 0;

protected:
    VMExceptions() = default;
    VMExceptions(const VMExceptions& a_other) = default;
    VMExceptions& operator=(const VMExceptions& a_other) = default;
};


} //stackMachine

#endif