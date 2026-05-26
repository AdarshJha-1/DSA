class Solution 
{
public:
    int numberOfSpecialChars(string word) 
    {
        vector<int> atoz(26, 0), AtoZ(26, 0);

        for(const auto& c : word)
        {
            if(c >= 'a' && c <= 'z')
            {
                atoz[c - 'a']++;
            }
            if(c >= 'A' && c <= 'Z')
            {
                AtoZ[c - 'A']++;
            }
        }

        int count = 0;
        for(int i = 0; i < 26; i++)
        {
            if(atoz[i] != 0 && AtoZ[i] != 0)
            {
                count++;
            }
        }

        return count;
    }
};
