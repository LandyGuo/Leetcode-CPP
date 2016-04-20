/*
66. Plus One
Difficulty: Easy
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/
/*2nd pass
1）增加一个进位空间
2）add one
3)从低位到高位处理进位
4）去掉高位的0
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        //添加一位用来容纳高位可能的进位
        digits.insert(digits.begin(),0);
        //add one
        digits[digits.size()-1]+=1;
        //从低位到高位处理进位
        int carry_on=0;
        for(int p = digits.size()-1;p>=0;p--)
        {
            digits[p]+=carry_on;
            carry_on = digits[p]/10;
            digits[p]%=10;
        }
        //去掉高位的0
        int p =0;
        while(p<digits.size()&&digits[p]==0)p++;
        vector<int>res(digits.begin()+p,digits.end());
        return res;
            
        
    }
};
