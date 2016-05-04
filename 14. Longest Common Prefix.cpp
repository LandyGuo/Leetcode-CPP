/*
14. Longest Common Prefix   
Difficulty: Easy
Write a function to find the longest common prefix string amongst an array of strings.
*/
//2nd pass
/*思路：
1）最长前缀长度不可能超过strs里面最小字符串的长度;
2）每当确定当前字符要不要添加进来的时候，需要将所有字符串当前位置的字符全部比较一遍
*/
#define min(x,y)  ((x<=y)?(x):(y))
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        int min_len = INT_MAX;
        for(string const& s:strs)
            min_len = min(s.length(),min_len);
        string ret;
        for(int i=0;i<min_len;i++)
        {
            bool add = true;
            for(int j=1;j<strs.size();j++)
            {
                if(strs[j][i]!=strs[j-1][i])
                {
                    add = false;
                    break;
                }
            }
            if(add)
                ret +=strs[0][i];
            else
                break;
        }
        return ret;
    }
};
