/*
13. Roman to Integer    
Difficulty: Easy
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/
/*2nd pass
思路：从低位到高位，记录当前的进制，如果出现比当前进制小的，就减去；出现比当前进制大的就加上。
I:1
V:5
X:10
L:50
C:100
D:500
M:1000
*/
class Solution {
public:
    int romanToInt(string s) {
        map<char,int> digits = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int sum=0;
        int cur = 0;
        for(auto p=s.rbegin();p!=s.rend();p++)
        {
            if(digits[*p]>=cur)
            {
                sum+=digits[*p];
                cur = digits[*p];
            }
            else
                sum-=digits[*p];
        }
        return sum;
    }
};
