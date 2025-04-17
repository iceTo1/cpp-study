class Solution 
{
public:
    bool isPalindrome(string s) 
    {
        std::string::iterator iterFront = s.begin();
        std::string::iterator iterBack = s.end() - 1;
        while (iterFront < iterBack)
        {
            if (!isalpha(*iterFront) && !isdigit(*iterFront))
            {
                ++iterFront;
                continue;
            }
            if (!isalpha(*iterBack) && !isdigit(*iterBack))
            {
                --iterBack;
                continue;
            }
            if (tolower(*iterFront) != tolower(*iterBack))
            {
                return false;
            }
            ++iterFront;
            --iterBack;
        }
        return true;    
    }
};