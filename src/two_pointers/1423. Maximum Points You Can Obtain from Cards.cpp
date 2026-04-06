class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {

        int firstKSum = 0;
        int lastKSum = 0;
        for (int i = 0; i < k; i++)
        {
            firstKSum += cardPoints[i];
        }
        int ans = firstKSum;

        int i = k - 1;
        int j = cardPoints.size() - 1;
        while (i >= 0)
        {
            lastKSum += cardPoints[j--];
            firstKSum -= cardPoints[i--];
            int currSum = firstKSum + lastKSum;
            ans = max(ans, currSum);
        }

        return ans;
    }
};