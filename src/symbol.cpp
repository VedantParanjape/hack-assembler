#include "include/symbol.hpp"

int symbol_table::lookup(std::string symbol)
{
    if (symbols.find(symbol) != symbols.end())
    {
        return symbols[symbol];
    }
    else
    {
        return -1;
    }
}

bool symbol_table::insert(std::string symbol, int location)
{
    if (symbols.find(symbol) == symbols.end())
    {
        const auto [it, success] = symbols.insert({symbol, location});
        return success;
    }
    else
    {
        return false;
    }
}

std::vector<std::string> handle_symbols(std::vector<std::string> instructions, symbol_table sym)
{
    int instruction_number = 0;
    int variable_count = 16;
    std::vector <std::string> processed;

    for (auto i : instructions)
    {
        if (i[0] == std::string("(")[0] and i[i.length()-1] == std::string(")")[0])
        {
            std::string label(i.begin()+1, i.end()-1);
            int loc = sym.lookup(label);

            if (loc < 0)
            {
                sym.insert(label, instruction_number);
            }
        }
        else
        {
            instruction_number++;
            processed.push_back(i);
        }
    }

    for (auto &i : processed)
    {
        if (i[0] == std::string("@")[0])
        {
            std::string label(i.begin()+1, i.end());
            int loc = sym.lookup(label);

            if (loc > 0 and std::find_if(label.begin(), label.end(), [](unsigned char c)->bool { return !isdigit(c); }) != label.end())
            {
                i = "@" + std::to_string(loc);
            }
            else if(std::find_if(label.begin(), label.end(), [](unsigned char c)->bool { return !isdigit(c); }) != label.end())
            {
                sym.insert(label, variable_count);
                i = "@" + std::to_string(variable_count);

                variable_count++;
            }
        }
    }

    return processed;
}

// int main()
// {
//     symbol_table st;
//     std::cout << st.insert("vedant", 100);
//     std::cout << st.lookup("vedant") << st.lookup("@30");
// }