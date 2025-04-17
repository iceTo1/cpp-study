class Solution 
{
public:
    bool isPalindrome(string s) 
    {
        std::string compare = "";
        std::string::iterator iter = s.begin();
        while (iter != s.end())
        {
            if (isalpha(*iter))
            {
                compare += tolower(*iter);
            }
            else if (isdigit(*iter))
            {
                compare += *iter;
            }
            ++iter;
        }


        std::string::iterator iterFront = compare.begin();
        std::string::iterator iterBack = compare.end() - 1;
        while (iterFront < iterBack)
        {
            if (*iterFront != *iterBack)
            {
                return false;
            }
            ++iterFront;
            --iterBack;
        }

        return true;    
    }
};