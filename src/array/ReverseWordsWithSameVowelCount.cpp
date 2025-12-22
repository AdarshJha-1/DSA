#include <iostream>
#include <string>
#include <algorithm>

std::string getWordFromString(const std::string &str, int &sIdx)
{
    std::string word = "";
    while (str[sIdx] == ' ')
        sIdx++;
    for (; sIdx < str.size(); sIdx++)
    {
        if (str[sIdx] != ' ')
        {
            word += str[sIdx];
        }
        else
        {
            break;
        }
    }
    return word;
}

int main()
{

    std::string str = "Hello World";
    std::cout << str << std::endl;
    int idx = 0;
    std::string word = getWordFromString(str, idx);
    std::cout << word << std::endl;
    word = getWordFromString(str, idx);

    str = "Hello my World";
    std::cout << str << std::endl;
    std::reverse(str.begin() + 6, str.begin() + 8);
    std::cout << str << std::endl;
    return 0;
}