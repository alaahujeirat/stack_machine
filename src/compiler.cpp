#include <fstream>
#include <iostream>
#include "compiler.hpp"


namespace stackMachine {


Compiler::Compiler()
: m_dictionary(Build())
{}

void Display(std::vector<std::string>& a_vec)
{
    std::vector<std::string>::const_iterator it = a_vec.cbegin();
    std::vector<std::string>::const_iterator end = a_vec.cend();

    while (it != end) {
        std::cout << "Illegal command: " << *it << '\n';
        ++it;
    }
}


void IgnoreComments(std::fstream& a_stream, std::string& a_word)
{
    std::string buf;

    if (a_word[0] == '#') {
        std::getline(a_stream, a_word);
        a_stream >> a_word;
    }

    while (!a_stream.eof()) {
        if (a_stream.peek() == '#') {
            std::getline(a_stream, buf);
        }
        else {
            break;
        }
    }
}    


static void AddLabels(std::fstream& a_stream, std::map<std::string, int64_t>& a_table)
{
    std::string word;
    int64_t counter = 0;

    IgnoreComments(a_stream, word);

    while (a_stream >> word) {
        IgnoreComments(a_stream, word);

        if (word[0] == '$' && word.back() == ':') {
            word.pop_back();
            a_table.insert({word, counter});
        }
        else {
            ++counter;
        }
    }
}


Code Compiler::Compile(std::string a_filename)
{
    std::fstream f(a_filename);

    Code compiled_code;
    std::string command;
    std::vector<std::string> illegal_code;

    AddLabels(f, m_dictionary);

    f.clear();
    f.seekg(0);

    IgnoreComments(f, command);

    while (f >> command) {
        IgnoreComments(f, command);
        if (f.eof()) { break; }

        if (command.back() != ':') {
            Dictionary::iterator it = m_dictionary.find(command);
            if (it == m_dictionary.end()) {
                illegal_code.push_back(command);
            }
            else {
                compiled_code.push_back(it->second);
                if (command == "PUSH") {
                    try {
                        f >> command;
                        compiled_code.push_back(stol(command));
                    } catch (const std::invalid_argument& e) {
                        throw CompilerExceptions("Illegal PUSH argument\n");
                    }
                }
            }
        }
    }

    if (illegal_code.size()) {
        Display(illegal_code);
        throw CompilerExceptions("Illegal commands\n");
    }

    return compiled_code;
}


Dictionary Compiler::Build()
{
    Dictionary d;

    d.insert({"NOP", 0});
    d.insert({"ADD", 1});
    d.insert({"SUB", 2});
    d.insert({"AND", 3});
    d.insert({"OR", 4});
    d.insert({"XOR", 5});
    d.insert({"NOT", 6});
    d.insert({"IN", 7});
    d.insert({"OUT", 8});
    d.insert({"LOAD", 9});
    d.insert({"STOR", 10});
    d.insert({"JMP", 11});
    d.insert({"JZ", 12});
    d.insert({"PUSH", 13});
    d.insert({"DUP", 14});
    d.insert({"SWAP", 15});
    d.insert({"ROL3", 16});
    d.insert({"OUTNUM", 17});
    d.insert({"INNUM", 18});
    d.insert({"JNZ", 19});
    d.insert({"DROP", 20});
    d.insert({"COMPL", 21});
    d.insert({"PUSHIP", 22});
    d.insert({"POPIP", 23});
    d.insert({"DROPIP", 24});
    d.insert({"HLT", 999});

    return d;
}




const char* CompilerExceptions::what() throw() 
{
    return m_str.c_str();
}

} //stackMachine