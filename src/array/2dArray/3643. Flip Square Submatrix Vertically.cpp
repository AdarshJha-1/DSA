class Solution
{
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>> &grid, int x, int y, int k)
    {
        int aboveRow = x;
        int belowRow = x + k - 1;
        int limitCol = y + k - 1;

        while (aboveRow < belowRow)
        {

            cout << "HEREEE\n";
            int i = y;
            int j = y;
            while (i <= limitCol && j <= limitCol)
            {
                swap(grid[aboveRow][i++], grid[belowRow][j++]);
            }
            aboveRow++;
            belowRow--;
        }

        return grid;
    }
};