/*
168. Excel Sheet Column Title  
Difficulty: Easy
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
*/
/*
注意从0开始计数，28(从1开始计数)->27(从0开始计数，0相当于1)
（28-1）%26 = 1  ---------->  B
 (28-1)/26 = 1(十进制意义上的1，相当于0) ----->1-1 =0 ----A
 AB

*/

class Solution {
public:
    string convertToTitle(int n) {
        if(n<1)
            return "";
        string res="";
        while(n)
        {
            int digit = (n-1)%26;    //从0开始计数，1当0
            n = (n-1)/26;
            res = char('A'+digit)+res;
        }   
        return res;
    }
};
