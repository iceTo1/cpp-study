class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int size = prices.size();
        int buy = prices[0], sell = 0;

        for (int i = 1; i < size; ++i)
        {
            if (buy > prices[i])
                buy = prices[i];
            
            int profit = prices[i] - buy;
            if (profit > sell)
            {
                sell = prices[i] - buy;
            }
        }

        return sell;
    }
};