#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "aaacaaaa";
    int n = str.size();

    vector<int> LPS(n, 0);

    int len = 0;
    for (int i = 1; i < n;)
    {
        if (str[i] == str[len])
        {
            len++;
            LPS[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = LPS[len - 1];
            }
            else
            {
                LPS[i] = 0;
                i++;
            }
        }
    }

    for (const auto &v : LPS)
    {
        cout << v << " ";
    }

    return 0;
}