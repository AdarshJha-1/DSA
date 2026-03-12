class Solution 
{
public:
    string removeOuterParentheses(string s) 
    {
        int openC = 1;
        int closeC = 0;

        string ans = "";

        string temp = "";
        for(int i = 1; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                temp += '(';
                openC++;
            }
            else
            {
                if(closeC + 1 == openC)
                {
                    ans += temp;
                    temp = "";
                    openC = 1;
                    closeC = 0;
                    i++;
                }
                else
                {
                    temp += ')';
                    closeC++;
                }
            }
        } 
        return ans;
    }
};