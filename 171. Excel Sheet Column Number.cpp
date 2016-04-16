/*
171. Excel Sheet Column Number    
Difficulty: Easy
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/
/*思路：将26进制转换为10进制*/
class Solution {
public:
    int titleToNumber(string s) {
        int res=0;
        for(auto p =s.begin();p!=s.end();p++)
        {
            res*=26;//每位之间26进一位
            res+=(*p-'A'+1);
        }
        return res;
    }
};
