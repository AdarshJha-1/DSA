/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution 
{
public:
    int findInMountainArray(int target, MountainArray &mountainArr) 
    {
        for(int i = 0; i < mountainArr.length(); i++)
        {
            int fromArr = mountainArr.get(i);
            if(fromArr == target)
            {
                return i;
            }
        }

        return -1;
    }
};


/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int mountainArrPeek(int target, MountainArray &mountainArr, int n) 
    {
        int s = 0;
        int e = n - 1;
        while(s < e)
        {
            int m = s + (e - s) / 2;
            if(mountainArr.get(m) < mountainArr.get(m + 1))
            {
                s = m + 1;
            }
            else
            {
                e = m;
            }
        }
        return e;
    }

    // assuming not consecutive idx values are same
    int BS(int target, MountainArray &mountainArr, int s, int e, bool asc)
    {
        while(s <= e)
        {
            int m = s + (e - s) / 2;
            int val = mountainArr.get(m);
            if (val == target)
            {
                return m;
            }

            if(asc)
            {
                if (val > target)
                {
                    e = m - 1;
                }
                else 
                {
                    s = m + 1;
                }
            }
            else 
            {
                if (val > target)
                {
                    s = m + 1;
                }
                else 
                {
                    e = m - 1;
                }
            }
            
        }
        return -1;
    } 

    int findInMountainArray(int target, MountainArray &mountainArr) 
    {
        int n = mountainArr.length();
        int peek = mountainArrPeek(target, mountainArr, n);
        int firstHalf = BS(target, mountainArr, 0, peek, true);
        int secondHalf = BS(target, mountainArr, peek + 1, n - 1, false);

        if(firstHalf != -1)
        {
            return firstHalf;
        }
        if(secondHalf != -1)
        {
            return secondHalf;
        }

        return -1;
    }
};
