/*
91. Decode Ways  
Difficulty: Medium
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

Subscribe to see which companies asked this question
*/
//2nd pass
/*
思路：动态规划：opt[i]表示以s[i]为结尾的字符串的编码方法数
opt[i] = opt[i-1](当前字符独立编码：s[i]>=1&&s[i]<=9)+opt[i-2](当前字符和前一个字符一起编码:pre[i]=1||pre[i]==2&&0<=cur[i]<=6)
注意：
1)本题只用考虑符合题意的情形（能单独编码，或者和前面一个一起编码），两种情况都不满足，直接返回invalid
2)初始化时，前面加1个为1的辅助单元opt[0]=1，并根据字符串第一个字符确定opt[1]的值,opt[s.length()]即为返回值
*/
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()) return 0;
        vector<int>opt(s.length()+1,0);
        opt[0] = 1;
        opt[1] = s[0]>='1'&&s[0]<='9'?1:0;
        for(int i=2;i<opt.size();i++)
        {
            char cur = s[i-1],pre = s[i-2];
            if(isvalid(cur)&&isvalid(pre,cur))
                opt[i] = opt[i-1]+opt[i-2];
            else if(!isvalid(cur)&&isvalid(pre,cur))
                opt[i] = opt[i-2];
            else if(isvalid(cur)&&!isvalid(pre,cur))
                opt[i] = opt[i-1];
            else 
                return 0;
        }
        return opt[s.length()];
    }
    
    bool isvalid(char c)
    {
        return c>='1'&&c<='9';   
    }
    bool isvalid(char pre,char cur)
    {
        return pre=='1'||(pre=='2'&&cur>='0'&&cur<='6');
    }
};
