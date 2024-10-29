#include <iostream>

using namespace std;

void rotateArr(int arr[], int n)
{
    int temp = arr[n - 1];
    for (int i = n - 1; i >0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {2, 7, 4, 11, 5, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    rotateArr(arr, size);
    return 0;
}