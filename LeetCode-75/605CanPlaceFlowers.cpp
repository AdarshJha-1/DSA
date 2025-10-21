// Wrong
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        if (flowerbed.size() == 1)
        {
            if (n == 1 && flowerbed[0] == 0)
                return 1;
            if (n == 0 && flowerbed[0] == 1)
                return 1;
        }
        int N = flowerbed.size();
        int i = 0;
        while (n && i < N)
        {
            if (flowerbed[i] != 1)
            {
                if (i == 0 && flowerbed[i + 1] != 1)
                {
                    flowerbed[i] = 1;
                    n--;
                }
                else if (i == N - 1 && flowerbed[i - 1] != 1)
                {
                    flowerbed[i] = 1;
                    n--;
                }
                else if (flowerbed[i - 1] != 1 && flowerbed[i + 1] != 1)
                {
                    flowerbed[i] = 1;
                    n--;
                }
            }
            i++;
        }
        return n == 0;
    }
};

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        if (n == 0)
            return 1;
        int N = flowerbed.size();
        for (int i = 0; i < N && n > 0; i++)
        {
            if (flowerbed[i] != 1)
            {
                if ((i == 0 || flowerbed[i - 1] != 1) && (i == N - 1 || flowerbed[i + 1] != 1))
                {
                    n--;
                    flowerbed[i] = 1;
                }
            }
        }

        return n == 0;
    }
};