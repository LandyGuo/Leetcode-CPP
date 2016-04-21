/*
231. Power of Two   My Submissions QuestionEditorial Solution
Total Accepted: 69171 Total Submissions: 190153 Difficulty: Easy
Given an integer, write a function to determine if it is a power of two.
*/

/*2nd pass
注意运算符的优先级:算术>移位>关系>逻辑
因此n&(n-1)==0 的运算顺序是先(n-1)==0,然后n&((n-1)==0),所以必须加括号:(n&(n-1))==0
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n>0)&&((n&(n-1))==0);
    }
};
