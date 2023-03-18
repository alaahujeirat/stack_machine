#ifndef COMPILER_HPP
#define COMPILER_HPP

#include <string>
#include <map>
#include "code_segment.hpp"
#include "abstract_exception.hpp"

namespace stackMachine {

typedef std::map<std::string, int64_t> Dictionary;

class Compiler {
public:
    Compiler();
    Compiler(const Compiler& a_other) = default;
    Compiler& operator=(const Compiler& a_other) = default;
    ~Compiler() = default;
    
    Code Compile(std::string a_filename);

private:
    Dictionary Build();

private:
    Dictionary m_dictionary;
};


class CompilerExceptions: public VMExceptions {
public:
    CompilerExceptions(const char* a_str) : m_str(a_str) {}
    CompilerExceptions(const CompilerExceptions& a_other) = default;
    CompilerExceptions& operator=(const CompilerExceptions& a_other) = default;
    ~CompilerExceptions() = default;

    const char* what() throw() override;

private:
    std::string m_str;
};


} //stackMachine

#endif