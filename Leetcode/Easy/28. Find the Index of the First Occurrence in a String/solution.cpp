class Solution 
{
public:
    int strStr(string haystack, string needle)
    {
        if (haystack == needle)
        {
            return 0;
        }
        if (haystack == "" || needle == "")
        {
            return -1;
        }
        int loopCount = needle.size();

        std::string compareStr = "";
        int index;
        for (int k = 0; k < haystack.size(); ++k)
        {
            if (compareStr == needle)
            {
                return index;
            }
            else if ((haystack[k] == needle[0]) && (k + loopCount <= haystack.size()))
            {
                index = k;
                compareStr += haystack[k];
                for (int i = 1; i < loopCount; ++i)
                {
                    while (haystack[k + i] == needle[i] && (i < loopCount))
                    {
                        compareStr += haystack[k + i];

                        ++i;

                        if (compareStr == needle)
                        {
                            return index;
                        }
                    }
                    if (compareStr != needle)
                    {
                        compareStr = "";
                    }
                }
            }

        }
        if (compareStr == needle)
        {
            return index;
        }

        return -1;
    }
};