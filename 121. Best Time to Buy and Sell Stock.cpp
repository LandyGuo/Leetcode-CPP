/*
121. Best Time to Buy and Sell Stock 
Difficulty: Easy
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Subscribe to see which companies asked this question
*/
//2nd pass
/*
思路：
股票高买低卖，思路很直观：
在每个位置，找包含当前位置与之之前所有位置的最小值，然后求差最大即为最大收益
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int length = prices.size();
        int last = INT_MAX;
        int max_val = INT_MIN;
        for(int i=0;i<length;i++)
        {
            last = min(last,prices[i]);
            max_val = max(max_val,prices[i]-last);
        }
        return max_val;
    }
};
