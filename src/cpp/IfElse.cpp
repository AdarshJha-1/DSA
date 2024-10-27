#include <iostream>

using namespace std;

int main()
{
    // int package;
    // cin >> package;
    // if(package > 10) {
    //         cout << "Accepted";
    // } else {
    //     cout << "Rejected";
    // }

    int marks;
    cout << "Enter your marks: ";
    cin >> marks;
    if (marks > 33)
    {
        cout << "Pass";
    }
    else
    {
        cout << "Fail";
    }
    return 0;
}