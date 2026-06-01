#include <bits/stdc++.h>
using namespace std;

vector<int> segT;

void buildTree(vector<int> &nums, int i, int l, int r)
{
    if (l == r)
    {
        segT[i] = nums[l];
        return;
    }
    int m = l + (r - l) / 2;
    buildTree(nums, 2 * i + 1, l, m);
    buildTree(nums, 2 * i + 2, m + 1, r);

    segT[i] = segT[2 * i + 1] + segT[2 * i + 2];
    return;
}

void update(int idx, int val, int i, int l, int r)
{
    if (l == r)
    {
        segT[i] = val;
        return;
    }
    int m = l + (r - l) / 2;
    if (idx <= m) // to go left -> 2i + 1
    {
        update(idx, val, 2 * i + 1, l, m);
    }
    else // to go right -> 2i + 2
    {
        update(idx, val, 2 * i + 2, m + 1, r);
    }
    segT[i] = segT[2 * i + 1] + segT[2 * i + 2];
}

int main()
{
    vector<int> nums = {3, 1, 2, 7};
    int n = nums.size();
    segT.resize(2 * n, 0);

    buildTree(nums, 0, 0, n - 1);
    for (const auto &v : segT)
    {
        cout << v << " ";
    }
    cout << "\n";

    update(1, 2, 0, 0, n - 1);

    for (const auto &v : segT)
    {
        cout << v << " ";
    }
    cout << "\n";

    return 0;
}