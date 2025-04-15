class Solution
{
public:
    int lengthOfLastWord(string s) 
    {
        std::string::reverse_iterator riter = s.rbegin();
        int count = 0;
        if (*riter == ' ')
        {
            while ((riter != s.rend()) && (*riter == ' '))
            {
                ++riter;
            }
            while ((riter != s.rend()) && (*riter != ' '))
            {
                ++count;
                ++riter;
            }
        }
        else
        {
            while ((riter != s.rend()) && (*riter != ' '))
            {
                ++count;
                ++riter;
            }
        }
        
        return count;        
    }
};