#include <iostream>
#include <string>
#include <vector>

std::vector<int> LPS(std::string &str)
{
    int n = str.size();
    std::vector<int> lps(n, 0);
    int p = 0;
    int s = 1;
    while (s < n)
    {
        if (str[p] == str[s])
        {
            lps[s] = p + 1;
            s++;
            p++;
        }
        else
        {
            if (p == 0)
            {
                lps[s] = 0;
                s++;
            }
            else
            {
                p = lps[p - 1];
            }
        }
    }
    return lps;
}

std::vector<int> LPSv1(std::string &str)
{
    int n = str.size();
    std::vector<int> lps(n, 0);

    int pre = 0;
    int suf = 1;
    while (suf < n)
    {
        if (str[pre] == str[suf])
        {
            lps[suf] = pre + 1;
            suf++;
            pre++;
        }
        else
        {
            if (pre == 0)
            {
                lps[suf] = 0;
                suf++;
            }
            else
            {
                pre = lps[pre - 1];
            }
        }
    }
    return lps;
}
int main()
{
    std::string str = "ABCABDABCABDABDAB";
    std::vector<int> lps = LPSv1(str);

    for (const auto &val : lps)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}