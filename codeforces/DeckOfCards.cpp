#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string str;
        cin >> str;

        if (n == 1 && k != 0)
        {
            cout << '-' << endl;
            continue;
        }
        vector<char> arr(n, '+');

        int n0 = 0, n1 = 0, n2 = 0;
        for (char c : str)
        {
            if (c == '0')
                n0++;
            else if (c == '1')
                n1++;
            else
                n2++;
        }

        int i = 0, j = n - 1;

        // Remove top n0 cards
        for (int x = 0; x < n0; x++)
            arr[i++] = '-';

        // Remove bottom n1 cards
        for (int x = 0; x < n1; x++)
            arr[j--] = '-';

        // Uncertain removals
        int top_uncertain = min(n2, j - i + 1); // how many from remaining top
        for (int x = 0; x < top_uncertain; x++)
            arr[i++] = '?';

        int bottom_uncertain = min(n2, j - i + 1); // remaining for bottom
        for (int x = 0; x < bottom_uncertain; x++)
            arr[j--] = '?';

        // Print result
        for (char c : arr)
            cout << c;
        cout << '\n';
    }
    return 0;
}