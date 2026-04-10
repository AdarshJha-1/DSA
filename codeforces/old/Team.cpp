#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    while (n--)
    {
        int agree = 0;
        int p;
        cin >> p;
        agree = (agree * 10) + p;
        int v;
        cin >> v;
        agree = (agree * 10) + v;
        int t;
        cin >> t;
        agree = (agree * 10) + t;

        if (
            agree != 100 &&
            agree != 10 &&
            agree != 1 &&
            agree != 0)
        {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}