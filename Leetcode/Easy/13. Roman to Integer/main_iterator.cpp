class Solution 
{
public:
    int romanToInt(string s) 
    {
        int result = 0;
        int size = s.size();
        std::string::iterator iter = s.begin();
        while (iter != s.end())
        {
            if (*iter == 'I')
            {
                auto next = std::next(iter);
                if (next != s.end() && *next == 'V')
                {
                    result += 4;
                    ++iter;
                }
                else if (next != s.end() && *next == 'X')
                {
                    result += 9;
                    ++iter;
                }
                else
                {
                    result += 1;
                }
            }

            else if (*iter == 'X')
            {
                auto next = std::next(iter);
                if (next != s.end() && *next == 'L')
                {
                    result += 40;
                    ++iter;
                }
                else if (next != s.end() && *next == 'C')
                {
                    result += 90;
                    ++iter;
                }
                else
                {
                    result += 10;
                }
            }

            else if (*iter == 'C')
            {
                auto next = std::next(iter);
                if (next != s.end() && *next == 'D')
                {
                    result += 400;
                    ++iter;
                }
                else if (next != s.end() && *next == 'M')
                {
                    result += 900;
                    ++iter;
                }
                else
                {
                    result += 100;
                }
            }

            else if (*iter == 'V')
            {
                result += 5;
            }
            else if (*iter == 'L')
            {
                result += 50;
            }
            else if (*iter == 'D')
            {
                result += 500;
            }
            else if (*iter == 'M')
            {
                result += 1000;
            }
            ++iter;           
        }
        return result;
    }
};