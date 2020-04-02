#ifndef SYMBOL_HPP
#define SYMBOL_HPP

#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

class symbol_table{
    private:
        std::map<std::string, int> symbols{
            {"R0", 0},
            {"R1", 1},
            {"R1", 2},
            {"R1", 3},
            {"R1", 4},
            {"R1", 5},
            {"R1", 6},
            {"R1", 7},
            {"R1", 8},
            {"R1", 9},
            {"R1", 10},
            {"R1", 11},
            {"R1", 12},
            {"R1", 13},
            {"R1", 14},
            {"R1", 15},
            {"SCREEN", 16384},
            {"KBD", 24576},
            {"SP", 0},
            {"LCL", 1},
            {"ARG", 2},
            {"THIS", 3},
            {"THAT", 4}
        };
    
    public:
        int lookup(std::string);
        bool insert(std::string, int location);
};

std::vector<std::string> handle_symbols(std::vector<std::string> instructions, symbol_table sym);

#endif