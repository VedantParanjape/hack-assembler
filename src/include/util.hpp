#ifndef UTIL_HPP
#define UTIL_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>

typedef struct c_type_instructions
{
    std::string dest;
    std::string comp;
    std::string jump;
}parsed_instruction;

std::vector<std::string> load_file(std::string filename);
std::vector<std::string> remove_whitespace(std::vector<std::string> instructions);
std::vector<std::string> remove_comments(std::vector<std::string> instructions);
parsed_instruction parse_instructions(std::string);
bool create_binary(std::vector<std::string> binary_instructions, std::string filename);

#endif