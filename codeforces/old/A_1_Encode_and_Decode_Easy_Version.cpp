#include <iostream>
#include <vector>
using namespace std;

void runFirst()
{
    int n;
    cin >> n;
    string s = "";
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        s += 'a' + temp - 1;
    }
    cout << s << endl;
}

void runSecond()
{
    string str;
    cin >> str;
    cout << str.size() << endl;
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i] - 'a' + 1 << " ";
    }
    cout << endl;
}

int main()
{
    char ch[27];
    string str;
    cin >> str;
    if (str == "first")
    {
        runFirst();
    }
    else
    {
        runSecond();
    }
    return 0;
}