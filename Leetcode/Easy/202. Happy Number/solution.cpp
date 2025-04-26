class Solution 
{
public:
    bool isHappy(int n) 
    {
        int result = 0;
        while (true)
        {
            while (n > 0)
            {
                result += (n % 10) * (n % 10);
                n /= 10;
            }
            if (result == 1)
            {
                return true;
            }
            if (result < 5)
            {
                break;
            }
            n = result;
            result = 0;
        }
        return false;
    }
};