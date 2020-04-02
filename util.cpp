#include "util.hpp"

std::vector<std::string> load_file(std::string filename)
{
    std::ifstream filehandle;
    std::vector<std::string> instruction_table;

    filehandle.open(filename);
    if (!filehandle.is_open())
    {
        std::cerr << "Failed to open" << filename << "\n";
    }
    else
    {
        for(std::string instruction; std::getline(filehandle, instruction); )
        {
            instruction_table.push_back(instruction);
        }
    }

    return instruction_table;
}

std::vector<std::string> remove_whitespace(std::vector<std::string> instructions)
{
    std::vector <std::string> processed;

    for(auto i : instructions)
    {
        i.erase(std::remove_if(i.begin(), i.end(), ::isspace), i.end());

        if (i.size() > 0)
        {
            processed.push_back(i);
        }
    }

    return processed;
}

std::vector<std::string> remove_comments(std::vector<std::string> instructions)
{
    std::vector <std::string> processed;

    for(auto i : instructions)
    {
        int index = i.find_first_of("/");
        if (i.at(index+1) == std::string("/")[0])
        {
            i.erase(i.begin() + index, i.end());
        }
        processed.push_back(i);
    }

    return processed;
}

parsed_instruction parse_instructions(std::string instructions)
{
    int index_eq = 0, index_sc = 0;
    parsed_instruction cmd;

    index_eq = instructions.find("=");
    index_sc = instructions.find(";");
    auto begin = instructions.begin();
    auto end = instructions.end();

    if (index_eq != std::string::npos and index_sc == std::string::npos)
    {
        // for inst of form D = D + M
        cmd.dest = std::string(begin, begin+index_eq);
        cmd.comp = std::string(begin+index_eq+1, end);
        cmd.jump = "null";
    }
    else if (index_eq == std::string::npos and index_sc != std::string::npos)
    {
        // for inst of form D;JMP
        cmd.dest = "null";
        cmd.comp = std::string(begin, begin+index_sc);
        cmd.jump = std::string(begin+index_sc+1, end);
    }
    else if (index_eq != std::string::npos and index_sc != std::string::npos)
    {
        // for inst of form D = D + M;JMP
        cmd.dest = std::string(begin, begin+index_eq);
        cmd.comp = std::string(begin+index_eq+1, begin+index_sc);
        cmd.jump = std::string(begin+index_sc+1, end);
    }

    return cmd;
}

bool create_binary(std::vector<std::string> binary_instructions, std::string filename)
{
    std::ofstream filehandle;

    filehandle.open(filename);
    if (!filehandle.is_open())
    {
        std::cout << "Couldnot write to " << filename << "\n";
        return false;
    }
    else
    {
        for (auto i : binary_instructions)
        {
            filehandle << i << "\n";
        }
    }

    filehandle.close();
    return true;

}
// int main()
// {
//     std::vector<std::string> commands = load_file("Fill.asm");
//     auto processed = remove_whitespace(remove_comments(commands));

//     std::cout << "starting program" << "\n";
//     for(auto i : processed)
//     {
//         std::cout << i << "\n";
//     }

//     return 0;
// }

// int main()
// {
//     std::string inst;

//     std::cin >> inst;

//     auto temp = parse_instructions(inst);
//     std::cout << temp.dest << " " << temp.comp << " " << temp.jump << "\n";
// }