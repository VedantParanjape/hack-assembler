#ifndef TRANSLATE_HPP
#define TRANSLATE_HPP

#include <vector>
#include <string>
#include <bitset>
#include <map>
#include "util.hpp"

std::string translate_a_instructions(std::string instruction);
std::string translate_c_instructions(std::string instruction);
std::vector<std::string> translate(std::vector<std::string> instructions);

#endif