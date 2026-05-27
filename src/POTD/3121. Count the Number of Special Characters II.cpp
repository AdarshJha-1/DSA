// 1st try not working wrong idea
class Solution 
{
public:
    int numberOfSpecialChars(string word) 
    {
        unordered_map<char, int> m;
        int counter = 0;

        for(const auto& c : word)
        {
            if(c >= 'A' && c <= 'Z' && m.count(c + 32) != 0)
            {
                counter++;
            }
            else
            {
                m[c]++;
            }
        }

        return counter;
    }
};

class Solution 
{
public:
    int numberOfSpecialChars(string word) 
    {
        int n = word.size();
        vector<bool> seen(26, false);
        vector<int> smallCharLastOccIdx(26, INT_MAX);
        for(int i = 0; i < n; i++)
        {
            if(word[i] >= 'a' && word[i] <= 'z')
            {
                smallCharLastOccIdx[word[i] - 'a'] = i;
            }
        }

        int counter = 0;
        for(int i = 0; i < n; i++)
        {
            if(word[i] >= 'A' && word[i] <= 'Z' && !seen[word[i] - 'A'])
            {  
                seen[word[i] - 'A'] = true;
                if(smallCharLastOccIdx[(word[i] + 32) - 'a'] < i)
                {
                    counter++;
                }
            }
        }
        return counter;
    }
};
