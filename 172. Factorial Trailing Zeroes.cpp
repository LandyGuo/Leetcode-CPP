/*
172. Factorial Trailing Zeroes  
Difficulty: Easy
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/

/*2nd pass:
思路：对于阶乘的结果后面0的个数取决于因子中5的个数
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int sum=0;
        while(n)
        {
            sum+=n/5;
            n/=5;
        }
        return sum;
    }
};
