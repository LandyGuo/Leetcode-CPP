/*
122. Best Time to Buy and Sell Stock II 
Difficulty: Medium
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
(ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/
//2nd pass
/*思路： 
1.因为不限制交易次数，所以要抓住尽可能多的赚钱机会，只要当天比前一天价钱高，就应该捕捉到这个增长边沿
2.把所有的增长边沿捕捉起来就是最大收益
注意：
连续多天的增长可以看成是每2天一点点的增长累积起来的
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_val = 0;
        for(int i=1;i<prices.size();i++)
            max_val += max(0,prices[i]-prices[i-1]);
        return max_val;
    }
};
