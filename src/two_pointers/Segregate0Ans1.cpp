#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<int> arr = {1, 0, 1, 0, 1, 0};
    int i = 0;
    int j = arr.size() - 1;
    while (i < j)
    {
        if (arr[i] == 0)
        {
            i++;
        }
        else if (arr[j] == 1)
        {
            j--;
        }
        else
        {
            // int temp = arr[i];
            // arr[i] = arr[j];
            // arr[j] = temp;
            // i++;
            // j--;
            arr[i] = 0;
            arr[j] = 1;
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    // cout << endl;
    // cout << "More Ways" << endl;
    // int count0 = 0;
    // int count1 = 0;

    // for (int i = 0; i < arr.size(); i++)
    // {
    //     if (arr[i] == 0)
    //     {
    //         count0++;
    //     }
    //     else
    //     {
    //         count1++;
    //     }
    // }

    // for(int i = 0; i < count0; i++) {
    //     arr[i] = 0;
    // }
    // for(int i = count0; i < arr.size(); i++) {
    //     arr[i] = 1;
    // }
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     cout << arr[i] << " ";
    // }

    return 0;
}