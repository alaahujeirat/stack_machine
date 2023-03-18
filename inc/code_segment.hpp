#ifndef CODE_SEGMENT_HPP
#define CODE_SEGMENT_HPP
#include <cstdint>
#include <vector>
#include <string>
#include "abstract_exception.hpp"

namespace stackMachine {

typedef std::vector<int64_t> Code;

class CodeSegment {
public:
    CodeSegment(const Code& a_code);
    CodeSegment(CodeSegment const& a_other) = default;
    CodeSegment& operator=(CodeSegment const& a_other) = default;
    ~CodeSegment() = default;

    size_t Size() const;
    int64_t GetInstruction(size_t a_idx) const;

    size_t GetIndex() const;
    void SetIndex(size_t a_value);

private:
    const Code m_code;
    size_t m_ip;
};


class CodeSegmentExceptions: public VMExceptions {
public:
    CodeSegmentExceptions(const char* a_str);
    CodeSegmentExceptions(CodeSegmentExceptions const& a_other) = default;
    CodeSegmentExceptions& operator=(CodeSegmentExceptions const& a_other) = default;
    ~CodeSegmentExceptions() = default;

    const char* what() throw() override;

private:
    std::string m_str;
};

} //stackMachine

#endif