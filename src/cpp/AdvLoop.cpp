#include <iostream>

using namespace std;

int main()
{
    // for(int i = 100; i <= 200; i++) {
    //     cout << i << endl;
    // }

    // for(char ch = 'a'; ch <= 'z'; ch++) {
    //     cout << ch << " ";
    // }

    // for(int i = 10; i > 0; i--) {
    //     cout << i << " ";
    // }

    // for(int i = 1; i <= 100; i += 3) {
    //     cout << i  << " ";
    // }

    int n;
    cout << "Enter n value: ";
    cin >> n;
    // for (int i = 1; i <= 10; i++)
    // {
    //     cout << n << " X " << i << " = " << n * i << endl;
    // }

    // for(int num = 6; num <= 60; num += 6) {
    //     cout << num << endl;
    // }

    // for(int i = n; i <= n * 10; i += n) {
    //     cout << i << endl;
    // }

    // int pow;
    // cout << "Enter pow value: ";
    // cin >> pow;
    // int ans = n;
    // for(int i = 0; i < pow - 1; i++) {
    //     ans *= n;
    // }
    // cout << "Ans: " << ans << endl;

    // int sum = 0;
    // for(int i = 1; i <= n; i++) {
    //     sum += i;
    // }

    // cout << "Sum of " << n << " natural number is: " << sum << endl;

    // int sumFormula =  n * (n + 1) / 2;
    // cout << "Sum of " << n << " natural number is: " << sumFormula << endl;

    // int fact = 1;
    // for (int i = 1; i <= n; i++)
    // {
    //     fact *= i;
    // }

    // cout << "Factorial of " << n << " is: " << fact << endl;

    int first = 0;
    int second = 1;
    int sum;
    for(int i = 3; i <= n; i++) {
        sum = first + second;
        first = second;
        second = sum;
    }

    cout << " Fibonacci of " << n << " is: " << second << endl;
    return 0;
}