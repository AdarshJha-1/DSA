class NumArray
{
public:
    vector<int> nums;
    vector<int> segT;
    int n;

    void buildST(int i, int l, int r)
    {
        if (l == r)
        {
            segT[i] = nums[l];
            return;
        }
        int m = l + (r - l) / 2;
        buildST(2 * i + 1, l, m);
        buildST(2 * i + 2, m + 1, r);
        segT[i] = segT[2 * i + 1] + segT[2 * i + 2];
    }

    void updateST(int i, int l, int r, int idx, int val)
    {
        if (l == r && l == idx)
        {
            segT[i] = val;
            return;
        }
        int m = l + (r - l) / 2;
        if (idx <= m)
        {
            updateST(2 * i + 1, l, m, idx, val);
        }
        else
        {
            updateST(2 * i + 2, m + 1, r, idx, val);
        }
        segT[i] = segT[2 * i + 1] + segT[2 * i + 2];
    }

    int queryST(int i, int l, int r, int start, int end)
    {
        if (start > r || end < l)
        {
            return 0;
        }
        if (l >= start && r <= end)
        {
            return segT[i];
        }
        int m = l + (r - l) / 2;
        return queryST(2 * i + 1, l, m, start, end) + queryST(2 * i + 2, m + 1, r, start, end);
    }

    NumArray(vector<int> &nums)
    {
        this->nums = nums;
        this->n = nums.size();
        segT.resize(4 * n, 0);
        buildST(0, 0, n - 1);
    }

    void update(int index, int val)
    {
        updateST(0, 0, n - 1, index, val);
    }

    int sumRange(int left, int right)
    {
        return queryST(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */