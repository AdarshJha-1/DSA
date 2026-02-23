class Solution
{
public:
    int towerOfHanoi(int n, int from, int to, int aux)
    {
        if (n == 0 || n == 1)
        {
            return n;
        }

        int count = 0;
        count += towerOfHanoi(n - 1, from, aux, to);
        // cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
        count += 1;
        count += towerOfHanoi(n - 1, aux, to, from);

        return count;
    }
};