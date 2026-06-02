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

int query(int rl, int rr, int i, int l, int r)
{
    if (r < rl || l > rr)
    {
        return 0;
    }
    if (l >= rl && r <= rr)
    {
        return segT[i];
    }
    int m = l + (r - l) / 2;
    int sum = 0;
    sum += query(rl, rr, 2 * i + 1, l, m);
    sum += query(rl, rr, 2 * i + 2, m + 1, r);

    return sum;
}

// Lazy Propagation
void updateLazy()

    int main()
{
    vector<int> nums = {3, 1, 2, 7, 2, 1, 2, 3};
    int n = nums.size();
    // segT.resize(2 * n, 0);
    segT.resize(4 * n, 0); // more safer

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

    int rangeSum = query(2, 6, 0, 0, n - 1);
    cout << rangeSum << "\n";

    return 0;
}