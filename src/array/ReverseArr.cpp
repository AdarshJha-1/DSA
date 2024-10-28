#include <iostream>

using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int i = 0, j = size - 1;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    while (i <= j)
    {
        // int temp = arr[i];
        // arr[i] = arr[j];
        // arr[j] = temp;
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}