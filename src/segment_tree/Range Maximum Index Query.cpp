#include <bits/stdc++.h>

using namespace std;

vector<int> segTIdx;

void build(int i, int l, int r, vector<int> &nums)
{
    if (l == r)
    {
        segTIdx[i] = l;
        return;
    }

    int m = l + (r - l) / 2;
    build(2 * i + 1, l, m, nums);
    build(2 * i + 2, m + 1, r, nums);
    segTIdx[i] = nums[segTIdx[2 * i + 1]] > nums[segTIdx[2 * i + 2]] ? segTIdx[2 * i + 1] : segTIdx[2 * i + 2];
}

int query(int i, int l, int r, int start, int end, vector<int> &nums)
{
    if (r < start || end < l)
    {
        return -1;
    }

    if (l >= start && r <= end)
    {
        return segTIdx[i];
    }
    int m = l + (r - l) / 2;
    int left = query(2 * i + 1, l, m, start, end, nums);
    int right = query(2 * i + 2, m + 1, r, start, end, nums);
    if (left == -1)
    {
        return right;
    }
    if (right == -1)
    {
        return left;
    }
    return nums[left] > nums[right] ? left : right;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    int n = nums.size();
    segTIdx.resize(4 * n, 0);
    build(0, 0, n - 1, nums);
    cout << query(0, 0, n - 1, 2, 3, nums) << endl;
    return 0;
}