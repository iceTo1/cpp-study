class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) 
        {
            if (1 == strs.size())
            {
                return strs[0];
            }
    
            int minSize = 200; // initialize with the maximum length given.
            for (const std::string& str : strs)
            {
                if (str.size() < minSize)
                {
                    minSize = str.size();
                }
            }
    
            string prefix = "";
            char tempChar;
            for (int i = 0; i < minSize; ++i)
            {
                tempChar = strs[0][i];
                for (int j = 1; j < strs.size(); ++j)
                {
                    if (strs[j][i] != tempChar)
                    {
                        return prefix;
                    }
                }
                prefix += tempChar;
            }
    
            return prefix;
        }
    };