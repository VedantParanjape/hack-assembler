#include "include/translate.hpp"

std::map<std::string, std::string> comp_table{
    {"0", "0101010"},
    {"1", "0111111"},
    {"-1", "0111010"},
    {"D", "0001100"},
    {"A", "0110000"},
    {"!D", "0001101"},
    {"!A", "0110001"},
    {"-D", "0001111"},
    {"-A", "0110011"},
    {"D+1", "0011111"},
    {"A+1", "0110111"},
    {"D-1", "0001110"},
    {"A-1", "0110010"},
    {"D+A", "0000010"},
    {"D-A", "0010011"},
    {"A-D", "0000111"},
    {"D&A", "0000000"},
    {"D|A", "0010101"},
    {"M", "1110000"},
    {"!M", "1110001"},
    {"-M", "1110011"},
    {"M+1", "1110111"},
    {"M-1", "1110010"},
    {"D+M", "1000010"},
    {"D-M", "1010011"},
    {"M-D", "1000111"},
    {"D&M", "1000000"},
    {"D|M", "1010101"}
};

std::map<std::string, std::string> dest_table{
    {"null", "000"},
    {"M", "001"},
    {"D", "010"},
    {"MD", "011"},
    {"A", "100"},
    {"AM", "101"},
    {"AD", "110"},
    {"AMD", "111"}
};

std::map<std::string, std::string> jump_table{
    {"null", "000"},
    {"JGT", "001"},
    {"JEQ", "010"},
    {"JGE", "011"},
    {"JLT", "100"},
    {"JNE", "101"},
    {"JLE", "110"},
    {"JMP", "111"}
};

std::string translate_a_instructions(std::string instruction)
{
    int value = std::atoi(std::string(instruction.begin()+1, instruction.end()).c_str());

    return "0" + std::bitset<15>(value).to_string();
}

std::string translate_c_instructions(std::string instructions)
{
    std::string binary_command;
    parsed_instruction cmd = parse_instructions(instructions);

    binary_command = "111" + comp_table[cmd.comp] + dest_table[cmd.dest] + jump_table[cmd.jump];

    return binary_command;
}

std::vector<std::string> translate(std::vector<std::string> instructions)
{
    std::vector<std::string> translated;

    for (auto i : instructions)
    {
        if (i[0] == std::string("@")[0])
        {
            // std::cout << "a ins: " << i << "  :  " << translate_a_instructions(i) << "\n";
            translated.push_back(translate_a_instructions(i));
        }
        else
        {
            // std::cout << "c ins: " << i << "  :  " << translate_c_instructions(i) << "\n";
            translated.push_back(translate_c_instructions(i));
        }
    }

    return translated;
}

