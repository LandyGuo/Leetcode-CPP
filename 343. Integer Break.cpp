/*
343. Integer Break  
Difficulty: Medium
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: you may assume that n is not less than 2.

Hint:

There is a simple O(n) solution to this problem.
You may check the breaking results of n ranging from 7 to 10 to discover the regularities.
*/
/*
思路：
1)不需要任何数学知识，直接动规：
class Solution {
public:
    int integerBreak(int n) {
        vector<int>opt(n+1,INT_MIN);
        opt[1] = 1;
        opt[2] = 1;
        opt[3] = 2;
        opt[4] = 4;
        for(int i=5;i<=n;i++)
            for(int j=1;j<=i/2;j++)
            opt[i] = max(opt[i],max(j,opt[j])*max(opt[i-j],i-j));//j是不拆分，opt[j]是拆分j的最大乘积;实际上如果j>=5，opt[j]>j,因此一定要拆分。这一步的意思是：把i拆分成两部分，考虑这两部分拆分，不拆分能得到的最大乘积
        return opt[n];
    }
2)如果具备以下数学知识：
1. 2^3<3^2,   和为6
    4^3 < 3^4  和为 12
    5^3 < 3^5
    6^3 < 3^6
    因此，应该尽可能拆分成更多的3，乘积才能最大
    breaking it into 3s turns out to be the most efficient
2.
3*（n-3）>=n
n>=4.5,因此只要n>=5,都应该拆分成3，但是n<=4时，拆分不一定能保证最大
可以将动态规划中
            for(int j=1;j<=i/2;j++)
            opt[i] = max(opt[i],max(j,opt[j])*max(opt[i-j],i-j));
简化为:
    opt[i] = 3*max(opt[i-3],i-3);//相当于直接选择3进行拆分
*/

class Solution {
public:
    int integerBreak(int n) {
        vector<int>opt(n+1,INT_MIN);
        opt[1] = 0;
        opt[2] = 1;
        opt[3] = 2;
        opt[4] = 4;
        for(int i=5;i<=n;i++)
            opt[i] = 3*max(opt[i-3],i-3);
        return opt[n];
    }
};
