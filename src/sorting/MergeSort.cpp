#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int l, int r, int m)
{
    vector<int> temp((r - l) + 1);
    int i = 0;
    int f = l, s = m + 1;
    while (f <= m && s <= r)
    {
        if (arr[s])
        {
            temp[i++] = arr[f++];
        }
        else
        {
            temp[i++] = arr[s++];
        }
    }

    while (f <= m)
    {
        temp[i++] = arr[f++];
    }
    while (s <= r)
    {
        temp[i++] = arr[s++];
    }

    for (int i = 0; i < temp.size(); i++)
    {
        arr[i + l] = temp[i];
    }
}

void mergeSort(vector<int> &arr, int l, int r)
{
    if (l >= r)
        return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, r, m);
}

int main()
{
    vector<int> arr = {70, 30, 50, 10};
    mergeSort(arr, 0, arr.size() - 1);
    for (auto &v : arr)
        cout << v << " ";
    return 0;
}
