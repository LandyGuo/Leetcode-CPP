/*
201. Bitwise AND of Numbers Range   
Difficulty: Medium
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.
*/
/*2nd pass
思路：
        101 - 5       5&6&7= 4 = 100    实际上就是找5和7都为1 的前缀，逐步去掉5和7后面的比特位，直到两个相等，这时然后再将去掉的比特位都补0
        110 - 6                          这时就是最终的结果
        111 - 7
*/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int cnt = 0;
        while(m!=n)
        {
            m>>=1;
            n>>=1;
            cnt+=1;
        }
        return m<<cnt;
    }
};
