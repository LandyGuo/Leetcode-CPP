/*
309. Best Time to Buy and Sell Stock with Cooldown  
Difficulty: Medium
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]
*/
/*2nd pass
has_stock_profit[i] = max{has_stock_profit[i-1],no_stock_profit[i-2]-prices[i]}
no_stock_profit[i] = max{no_stock_profit[i-1],has_stock_profit[i-1]+prices[i]}
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)
            return 0;
        vector<int>has_stock_profit(prices.size()+1,0),no_stock_profit(prices.size()+1,0);
        //initialize
        has_stock_profit[0] = has_stock_profit[1] = -prices[0];
        no_stock_profit[0] = no_stock_profit[1] = 0;
        int length = prices.size()+1;
        for(int i = 2;i<length;i++)
        {
            has_stock_profit[i] = max(has_stock_profit[i-1],no_stock_profit[i-2]-prices[i-1]);
            no_stock_profit[i] = max(no_stock_profit[i-1],has_stock_profit[i-1]+prices[i-1]);//注意：对应的价格是prices[i-1]
        }
        return no_stock_profit[no_stock_profit.size()-1];
    }
};
