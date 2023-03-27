#include <fstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <regex>

int main()
{
    const std::string text = "standard.output(\"1\");standard.output(\"2\");";
    const std::regex ws_re("\\s*;\\s*"); // whitespace

    const std::regex a = std::regex("standard\\.output\\(\"([^\"]+)\"\\)");
    
    auto b = std::sregex_token_iterator(text.begin(), text.end(), ws_re, -1);
    const std::sregex_token_iterator end;
    std::smatch base_match;

    while (b != end)
    {
        const std::string statement = *b++;
        std::regex_match(statement, base_match, a);
        std::cout << statement;

        if (base_match.size() == 2)
        {
            std::ssub_match base_sub_match = base_match[1];
            std::string base = base_sub_match.str();
            std::cout << " has a base of " << base;
        }
        std::cout << std::endl;
    }


    std::cin.get();
    return 0;
}