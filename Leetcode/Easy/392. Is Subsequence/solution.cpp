class Solution 
{
public:
    bool isSubsequence(string s, string t) 
    {
        if ("" == s)
        {
            return true;
        }
        std::string container;
        int j = 0, idx = -1;
        for (int i = 0; i < s.size(); ++i)
        {
            j = idx + 1;
            while (j < t.size())
            {
                if (t[j] == s[i])
                {
                    container += t[j];
                    idx = j;
                    break;
                }
                else
                {
                    ++j;
                }

            }
        }

        if (container == s)
        {
            return true;
        }

        return false;
    }
};