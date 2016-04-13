/*
279. Perfect Squares 
Difficulty: Medium
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
*/
/*2nd pass
思路：动态规划
opt[i] = min(opt[i],opt[i-k*k]+1)(1<=K<=sqrt(i)),踩在已经计算的结果上加1
注意：k从1开始，这就意味着每个数opt[i]都至少能在opt[i-1]的基础上得到一个值
*/
class Solution {
public:
    int numSquares(int n) {
        vector<int>opt(n+1,0);
        for(int i=1;i<=n;i++)
        {
            opt[i] = INT_MAX;
            int sqrt_i = int(sqrt(i));
            for(int k=1;k<=sqrt_i;k++)
                opt[i] = min(opt[i],opt[i-k*k]+1);
        }
        return opt[n];
    }
};
