#include <iostream>
#include "include/util.hpp"
#include "include/symbol.hpp"
#include "include/translate.hpp"
#include <cstring>

int main(int argc, char** argv)
{
    symbol_table symbols;
    std::string input_filename="", output_filename="";
    
    for (int i=0; i < argc; i++)
    {
        if (std::string(argv[i]) == "-i" and std::string(argv[i+1]) !=  "-o" and i+1 < argc)
        {
            input_filename = argv[i+1];
        }
        else if (std::string(argv[i]) == "-o" and std::string(argv[i+1]) != "-i" and i+1 < argc)
        {
            output_filename = argv[i+1];
        }
    }
    
    if (input_filename == "")
    {
        std::cout << "fatal error: no input files\n"
                  << "Usage: assembler -i [input filename] -o [output filename]\n";
    }
    else
    {
        std::vector<std::string> commands = load_file(input_filename);
        auto translated = translate(handle_symbols(remove_whitespace(remove_comments(commands)), symbols));

        if (output_filename != "")
        {
            if (!create_binary(translated, output_filename+".hack"))
            {
                std::cout << "fatal error: couldnot create file\n";
            }
        }
        else
        {
            if (!create_binary(translated, "a.hack"))
            {
                std::cout << "fatal error: couldnot create file\n";
            }
        }
        
        
    }
    
    return 0;
}
